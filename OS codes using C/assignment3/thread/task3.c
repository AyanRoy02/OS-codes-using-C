#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>

void *func_thread(char *n);
void *t_ret1,*t_ret2,*t_ret3;
void *func_thread(char *n){
	int res=0;
	int end=strlen(n);
	
	for(int i=0;i<end;i++){
		int temp=n[i];
		res+=temp;
	}
	
	return (void *)res;
}

int main(){
	char num1[100],num2[1000],num3[100];
	printf("Enter your name: \n");
	scanf("%s",num1);
	printf("Enter your name: \n");
	scanf("%s",num2);
	printf("Enter your name: \n");
	scanf("%s",num3);
	pthread_t t1,t2,t3;
	pthread_create(&t1,NULL,(void *)func_thread,(char *)num1);
	pthread_create(&t2,NULL,(void *)func_thread,(char *)num2);
	pthread_create(&t3,NULL,(void *)func_thread,(char *)num3);
	pthread_join(t1,(void **)&t_ret1);
	pthread_join(t2,(void **)&t_ret2);
	pthread_join(t3,(void **)&t_ret3);
	
	if(t_ret1==t_ret2 && t_ret1==t_ret3 && t_ret2==t_ret3){
        	printf("Youreka\n");
        }
   
	else if (t_ret1!=t_ret2 && t_ret1!=t_ret3 && t_ret2!=t_ret3){
        	printf("Hasta la vista\n");
   	}else{
   		printf("Miracle\n");
   	}
	
	return 0;
}







