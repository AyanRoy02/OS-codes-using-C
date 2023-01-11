#include <pthread.h>
#include <stdio.h>
#include <string.h>
#define MAX 10 //producers and consumers can produce and consume upto MAX
#define BUFLEN 6
#define NUMTHREAD 2 /* number of threads */
void * consumer(int *id);
void * producer(int *id);
char buffer[BUFLEN];

char source[BUFLEN]; //from this array producer will store it's production into buffer
int pCount = 0;
int cCount = 0;
int buflen;
//initializing pthread mutex and condition variables
pthread_mutex_t count_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t nonEmpty = PTHREAD_COND_INITIALIZER;
pthread_cond_t full = PTHREAD_COND_INITIALIZER;
int thread_id[NUMTHREAD] = {0,1};
int i = 0;
int j = 0;
int counter = 0;
int main()
{
int i;
/* define the type to be pthread */
pthread_t thread[NUMTHREAD];
pthread_mutex_init(&count_mutex,NULL);
strcpy(source,"abcdef");
buflen = strlen(source);
/* create 2 threads*/
/* create one consumer and one producer */
/* define the properties of multi threads for both threads */
//Write Code Here
pthread_create(&thread[0],NULL,(void *)consumer,&thread_id[0]);
pthread_create(&thread[1],NULL,(void *)producer,&thread_id[1]);
	
for(int i=0;i<2;i++){
	pthread_join(thread[i],NULL);
	}
	
pthread_mutex_destroy(&count_mutex);
return 0;
}

void * producer(int *id)
{
/*
1. Producer stores the values in the buffer (Here copies values from source[] to buffer[]).
2. Use mutex and thread communication (wait(), sleep() etc.) for the critical section.
3. Print which producer is storing which values using which thread inside the critical
section.
4. Producer can produce up to MAX
*/
//Write code here
while(1){
	if(i==MAX || j==MAX){
		break;
	}
	
	
	while(counter==buflen){
		sleep(1);
	}
	pthread_mutex_lock(&count_mutex);
	buffer[counter]=source[pCount];
	//printf("%d produced  by thread 2\n",pCount);
	printf("%d produced %c by thread 0\n",i,buffer[counter]);
	pCount=(pCount+1)%buflen;
	i++;
	counter++;
	sleep(1);
	pthread_mutex_unlock(&count_mutex);
		
	}
}

void * consumer(int *id)
{
/*
1. Consumer takes out the value from the buffer and makes it empty.
2. Use mutex and thread communication (wait(), sleep() etc.) for critical section
3. Print which consumer is taking which values using which thread inside the critical
section.
4. Consumer can consume up to MAX
*/
//Write code here
while(1){

	if(i==MAX || j==MAX){
		break;
	}
	
	while (counter==0){
		sleep(1);
	}
	pthread_mutex_lock(&count_mutex);
	//printf("%d consumed  by thread 1\n",cCount);
	printf("%d consumed %c by thread 1\n",j,buffer[cCount]);
	cCount=(cCount+1)%buflen;
	j++;
	counter--;
	sleep(1);
	pthread_mutex_unlock(&count_mutex);
		
	}
}
