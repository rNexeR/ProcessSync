#include "ReadersAndWriters.h"

ReadersAndWriters::ReadersAndWriters()
{
    //ctor
    rw_mutex = new PosixSemaphore(1);
    mutex = new PosixSemaphore(1);
    read_count = 0;
}

ReadersAndWriters::~ReadersAndWriters()
{
    //dtor
    delete rw_mutex;
    delete mutex;
}

void ReadersAndWriters::reader(){
    do{
        mutex->wait();
        read_count++;
        if(read_count == 1)
            rw_mutex->wait();
        mutex->signal();

        cout<<"Reader is acting"<<endl;

        mutex->wait();
        read_count--;
        if(read_count == 0)
            rw_mutex->signal();
        mutex->signal();
        sleep(2);
    }while(true);
}

void ReadersAndWriters::writer(){
    do{
        rw_mutex->wait();

        cout<<"Writer is acting"<<endl;

        rw_mutex->signal();
        sleep(3);
    }while(true);
}

void ReadersAndWriters::execute(){
    thread read(&ReadersAndWriters::reader, this);
    thread write(&ReadersAndWriters::writer, this);
    while(true);
}
