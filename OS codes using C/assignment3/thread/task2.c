#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
void *funcThread(void *arg);
int main(){
	pthread_t t1,t2,t3,t4,t5;
	pthread_create(&t1,NULL,funcThread,"0");
	pthread_join(t1,NULL);
	
	pthread_create(&t2,NULL,funcThread,"1");
	pthread_join(t2,NULL);
	
	pthread_create(&t3,NULL,funcThread,"2");
	pthread_join(t3,NULL);
	
	pthread_create(&t4,NULL,funcThread,"3");
	pthread_join(t4,NULL);
	
	pthread_create(&t5,NULL,funcThread,"4");
	pthread_join(t5,NULL);
	
	return 0;
}



void *funcThread(void *arg){
	int num,end_num;
	num=(char *)arg - "0";
	num/=2;
	num+=1;
	end_num=(num*5)+1;
	num=end_num-5;
	
	for(;num<end_num;num++){
		printf("Thread %s prints %d\n",(char *)arg,num);
		sleep(1);
	}
}
