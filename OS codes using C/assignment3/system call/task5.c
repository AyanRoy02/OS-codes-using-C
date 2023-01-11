#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(){

    pid_t a;
    a= fork();
    if (a==0){
    	printf("Child process ID:%d\n",getpid());
    	
    	for(int i=0;i<3;i++){
    		if (fork()==0){
    			printf("Grandfather process ID:%d\n",getpid());
    			exit(0);
    		}
    	}
    		
    	
	    
    }else{
    	printf("Parent process ID:%d\n",getpid());
    return 0;
    }
}
