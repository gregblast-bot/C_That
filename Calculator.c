#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void){

int choice, go=1;
double num1, num2, result;

while( go == 1){
printf("Give me a number ");
scanf("%lf", &num1);
printf("Give me a second number ");
scanf("%lf", &num2);
printf("Would you like to add (1) subtract (2) multiply (3) divide (4) ");
scanf("%d", &choice);

if(choice == 1){
	result = num1 + num2;
}
else if(choice == 2){
	result = num1 - num2;
}
else if(choice == 3){
	result = num1 * num2;
}
else{
	result = num1 / num2;
}

printf("Your result is %lf ", result);

printf("Go again?, yes (1), no (2)");
scanf("%d", &go);

}

return 0;

}
