#include <stdio.h>
#include <stdlib.h>
 
int main()
{
    int a;
    int b;
    char op[10];
    int res;
    printf("Enter two numbers:\n");
    scanf("%d %d",&a,&b);
    printf("Enter an operator:\n");
    scanf("%s",&op);
    if (a>b){
        res=a-b;
        printf("%d\n",res);
    }else if(a<b){
        res=a+b;
        printf("%d\n",res);
    }else{
        res=a*b;
        printf("%d\n",res);
    }
    return 0;
}
