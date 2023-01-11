#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(){

    pid_t a,b,c;
    int check;
    a =fork();
    b =fork();
    c =fork();
    if (a==0){
	check=getpid();
	if (check%2==1){
		fork();
	}
    }
    else if (b==0){
	check=getpid();
	if (check%2==1){
		fork();
	}    
    }
    else if (c==0){
	check=getpid();
	if (check%2==1){
		fork();
		
	}    
    }
    printf("ID of processes: %d\n",getpid());
    return 0;

}
