#ifndef POSIXSEMAPHORE_H
#define POSIXSEMAPHORE_H

#include <SemaphoreInterface.h>
#include <semaphore.h>


class PosixSemaphore : public SemaphoreInterface
{
    public:
        PosixSemaphore();
        virtual ~PosixSemaphore();
        void wait();
        void signal();
    protected:
    private:
        sem_t mutex;
};

#endif // POSIXSEMAPHORE_H
