#include <stdio.h>
#include <stdlib.h>

void fun1(void); //function prototype
void fun2(int,int,double); //Prototyping in c it only cares about type
double fun3(double,double);

int main(void){
int x=2,y=3;
double i=2.4;
double a=3.1,b=3.1,summie;
fun1();
fun2(x,y,i);
summie=fun3(a,b);
printf("\nAfter the function");
printf("\nx is %d y is %d i is %lf",x,y,i);
printf("\nThe sum of %lf and %lf is %lf",a,b,summie);

return 0;

}

void fun1(void){
	printf("Function Boy.\n");
}

void fun2(int i,int j,double a){
	double y;
	y=i*2;
	i=i+1;
	j=j+1;
	a=a+1;
	printf("In the function\n");
	printf("x is %d j is %d a is %lf",i,j,a);
}

double fun3(double a, double b){
	double summie;
	summie=a+b;
	printf("\nThe sum of %lf and %lf is %lf",a,b,summie);
	return summie;
}
