#include <stdio.h>
#include <stdlib.h>

int main(void){

	char user;
	
	printf("Give me a letter!");
	scanf(" %c", &user);
	user = tolower(user);
	
	switch(user){
	case 'a':
	case 'e':
	case 'i':
	case 'o':
	case 'u':
	printf("You entered a vowel");
	break;
	default:
	printf("You didnt enter shit.")
	}
	
	return 0;
}

