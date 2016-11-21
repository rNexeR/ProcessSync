#ifndef MYSEMAPHORE_H
#define MYSEMAPHORE_H

#include "SemaphoreInterface.h"

class MySemaphore : public SemaphoreInterface
{
    public:
        MySemaphore(int initial);
        virtual ~MySemaphore();
        virtual void wait();
        virtual void signal();
    protected:
    private:
        int value;
};

#endif // MYSEMAPHORE_H
