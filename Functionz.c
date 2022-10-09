#include <stdio.h>
#include <stdlib.h>

void fun1(void);
double fun2(void);
//Include the 2nd dimensions of an array
void fun3(double []);

int j=1;

int main(void){
	double nums[2];
	int i;

	fun1();

	for(i=0;i<2;i=i+1){
		nums[i]=fun2();
	}

	fun3(nums);
	printf("In the main %lf %lf",nums[0],nums[1]);
	
	j=j+1;
	printf("\nj is %d\n",j);
	return 0;
}

void fun1(void){
	printf("This program will add two numbers.\n");
	j=j+1;
	printf("\nj is %d\n",j);
}

double fun2(void){
	double num;
	printf("Give me a number. ");
	scanf("%lf",&num);
	j=j+1;
	printf("\nj is %d\n",j);
	return(num);
}

void fun3(double nums[2]){
	double summie;
	summie=nums[0]+nums[1];
	printf("The sum of %lf and %lf is %lf\n",nums[0],nums[1],summie);
	nums[0]=nums[0]+2.1;
	nums[1]=nums[1]+1.2;
	printf("In the function %lf %lf\n",nums[0],nums[1]);
	j=j+1;
	printf("\nj is %d\n",j);
}
