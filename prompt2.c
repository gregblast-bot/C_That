#include <stdio.h>
#include <stdlib.h>

int main(void){
	
	int a[20],b[20],status,i=0;
	double c[20],d[20];
	
	FILE *filein;
	filein = fopen("indata.dat","r");
	
	for(status=fscanf(filein,"%d %lf %lf %d",&a[i],&c[i],&d[i],&b[i]);status!=EOF;status=fscanf(filein,"%d %lf %lf %d",&a[i],&c[i],&d[i],&b[i])){
		printf("\n%d %lf %lf %d\n",a[i],c[i],d[i],b[i]);
		printf("%d",status);
		i=i+1;
	}
	
	printf("\n%d",status);
	

	fclose(filein);
	return 0;
}
