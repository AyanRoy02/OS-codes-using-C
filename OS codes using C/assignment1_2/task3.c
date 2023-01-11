#include <stdio.h>
#include <string.h>
#include <ctype.h>
 
 
int main()
{
 
    char a[30];
    int size;
    int res[4]={0,0,0,0};
    int sum=0;
    printf("Enter a password:\n");
    scanf("%s",&a);
    size =strlen(a);
    for (int i=0;i<size;i++){
        if (isupper(a[i])){
 
            //printf ("It is UPPERCASE character\n");
            res[0]=1;
 
        }else if (islower(a[i])){
            //printf ("It is lowercase character\n");
            res[1]=1;
 
        }else if (isdigit(a[i])){
            //printf("It is a digit\n");
            res[2]=1;
        }else if (a[i]=='_' || a[i]=='$' || a[i]=='#' || a[i]=='@'){
            //printf("It is a special character\n");
            res[3]=1;
 
        }
 
        
    }
    if (res[0]==0){
        printf("Uppercase character missing,");
    }
    if (res[1]==0){
        printf("Lowercase character missing,");
    }
    if (res[2]==0){
        printf("Digit missing,");
        }   
    if (res[3]==0){
        printf("special character missing");
        }
    for(int j = 0; j < 4; j++)
          sum = sum + res[j];
    if (sum==4){
        printf("OK\n");
    }
 
 
    return 0;
}
