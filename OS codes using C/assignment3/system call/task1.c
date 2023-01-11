#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    char a[1000];
    int i=0;
    char res[1000];
    FILE *fptr;
	fptr= fopen("text.txt","w+");
    while (i==0){
        printf("Enter a string: \n");
        scanf("%[^\n]%*c", &a);
        
        if (strcmp(a, "-1") == 0){
        	i=-1;
        }else{
        	strcat(res,a);
        	strcat(res,"\n");
        	printf("%s",res);
        }
    }
    if (fptr==NULL){
        	exit(1);
        }
    
    fprintf(fptr,"%s",res);
    fclose(fptr);

    return 0;

}
