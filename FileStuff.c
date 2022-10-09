#include <stdio.h>
#include <stdlib.h>

//KNOW HOW TO READ TO THE END OF A FILE!

int main(void){
//goagain=1
int status,somewhere,j;
double y;

FILE *out;
out=fopen("out.dat","w");

for(j=0;j<10;j=j+1){
	y=j+2.0;
	printf("%d\n",j);
	fprintf(out,"%d %lf\n",j,y);
}
fclose(out);

FILE *in;
char filename[40];
printf("Give me a filename.");
scanf(" %s",&filename);

in=fopen(filename,"r");

if(in==NULL){
		printf("Bad Boi!");
}
else{
for(status=fscanf(in,"%d %lf",&somewhere,&y);status!=-1;status=fscanf(in,"%d %lf",&somewhere,&y)){
	printf("%d\t%lf\t%d\n",somewhere,y,status);
}

/*for(j=0;j<=10;j=j+1){
	status=fscanf(in,"%d %lf",&somewhere,&y);
	printf("%d\t%lf\t%d\n",somewhere,y,status);
}*/
fclose(in);
}

/*for(goagain=1;goagain==1;scanf("%d",&goagain)){
	printf("Want to go again?");
}*/

/*while(goagain==1){
	printf("Want to go again?");
	scanf("%d",&goagain);
}*/

return 0;

}
