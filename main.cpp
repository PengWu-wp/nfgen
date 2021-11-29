#include <iostream>
#include <thread>

#include "Worker.h"
#include "Timer.h"

using namespace std;

u_int _NUM_THREADS = 3;
u_short _NF_PORT = 9995;



int main(int argc, char *argv[]) {

    u_int num_threads_ = _NUM_THREADS;
    u_short port_ = _NF_PORT;
    u_short netflow_version_ = 9;
    int count_ = 0;
    char *dest_;

    mutex mtx_;
    atomic_ulong requests_(0);

    // handle options
    if (argc < 2) {
        cout << "Usage: " << argv[0] << " [-t num_threads (" << _NUM_THREADS << ")] [-p port (" << _NF_PORT
             << ")] [-v netflow_version (9)] [-c count (0)] target_ip" << endl;
        return -1;
    }

    int opt;
    char *endptr;

    while ((opt = getopt(argc, argv, "t:p:hv:c:")) != EOF) {
        switch (opt) {
            case 't':
                num_threads_ = (u_int) strtol(optarg, &endptr, 0);
                if (num_threads_ == 0) {
                    cout << "Invalid num_threads: " << endptr << endl;
                    return EXIT_FAILURE;
                }
                break;
            case 'p':
                port_ = (u_int) strtol(optarg, &endptr, 0);
                if (port_ == 0) {
                    cout << "Invalid port: " << endptr << endl;
                    return EXIT_FAILURE;
                }
                break;
            case 'h':
                cout << "Usage: " << argv[0] << " [-t num_threads (" << _NUM_THREADS << ")] [-p port (" << _NF_PORT
                     << ")] [-v netflow_version (9)] target_ip" << endl;
                return EXIT_SUCCESS;
            case 'v':
                netflow_version_ = (u_int) strtol(optarg, &endptr, 0);
                break;
            case 'c':
                count_ = (u_int) strtol(optarg, &endptr, 0);
                break;
            default:
                cout << "Usage: " << argv[0] << " [-t num_threads (" << _NUM_THREADS << ")] [-p port (" << _NF_PORT
                     << ")] [-v netflow_version (9)] [-c count (0)] target_ip" << endl;
                return EXIT_FAILURE;
        }
    }

    if (!argv[optind]) {
        cout << "Error: destination missing" << endl;
        return EXIT_FAILURE;
    } else {
        dest_ = argv[optind];
    }

    if (netflow_version_ != 5 && netflow_version_ != 9) {
        cout << "Error: netflow_version(" << netflow_version_ << ") is wrong." << endl;
        return EXIT_FAILURE;
    }

    // create worker threads
    thread *thWorker;
    thWorker = new thread[num_threads_];

    for (u_int i = 0; i < num_threads_; i++) {
        thWorker[i] = thread(&Worker::Run, Worker(dest_, port_, &mtx_, &requests_, netflow_version_,count_));
    }

    // timer thread
    cout << "Timestamp, Requests/s" << endl;
    thread th_timer(&Timer::Start, Timer(&requests_));

    // run workers
    for (u_int i = 0; i < num_threads_; i++) {
        thWorker[i].join();
    }

    return EXIT_SUCCESS;
}
