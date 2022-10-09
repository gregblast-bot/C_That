#include <stdio.h>

int main(void){
//begin main
int a=5, b=3, c=4, d=2, e, f;
float alpha=3, beta=2, gamma=4, delta, epsilon;
delta = beta*a/d;
e = a/c;
epsilon = (gamma/alpha)*(a/d);
beta = (2.0/3.0)*beta;
f = b%d;

printf("\ndelta = %.3f\ne = %08d \nepsilon = %+6.2f",delta,e,epsilon);
printf("\nbeta = %f\nf = %d \n",beta,f);
return(0);
}//end program
