#include <stdio.h>


int main(){
	char *ptr;
	char *rev;
	char word[1000];
	printf("Enter your word:\n");
	scanf("%s",&word);
	rev = word;
	
	while (rev[0] != '\0' ){
		rev++;
	}
	rev--;
	for (ptr = word;ptr<=rev;){
		if(*ptr==*rev){
			rev--;
			ptr++;
		}else{
			break;
		}
			
	}
	if (ptr<=rev){
		printf("Word is not Palindrome\n");
	}else{
		printf("Word is a Palindrome\n");
	}
	
}
