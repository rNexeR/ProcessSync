#ifndef READERSANDWRITERS_H
#define READERSANDWRITERS_H

#include <thread>
#include "PosixSemaphore.h"
#include <unistd.h>


class ReadersAndWriters
{
    public:
        ReadersAndWriters();
        virtual ~ReadersAndWriters();
        void execute();
    protected:
        SemaphoreInterface *rw_mutex;
        SemaphoreInterface *mutex;
        int read_count;
    private:
        void reader();
        void writer();
};

#endif // READERSANDWRITERS_H
