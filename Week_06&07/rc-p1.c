#include <pthread.h>   
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#define MAX 50
#define BUFFER_LEN 24
#define MAX_COUNT 15
#define NUMTHREAD 3    

void *consumer(int *id);
void *producer(int *id);

char buffer[BUFFER_LEN];
char source[BUFFER_LEN];
int read_count = 0, write_count = 0;
int buffer_len;
pthread_mutex_t count_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t nonEmpty  = PTHREAD_COND_INITIALIZER;
pthread_cond_t full  = PTHREAD_COND_INITIALIZER;
int thread_id[NUMTHREAD]  = {0,1,2};
int i = 0, j = 0;

void *consumer(int *id)
{
  	pthread_mutex_lock(&count_mutex);
  	while(j < MAX)
    	{
      		pthread_cond_wait(&nonEmpty, &count_mutex);
      		printf("Consumer: Consumed item :%c\n", buffer[read_count]);
      		read_count = (read_count+1) % BUFFER_LEN;
      		fflush(stdout);
      		j++;
      		if (j < (MAX - 2))     	
			if (rand()%100 < 30)
	  			sleep(rand()%3);

    	}
  	pthread_mutex_unlock(&count_mutex);
}

void *producer(int *id)
{

  	while (i < MAX)
    	{
      		pthread_mutex_lock(&count_mutex);
      		buffer[write_count] = source[write_count % buffer_len];
      		printf("Producer:produced item :%c\n",buffer[write_count]);
      		fflush(stdout);
      		write_count = (write_count + 1) % BUFFER_LEN;
      		i++;
      		pthread_cond_signal(&nonEmpty);
      		pthread_mutex_unlock(&count_mutex);
      		if (i < (MAX - 2))    
			if (rand()%100 >= 30)
	  			sleep(rand()%3);
    	}
}

int main()
{
  	int i;
  	pthread_t thread[NUMTHREAD];
  	strcpy(source,"0123456789");
  	buffer_len = strlen(source);
  	pthread_create(&thread[0], NULL, (void *)consumer, &thread_id[0]);
 	pthread_create(&thread[1], NULL, (void *)producer, &thread_id[1]);
  	pthread_create(&thread[2], NULL, (void *)producer, &thread_id[2]);
  
  	for(i=0; i< NUMTHREAD ; i++)
    	{
      		pthread_join(thread[i], NULL);
    	}
}


