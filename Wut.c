//Gregory Wagonblast, Team 2
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void){

//Declare variables
char fl;
float x,power,times,sub;
int y,choice;

//Print demands and scan for options
printf("Please enter the first letter of your name. ");
scanf(" %c",&fl);
printf("Please enter a value (x), this value can take decimals. ");
scanf("%f",&x);
printf("Please enter an integer (y). ");
scanf("%d",&y);

//Loop indefinetily
while(choice!=1 && choice!=2 && choice!=1){
printf("Please select (1) to raise x to the power of y, (2)to multiply x by y, or (3) to subtract x-y. ");
scanf("%d",&choice);
}

//Switch statement to sort through options
switch(choice){
	
case 1:{
 power = pow(x,y);
 printf("x to the power of y is %f.",power);
 printf(" %c",fl);
}break;

case 2:{
 times = x*y;
 printf("x*y is %f.",times);
 printf(" %c",fl);
}break;

case 3:{
 sub = x-y;
 printf("x-y is %f.",sub);
 printf(" %c",fl);
}break;

default:{
 printf("You done goofed.");
 printf(" %c",fl);
}
}

return 0;
}
