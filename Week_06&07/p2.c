#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

int in=0, out=0;
int buffer[10000];

int count = 0;				
int mutex = 1;

void wait(int *semaphore)
{
	while(*semaphore <= 0) ;
	*semaphore -= 1;
}

void signal(int *semaphore)
{
	*semaphore += 1;
}

void *producer()
{
    	int next = 0;
    	while(1) 
    	{
        	wait(&mutex);								
			next++;						
			printf("Producer : Produced item %d\n", next);
			buffer[in++] = next;
			signal(&count);						
        	signal(&mutex);							
        	sleep(2);
    	}
}

void *consumer()
{
    	int next;
    	while(1) 
    	{   	
			wait(&count);							
			wait(&mutex);									
			next = buffer[out++];
			printf("Consumer : Consumed item %d\n", next);
			signal(&mutex);						
        	sleep(2);
    }
}

int main()
{
    	pthread_t p_thread, c_thread;
    	pthread_create(&p_thread, NULL, producer, NULL);
    	pthread_create(&c_thread, NULL, consumer, NULL);
		pthread_join(p_thread, NULL);
    	pthread_join(c_thread, NULL);
}
