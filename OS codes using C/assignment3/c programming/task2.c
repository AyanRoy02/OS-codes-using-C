#include <stdio.h>
#include <stdlib.h>

int perfect_number(int x, int y){

    int i;
    int sum;

    for (;x<=y;x++){
        sum = 0;
        for (i=1;i<x;i++){
            if(x%i==0){
                sum+=i;
            }
        }
        if (sum==x){
            printf("%d\n",x);
        }
    }

}

int main(){

    int a;
    int b;

    printf("Enter First number: \n");
    scanf("%d", &a);

    printf("Enter Second number: \n");
    scanf("%d", &b);

    perfect_number(a,b);

    return 0;

}