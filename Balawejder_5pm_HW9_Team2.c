#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void){
	
//Declare data as an int array to be read from
//Declare filename as a string to be entered by the user
int data[365][2],counter=1,sum1=0,sum2=0,sum3=0,sum4=0,i=0,j=0,mindiff,maxdiff; 
int min1=data[i][j], min2=data[i][j+1], max1=data[i][j], max2=data[i][j+1], median;
double mean1=0, mean2=0, stddev1=0, stddev2=0, var1, var2,n=0;
char filename[20];

//Integrity statement, only run once since we loop back to main
while(counter != 1){
printf("We in Team 02 certify that we have completed this assignment in an honest manner.\n");
printf("Celia Davis\n");
printf("Gregory Wagonblast\n");
printf("Kaizen Edwin C. Rodriguez\n");
counter = 1 + counter;
}

//Pointer to file
FILE *filein;

//Prompt the user for the file name
printf("Enter a file name with extension. ");
scanf(" %s",&filename);

//Open a file to read from it
filein = fopen(filename,"r");

//Check indefinitely while filename is not equal to file 1930_2001.txt
if(filein==NULL){
		printf("%s does not exist.\n",filename);
		main();
}		

//Loop through rows and columns in order to scan and put into the data array what's in the file
for(int i=0;i<365;i=i+1){
	for(int j=0;j<2;j=j+1){
		fscanf(filein,"%d",&data[i][j]);
	}
}

//Loop through rows and columns in order to print what's in the file
for(int i=0;i<365;i=i+1){
	for(int j=0;j<1;j=j+1){
		printf("Temperatures on day %d in 1930 = %d \t 2001 = %d ",i+1,data[i][j],data[i+1][j-1]);
		sum1 = sum1 + data[i][j];
		sum2 = sum2 + data[i][j+1];
		sum3 = sum3 + pow((data[i][j]-mean1),2);
		sum4 = sum4 + pow((data[i][j+1]-mean2),2);
		n = n + 1;
		
		// If current element is greater than maxdiff
		if(data[i][j+1]-data[i][j] > maxdiff){
			maxdiff = data[j][i]-data[i][j];
		}
		// If current element is smaller than mindiff
		if(data[i][j+1]-data[i][j] < min1){
			mindiff = data[j][i]-data[i][j];
		}
		// If current element is greater than max 
		if(data[i][j] > max1){
			max1 = data[i][j];
		}
		// If current element is smaller than min 
		if(data[i][j] < min1){
			min1 = data[i][j];
		}
		// If current element is greater than max 
		if(data[i][j+1] > max2){
			max2 = data[i][j];
		}
		// If current element is smaller than min 
		if(data[i][j+1] < min2){
			min2 = data[i][j];
		}
	}
	printf("\n");
}
printf("**************\n");
        
mean1 = sum1/n;
mean2 = sum2/n;
var1 = sum3/n;
var2 = sum4/n;
stddev1 = sqrt(var1);
stddev1 = sqrt(var2);

printf("The average temp for 1930 is: %.4f \n",mean1);
printf("The average temp for 2001 is: %.4f \n",mean2);
printf("The min temp for 1930 is: %d \n",min1);
printf("The min temp for 2001 is: %d \n",min2);
printf("The max temp for 1930 is: %d \n",max1);
printf("The max temp for 2001 is: %d \n",max2);
printf("The min difference between 1930 and 2001 is: %d \n",mindiff);
printf("The max difference between 1930 and 2001 is: %d \n",maxdiff);
printf("The standard deviation for 1930 is: %.4f \n",stddev1);
printf("The standard deviation for 2001 is: %.4f \n",stddev2);
printf("The median temp for 1930 is: \n");
printf("The median temp for 2001 is: \n");

//Close the file and return 0 to main
fclose(filein);

FILE *fileout;
fileout = fopen("results.txt","w");
fprintf(fileout,"%.4f\n%.4f\n%d\n%d\n%d\n%d",stddev1,stddev2,min1,min2,max1,max2);
fclose(fileout);
return 0;

}
