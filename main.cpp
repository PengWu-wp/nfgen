#include <iostream>
#include <thread>

#include "Worker.h"
#include "Timer.h"

using namespace std;

u_int _NUM_THREADS = 3;
u_short _NF_PORT = 9995;

static void usage(char *name) {
    printf("usage %s [options] <target_ip>\n"
           "\n"
           "Options:\n"
           "-h                 this text you see right here\n"
           "-t <num_threads>   Number of threads to generate the traffic (default 3)\n"
           "-p <port>          Target port number (default 9995)\n"
           "-c <count>         My way to keep frequency...\n"
           "-v <version>       Packet version  (default 9, netflow v9)\n"
           "                   5 for netflow v5\n"
           "                   6 for netflow v5(small)\n"
           "                   8 for netflow v9(small)\n"
           "                   9 for netflow v9\n"
           "                   10 for IPFIX\n"
            , name);
} // End of usage


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
        usage(argv[0]);
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
                usage(argv[0]);
                return EXIT_SUCCESS;
            case 'v':
                netflow_version_ = (u_int) strtol(optarg, &endptr, 0);
                break;
            case 'c':
                count_ = (u_int) strtol(optarg, &endptr, 0);
                break;
            default:
                usage(argv[0]);
                return EXIT_FAILURE;
        }
    }

    if (!argv[optind]) {
        cout << "Error: destination missing" << endl;
        return EXIT_FAILURE;
    } else {
        dest_ = argv[optind];
    }

    if (netflow_version_ != 5 && netflow_version_ != 9 && netflow_version_ != 10 && netflow_version_ != 6 &&
        netflow_version_ != 8) {
        cout << "Error: netflow_version(" << netflow_version_ << ") is wrong." << endl;
        return EXIT_FAILURE;
    }

    // create worker threads
    thread *thWorker;
    thWorker = new thread[num_threads_];

    for (u_int i = 0; i < num_threads_; i++) {
        thWorker[i] = thread(&Worker::Run, Worker(dest_, port_, &mtx_, &requests_, netflow_version_, count_));
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
