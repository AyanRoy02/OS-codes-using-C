#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(){
	
	pid_t p;
	p=fork();
	
	if (p==0){
		p=fork();
		if (p==0){
			printf("I am Grandchild\n");	
		}else{
			sleep(5);
			printf("I am Child\n");
		}	
	}else{
		sleep(10);
		printf("I am Parent\n");
			
	}
    
    return 0;

}
