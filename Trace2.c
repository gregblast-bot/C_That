//preprocessor and prototypes
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int mathFun(int, double, double []);

int main(void){
//begin main
int a = 5;
double b = 4.2;
double c[5];

printf("Before function:");
printf("\na = %d\tb = %.2lf",a,b);
a = mathFun(a,b,c);printf("\nAfter function:");
printf("\na = %d\tb = %.2lf",a,b);

b = mathFun(a,b,c);

printf("\nAfter function, again:");
printf("\na = %d\tb = %.2lf",a,b);

for(int j=0; j<5;j++){
printf("\nc[%d] = %.2lf",j,c[j]);
}
return(0);
}//end program

int mathFun(int x, double y, double z[]){
z[1] = x;
z[2] = y;
z[3] = 1/2*x;
z[4] = pow(x,2);
z[0] = z[1] * z[2] + 3;return(z[4]);
}
