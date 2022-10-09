#include <stdio.h>
#include <stdlib.h>

int main (void) {

double y;
int i;

FILE *outtie;
outtie = fopen("out.dat","w"); //w(write),r(read),a(append) are our options

printf("The address of out.dat is %p\n",outtie);

for (i=1;i<=8;i=i+1){
	if (i==6){
		rewind(outtie);
	}
	if (i==7){
		fclose(outtie);
		outtie=fopen("out.dat","a");
	}
	y=i*2.0;
	printf("%d %6.3lf\n",i,y);
	fprintf(outtie,"%d %6.3lf\n",i,y);
}

fclose(outtie);

FILE *innie;
innie = fopen("out.dat","r");
int j[10];
double x[10];

for (i=1;i<=7;i=i+1){
	fscanf(innie,"%d %lf",&j[i],&x[i]);
	printf("%d %lf\n",j[i],x[i]);
}

fclose(innie);

return 0;

}
