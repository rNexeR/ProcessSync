#ifndef SEMAPHOREINTERFACE_H
#define SEMAPHOREINTERFACE_H

#include <iostream>

using namespace std;


class SemaphoreInterface
{
    public:
        SemaphoreInterface(string type);
        virtual ~SemaphoreInterface();
        virtual void wait() = 0;
        virtual void signal() = 0;

        string type;
    protected:
    private:
};

#endif // SEMAPHOREINTERFACE_H
