#include "Philosophers.h"

Philosophers::Philosophers()
{
    cant = 5;
    chopsticks = new SemaphoreInterface*[cant];
    for(int i = 0; i < cant; i++){
        chopsticks[i] = new PosixSemaphore(1);
    }
}

Philosophers::~Philosophers()
{
    //dtor
}

void Philosophers::philosopher(int n){
    //cout<<n<<endl;
    do{
        chopsticks[n]->wait();
        chopsticks[(n+1)%5]->wait();

        cout<<"Filosopher number "<<n<<" is eating"<<endl;

        chopsticks[n]->signal();
        chopsticks[(n+1)%5]->signal();
        cout<<"Filosopher number "<<n<<" is thinking"<<endl;
        sleep(100);
    }while(true);
}

void Philosophers::execute(){
    thread hilos[cant];
    for(int i = 0; i < cant; i++){
        hilos[i] = thread(&Philosophers::philosopher, this, i);
    }
    while(true);
}
