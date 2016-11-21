#include "PosixSemaphore.h"

PosixSemaphore::PosixSemaphore() : SemaphoreInterface("PosixSemaphore")
{
    sem_init(&(this->mutex), 0, 1);
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
