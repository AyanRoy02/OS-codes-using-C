#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
/*
This program provides a possible solution using mutex and semaphore.
use 5 Farmers and 5 ShopOwners to demonstrate the solution.
*/
#define MaxCrops 5 // Maximum crops a Farmer can produce or a Shpoowner can take
#define warehouseSize 5 // Size of the warehouse
sem_t empty;
sem_t full;
int in = 0;
int out = 0;
char crops[warehouseSize]={'R','W','P','S','M'}; //indicating room for different crops
char warehouse[warehouseSize]={'N','N','N','N','N'}; //initially all the room is empty
pthread_mutex_t mutex;

int f[5]={0,0,0,0,0};
int s[5]={0,0,0,0,0};

void *Farmer(int *far)
{	
	int num=*far -1 ;
	int i=0;
	while (1){
		sem_wait(&empty);
		pthread_mutex_lock(&mutex);
		if(warehouse[i]=='N'){
			printf("Farmer: %d inserts crops %c at %d\n",*far,crops[i],i);
			warehouse[i]=crops[i];
			pthread_mutex_unlock(&mutex);
			f[num]++;
			sleep(1);
			sem_post(&full);
		}else{
			pthread_mutex_unlock(&mutex);
			sem_post(&empty);
			//sleep(1);
			}
		i=(i+1)%warehouseSize;
		sleep(1);
		if (f[num]==5){
			printf("farmer%d:",*far);
			for(int j;j<5;j++){
				printf("%c",warehouse[j]);
				}
			printf("\n");
			break;
		}
		
	}
/*
1.Farmer harvest crops and put them in particular room. For example, room 0 for
Rice(R).
2.use mutex and semaphore for critical section.
3.print which farmer is keeping which crops in which room inside the critical section.
4.print the whole warehouse buffer outside of the critical section
*/
}
void *ShopOwner(int *sho)
{
	int num=*sho - 1;
	int i=0;
	while(1){
		sem_wait(&full);
		pthread_mutex_lock(&mutex);
		if(warehouse[i]!='N'){
			printf("ShopOwner: %d removes crops %c from %d\n",*sho,warehouse[i],i);
			warehouse[i]='N';
			pthread_mutex_unlock(&mutex);
			s[num]++;
			sleep(1);
			sem_post(&empty);
			
		}else{
			pthread_mutex_unlock(&mutex);
			sem_post(&full);
			//sleep(1);
			}
		i=(i+1)%warehouseSize;
		if (s[num]==5){
			
			printf("ShopOwner%d:",*sho);
			for(int j;j<5;j++){
				printf("%c",warehouse[j]);
				}
			printf("\n");
			break;
		}
		
	}
/*
1.Shop owner takes crops and makes that particular room empty.
2.use mutex and semaphore for critical section.
3.print which shop owner is taking which crops from which room inside the critical
section.
4.print the whole warehouse buffer outside of the critical section
*/
}

int main()
{
/*initializing thread,mutex,semaphore
*/
pthread_t Far[5],Sho[5];
pthread_mutex_init(&mutex, NULL);
sem_init(&empty,0,warehouseSize);//when the warehouse is full thread will wait
sem_init(&full,0,0);//when the warehouse is empty thread will wait
int a[5] = {1,2,3,4,5}; //Just used for numbering the Farmer and ShopOwner
/*create 5 thread for Farmer 5 thread for ShopOwner
-------------------------------------------------
-------------------------------------------------
*/
for(int i=0;i<5;i++){
	pthread_create(&Far[i],NULL,(void *)Farmer,&a[i]);
	pthread_create(&Sho[i],NULL,(void *)ShopOwner,&a[i]);
	}
	
for(int i=0;i<5;i++){
	pthread_join(Far[i],NULL);
	pthread_join(Sho[i],NULL);
	}
	


// Closing or destroying mutex and semaphore
pthread_mutex_destroy(&mutex);
sem_destroy(&empty);
sem_destroy(&full);

return 0;
}
