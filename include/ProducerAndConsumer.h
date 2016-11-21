#ifndef PRODUCERANDCONSUMER_H
#define PRODUCERANDCONSUMER_H

#include <thread>
#include "PosixSemaphore.h"
#include "MySemaphore.h"
#include <unistd.h>


class ProducerAndConsumer
{
    public:
        ProducerAndConsumer();
        virtual ~ProducerAndConsumer();
        void execute();
    protected:
        int max_cant = 5;
        SemaphoreInterface *mutex;
        SemaphoreInterface *full;
        SemaphoreInterface *_empty;
    private:
        void consumer();
        void producer();
};

#endif // PRODUCERANDCONSUMER_H
