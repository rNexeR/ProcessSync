#include "MySemaphore.h"

MySemaphore::MySemaphore(int initial) : SemaphoreInterface("My Semaphore")
{
    //ctor
    value = initial;
}

MySemaphore::~MySemaphore()
{
    //dtor
}

void MySemaphore::wait()
{
    while(value <= 0 );
    value--;
}

void MySemaphore::signal()
{
    value++;
}
