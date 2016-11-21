#include <iostream>
#include "ProducerAndConsumer.h"
#include "ReadersAndWriters.h"
#include "Philosophers.h"


using namespace std;

int main()
{
    ProducerAndConsumer pac;
    ReadersAndWriters raw;
    Philosophers p;

    //p.execute();
    //raw.execute();
    pac.execute();


    return 0;
}
