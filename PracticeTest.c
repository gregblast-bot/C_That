#include <stdio.h>
#include <stdlib.h>

void fun1(char filename[40]);


int main(void){
int a[20],d[20],status,i=0;;
double b[20],c[20];
char filename[40];

FILE *filein;

fun1(filename);

filein = fopen(filename,"r");

while(filein == NULL){
printf("%s does not exist",filename);
printf("Enter a file name with extension. ");
scanf("%s",filename);
filein = fopen(filename,"r");
}

for((status=fscanf(filein,"%d %lf %lf %d",&a[i],&b[i],&c[i],&d[i]));status!=-1;(status=fscanf(filein,"%d %lf %lf %d",&a[i],&b[i],&c[i],&d[i]))){
	printf("%d\t%lf\t%lf\t%d\n",a[i],b[i],c[i],d[i]);
	i = i + 1;
}
fclose(filein);
	
printf("%d",i);

FILE *fileout;

fileout = fopen("REEE","w");
fprintf(fileout,"This is the length in nanometers of my genitalia. %dnm",i);
fclose(fileout);
	
return 0;
}

void fun1(char filename[40]){
printf("Enter a file name with extension. ");
scanf("%s",filename);
}

int fun2(){
	switch(variable){
		
		case(1):{
		
		break;	
		}
		case(2):{
		
		break;	
		}
		default:{
			
		}
	}
}
