#include<stdio.h>
#include<stdlib.h>

// prototypes
int confuse1(int[], int a, int b);
void confuse2(int e, int f, int y[], int[]);

int main(void){
int v[] = { 1, 0, -1, 3, 4 }, u[] = { 3, 4, 0, 2, 1 }, w[5];
int a = 3, b = -2, c = 2, d = 5, temp[2], i, n;

FILE *in_ptr;

in_ptr = fopen("data.txt", "r");
printf("Before confuse1 \n a = %d \n b = %d\n", a, b);
printf(" v = %d, %d, %d, %d, %d", v[0], v[1], v[2], v[3], v[4]);
a = confuse1(v, b, a);
printf("\nAfter confuse1\n a = %d \n b = %d \n", a, b);
printf(" v = %d, %d, %d, %d, %d\n", v[0], v[1], v[2], v[3], v[4]);

for(i = 0; i<5; i++){
	n = u[i];
	fscanf(in_ptr, "%d", &w[n]);
	printf("w[%d] = %d\t", n, w[n]);
}
	
fclose(in_ptr);

confuse2(c * 2, d%c, u, temp);
printf("\nAfter confuse2,\ntemp[0] = %d, \ntemp[1] = %d\n", temp[0], temp[1]);
//system("pause");
return 0;
} 
//end main

int confuse1(int x[], int a, int b){
int i, t;
printf("\nInside confuse1");

for(i = 0; i < 5; i = i + 1){
	switch(i){
	case 0:
	case 2: b= x[i] + x[i + 1];
		   printf("\n b = %d", b);
	break;
	case 1: t = x[i] / x[i -1];
		   printf("\n t = %d", t);
	break;
	case 3:
	case 4:
	case 5: x[i] = 2 * x[i] + a;
		   printf("\n x[i] = %d", x[i]);
	}
}
return(b);
} 
//end confuse1

void confuse2(int e, int f, int y[], int store[]){
	store[0] = y[e] / 3;
	store[1] = e + y[f];
}
