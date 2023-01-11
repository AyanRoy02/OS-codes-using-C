#include <sys/types.h>
#include <regex.h>
#include <stdio.h>

 
 
 
 
int main()
{
    char email[50];
    regex_t reegex;
    int value;
    int res;
    printf("Enter your E-Mail:\n");
    scanf("%s",&email);
    value =regcomp( &reegex, "^[a-zA-z].*@sheba.xyz$", 0);
    res=regexec(&reegex,email,0,NULL,0);
 
    if (res==0){
        printf("Email address is okay\n");
 
    }else{
        printf("Email address is outdated\n");
    }
 
    return 0;
}
