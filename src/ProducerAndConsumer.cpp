#include "ProducerAndConsumer.h"

ProducerAndConsumer::ProducerAndConsumer()
{
    //ctor
    mutex = new MySemaphore(1);
    full = new MySemaphore(0);
    _empty = new MySemaphore(max_cant);
}

ProducerAndConsumer::~ProducerAndConsumer()
{
    //dtor
    delete mutex;
    delete full;
    delete _empty;
}

void ProducerAndConsumer::consumer(){
    do{
        sleep(3);
        full->wait();
        mutex->wait();

        cout<<"Romoving product"<<endl;

        mutex->signal();
        _empty->signal();

    }while(true);
}

void ProducerAndConsumer::producer(){
    do{
        _empty->wait();
        mutex->wait();

        cout<<"Adding new product"<<endl;

        mutex->signal();
        full->signal();
        sleep(2);

    }while(true);
}

void ProducerAndConsumer::execute(){
    thread prod(&ProducerAndConsumer::producer, this);
    thread cons(&ProducerAndConsumer::consumer, this);

    while(true){

    }

    prod.join();
    cons.join();
}
