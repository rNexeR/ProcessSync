#include "PosixSemaphore.h"

PosixSemaphore::PosixSemaphore(int initial) : SemaphoreInterface("PosixSemaphore")
{
    sem_init(&(this->mutex), 0, initial);
}

PosixSemaphore::~PosixSemaphore()
{
    sem_close(&(this->mutex));
}

void PosixSemaphore::wait(){
    sem_wait(&(this->mutex));
}

void PosixSemaphore::signal(){
    sem_post(&(this->mutex));
}
