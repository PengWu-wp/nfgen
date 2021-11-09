//
// Created by Kosho Owa on 2019-07-25.
//

#ifndef NFGEN_WORKER_H
#define NFGEN_WORKER_H

#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <mutex>

#ifdef __linux__
#include <atomic>
#endif




using namespace std;

class Worker {
public:
    Worker();


    Worker(char *dest, u_short port, mutex *mtx, atomic_ulong *requests, u_short netflow_version);

    void Run();

private:
    char *dest_;
    u_short port_;
    u_short netflow_version_;
    std::mutex *mtx_;
    std::atomic_ulong *requests_;

    void safe_cout(const string &msg);
};

#endif //NFGEN_WORKER_H
