#include <stdio.h>
#include <stdlib.h>

int main(void){
int data;
char filename[20];

FILE *in;

printf("Enter a file name with the extension.\n");
scanf(" %s",&filename);
in = fopen(filename,"r");

while(in == NULL){
printf("%s does not exist.\n",filename);
printf("Please enter the file name with the extension.\n");
scanf(" %s",&filename);
in = fopen(filename,"r");
}

fscanf(in,"%d",data);

printf("The file contains %d",data);
fclose(in);




return 0;
}
