#ifndef POSIXSEMAPHORE_H
#define POSIXSEMAPHORE_H

#include <SemaphoreInterface.h>
#include <semaphore.h>


class PosixSemaphore : public SemaphoreInterface
{
    public:
        PosixSemaphore(int initial);
        virtual ~PosixSemaphore();
        virtual void wait();
        virtual void signal();
    protected:
    private:
        sem_t mutex;
};

#endif // POSIXSEMAPHORE_H
