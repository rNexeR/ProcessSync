#include <iostream>
#include <thread>
#include "PosixSemaphore.h"
#include <unistd.h>

using namespace std;

PosixSemaphore semaphore;

void foo()
{
  while(true){
		semaphore.wait();
		printf("Ping\n");
		sleep(1);
		semaphore.signal();
		usleep(1);
	}
}

void bar()
{
  while(1){
		semaphore.wait();
		printf("\tPong\n");
		sleep(1);
		semaphore.signal();
		usleep(1);
	}
}

int main()
{
  thread first (foo);     // spawn new thread that calls foo()
  thread second (bar);  // spawn new thread that calls bar(0)

  //cout << "main, foo and bar now execute concurrently...\n";

  // synchronize threads:
  first.join();                // pauses until first finishes
  second.join();               // pauses until second finishes

  cout << "foo and bar completed.\n";

  return 0;
}
