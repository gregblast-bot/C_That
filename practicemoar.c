#include <stdio.h>
#include <stdlib.h>

int main(void){

int status;
char filename[20];
double data[x][y],x,y;

FILE *filein;

printf("What is the name and extension of the file?");
scanf(" %s",&filename);
filein = fopen(filename, "r");

while(filein == NULL){
	printf("%s does not exist",filename);
	printf("What is the name and extension of the file?");
	scanf(" %s",&filename);
	filein = fopen(filename, "r");
}

for(status=fscanf(filein,"%lf",&data[x][y]),status!=EOF,status=fscanf(filein,"%lf",&data[x][y]){
	fscanf("lf",&data[x][y]);
	printf("%d",status);
}

for(status=fscanf(filein,"%lf",&data[x][y]),status!=EOF,status=fscanf(filein,"%lf",&data[x][y]){
	printf("lf",&data[x][y]);
}

fclose(filein);

return 0;
}
