#ifndef PHILOSOPHERS_H
#define PHILOSOPHERS_H

#include <thread>
#include "PosixSemaphore.h"
#include <unistd.h>


class Philosophers
{
    public:
        Philosophers();
        virtual ~Philosophers();
        void execute();
    protected:
        int cant;
        SemaphoreInterface **chopsticks;
    private:
        void philosopher(int n);
};

#endif // PHILOSOPHERS_H
