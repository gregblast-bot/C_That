#include <stdio.h>
#include <stdlib.h>

int main(void){
	int x=2,y;
	float a,b;
	a=3.2;
	double c=5.2,d;
	int e[3]={4,2};
	double f[2][2]={{5.1,7.1},{1.2,2.1}};
	char bopdaweasel[10];
	
	printf("Give me an int bro!");
	scanf("%d",&y);
	scanf(" %s",&bopdaweasel);
	printf("bopdaweasel=%s",bopdaweasel);
	printf("Give me two real numbers, NOW BRO.");
	scanf("%f %lf",&b,&d);
	printf("x=%d y=%d a=%+7.2f b=%07.2f c=%-7.21f d=%-7.21f",x,y,a,b,c,d);
	printf("\nGive me an int for my array");
	scanf("%d",&e[2]);
	printf("e= %d %d %d",e[0],e[2],e[2]);
	printf("\nf=\t%4.2lf\t%4.2lf\n\t%4.2lf\t%4.2lf",f[0][0],f[0][1],f[1][0],f[1][1]);
	
	return 0;
}
