#include <stdio.h>
#include <stdlib.h>
int main(void){
	//begin main
	int a=5, b=2,d,j;
	int c[] = {1,2,3,4,5,6};
	int count=0;
	
	printf("Begin here");
	
	while(b-2 < a+8){
		if(b == 5){
			d=b;
			for (j = 0;j<6;j=j+1){
				d=d+3;
				}
				printf("\nd = %d",d);}      
				 
				 else if( c[2] == a){
					 printf("\nb = %d",b);
					 }
					 else if((a%b) == 1){
						 printf("\nyou are an odd duck");
						 }
						 else{printf("\nelse condition");
							 }
							 b=b+3;
							 a=a-1;
							 count = count + 1;
							 }
							 printf("\nloop ran %d times",count);
							 printf("\nend program");
							 return(0);}//End of program
