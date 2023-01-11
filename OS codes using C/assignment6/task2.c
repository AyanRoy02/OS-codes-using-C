#include <stdio.h>
#include <stdlib.h>

int n = 6; // Number of processes
int m = 4; // Number of resources
int alloc[6][4] = { { 0, 1, 0, 3 }, // P0 // Allocation Matrix

{ 2, 0, 0, 3 }, // P1
{ 3, 0, 2, 0 }, // P2
{ 2, 1, 1, 5 }, // P3
{ 0, 0, 2, 2 }, // P4
{1, 2 , 3, 1 } }; //P5

int max[6][4] = { { 6, 4, 3, 4 }, // P0 // MAX Matrix

{ 3, 2, 2, 4 }, // P1
{ 9, 1, 2, 6 }, // P2
{ 2, 2, 2, 8 }, // P3
{ 4, 3, 3, 7 }, // P4
{ 6, 2 , 6, 5 } }; //P5

int avail[4] = { 2, 2, 2, 1 }; //Available resources


int main(){
    int i=0;
    int count=0;
    int unsafe=1;
    while(1){
        int flag=1;
        for(int j=0;j<m;j++){
            int need=0;
            need=max[i][j]-alloc[i][j];
            if (need>avail[j]){
                flag=0;
                break;
            }else{
                flag=1;
            }
            if (j==m-1){
                unsafe=0;
            }

        }
        if(flag==1){
            for(int j=0;j<m;j++){
                avail[j]+=alloc[i][j];
                alloc[i][j]=0;
                max[i][j]=999;
            }
            count++;
            printf("p%d--> ",i);
        }
        i++;
        i=i%n;
        if ((i==0) && (unsafe==1)){
            printf("DEADLOCK AHEAD\n");
            break;
        }else if(i==0){
            unsafe=1;
        }
        
        if(count==n){
            printf("DONE\n");
            break;
        }
    }
    return 0;
}
