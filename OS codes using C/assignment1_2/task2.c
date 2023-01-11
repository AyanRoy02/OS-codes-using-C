
#include <stdio.h>
#include <string.h>

 
 
 
 
int main()
{	

	char og[5000];
	char *token;
	char str1[5000]="";
	
	FILE *fptr;
	fptr= fopen("input.txt","r");
	fscanf(fptr,"%[^\n]",og);
	
	
	token= strtok(og," ");
	
	while(token != NULL ){
		strcat(str1,token);
		strcat(str1," ");
		token= strtok(NULL," ");
	}
	
	FILE *fptr1;
	fptr1= fopen("output.txt","w");
	fprintf(fptr1,"%s",str1);
	
	fclose(fptr1);
	
	fclose(fptr);
	
	return 0;
}
