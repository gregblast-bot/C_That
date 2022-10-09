#include <stdio.h>
#include <stdlib.h>
//Pointers store the address of where a variable is located in memory

int main(void){
	int c=5, *pc=&c;
	
	printf("c=%d address is: %p\n",c,&c);
	printf("pc=%p and the address is: %p",pc,&pc);
	printf("\nIndirect *pc=%d",*pc);
	
	
	
	return 0;
}
