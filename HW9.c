#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void){
	
//Declare data as an int array to be read from
//Declare filename as a string to be entered by the user
int data[365][2],sum1=0,sum2=0,sum3=0,sum4=0,i=0,j=0,absdiff[365],mindiff=1000,maxdiff=0; 
int min1=1000, min2=1000, max1=0, max2=0, n=0, median1, median2;
double mean1=0, mean2=0, stddev1=0, stddev2=0, var1, var2;
char filename[20];

//Integrity statement
printf("We in Team 02 certify that we have completed this assignment in an honest manner.\n");
printf("Celia Davis\n");
printf("Gregory Wagonblast\n");
printf("Kaizen Edwin C. Rodriguez\n");



//Pointer to file
FILE *filein;

//Prompt the user for the file name
printf("Enter a file name with extension. ");

//Open a file to read from it
scanf(" %s",&filename);
filein = fopen(filename,"r");



//Check indefinitely while filename is not equal to file 1930_2001.txt
while(filein==NULL){
		printf("%s does not exist.\n",filename);
		printf("Enter a file name with extension. ");
		scanf(" %s",&filename);
		filein = fopen(filename,"r");
}
	
		
//Loop through rows and columns in order to scan and put into the data array what's in the file
for(int i=0;i<365;i=i+1){
	for(int j=0;j<2;j=j+1){
		fscanf(filein,"%d",&data[i][j]);
	}
}

//Making a new array comprised of the difference between each day in 1930 and 2001
for(i=0;i<365;i=i+1){
	absdiff[i]=abs(data[i][j+1]-data[i][j]);
}

//Loop through rows and columns in order to print what's in the file
for(int i=0;i<365;i=i+1){
	for(int j=0;j<1;j=j+1){
		printf("Temperatures on day %d in 1930 = %d \t 2001 = %d ",i+1,data[i][j],data[i][j+1]);
		sum1 = sum1 + data[i][j];
		sum2 = sum2 + data[i][j+1];
		n = n + 1;
		
		// If current element is greater than maxdiff
		if(absdiff[i] > maxdiff){
			maxdiff = absdiff[i];
		}
		// If current element is smaller than mindiff
		if(absdiff[i] < mindiff){
			mindiff = absdiff[i];
		}
		// If current element is greater than max 1930
		if(data[i][j] > max1){
			max1 = data[i][j];
		}
		// If current element is smaller than min 1930
		if(data[i][j] < min1){
			min1 = data[i][j];
		} 
		// If current element is greater than max 2001
		if(data[i][j+1] > max2){
			max2 = data[i][j+1];
		}
		// If current element is smaller than min 2001
		if(data[i][j+1] < min2){
			min2 = data[i][j+1];
		}
	}
	printf("\n");
}

//Forming a new sorted array for 1930 data to be used in median1
for( int j =0; j<n-2;j=j+1)
{

for(int i = 0; i<= n-2; i=i+1)
{
	if(data[i][0]>data[i+1][0])
	{
		int Temp1=0, Temp2=0;
  		Temp1 = data[i][0];
  		Temp2 = data[i+1][0];
  		data[i][0] = Temp2;
  		data[i+1][0] = Temp1;
  		
	}
}
}
median1 = (int)(data[n/2][0]);

//Forming a new sorted array for 2001 data to be used in median2
for( int j =0; j<n-2;j=j+1)
{
for(int i = 0; i<= n-2; i=i+1)
{
  if(data[i][1]>data[i+1][1])
  {
	    int Temp1=0, Temp2=0;
  		Temp1 = data[i][1];
  		Temp2 = data[i+1][1];
  		data[i][1] = Temp2;
  		data[i+1][1] = Temp1;
  }
}
}
median2 = (int)(data[n/2][1]);
        
//calculation of the mean of each data set
mean1 = sum1/(double)n;
mean2 = sum2/(double)n;

//first part of standard deviation calculation
for(int i=0;i<365;i=i+1){
	j=0;
sum3 = sum3 + pow((data[i][j]-mean1),2);
sum4 = sum4 + pow((data[i][j+1]-mean2),2);
}

//2nd part of finding standard deviation
var1 = sum3/(double)(n-1);
var2 = sum4/(double)(n-1);
stddev1 = sqrt(var1);
stddev2 = sqrt(var2);
printf("**************\n");



//outputing all the information
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
printf("The median temp for 1930 is: %d\n", median1);
printf("The median temp for 2001 is: %d\n", median2);

//Close the file and return 0 to main
fclose(filein);

//writing results to a new file
FILE *fileout;
fileout = fopen("results.txt","w");
fprintf(fileout,"Standard deviation of 1930 is %.4f\nStandard deviation of 2001 is %.4f\nMean of 1930 is %f\nMean of 2001 is %f\nMin of 1930 is %d\nMin of 2001 is %d\nMax of 1930 is %d\nMax of 2001 is %d\nMedian of 1930 is %d\nMedian of 2001 is %d",stddev1,stddev2,mean1,mean2,min1,min2,max1,max2,median1,median2);
fclose(fileout);
return 0;

}


