//Gregory Wagonblast, Team 2
//File headers are always needed in order to pull from c library
#include <stdio.h>
#include <stdlib.h>

//Funtion Prototypes, explained in depth below
void userCheck(char pass[20]);
int Option(void);
void Average(double a[12],double b[12],int i);
void Change(double a[12],double b[12],int i);

int main(void){
	//Initialize all variables, number in arrays is arbitrary
	int i=0,status=0,r;
	double a[100],b[100];
	char pass[20],filename[40],goagain;
	
	//Print initial statement and call on function userCheck for password
	printf("Grade for Prof. Gomy's class.\n");
	//userCheck(pass);
	
	//Create a pointer to the file
	FILE *filein;
	
	//Prompt user to enter the file name and attempt to open, if not fall into loop
	printf("Please enter the name and extension of the desired file. ");
	scanf("%s",filename);
	filein = fopen(filename,"r");
	
	
	//Error check while the file is non-existent
	while(filein == NULL){
		printf("%s does not exist.\n",filename);
		printf("Please enter the name and extension of the desired file. ");
		scanf("%s",filename);
		filein = fopen(filename,"r");
	}
	
	//Print statments
	printf("File selected: %s",filename);
	printf("Contents of the file:");
	printf("\nMidterm Grades\tFinal Grades");
	
	//Use this technique in order to scan to EOF==-1
	for(status=fscanf(filein,"%lf %lf",&a[i],&b[i]);status!=EOF;status=fscanf(filein,"%lf %lf",&a[i],&b[i])){
		printf("%.2lf\t%.2lf",a[i],b[i]);
		//i is the number of rows
		i=i+1;
	}
	
	//r is result
	r = Option();
	
	switch(r){
		
		//Case 1 replaces grades and displays, call on function Change
		case(1):{
			printf("Replacing/Updating Grade.");
			Change(a,b,i);
		}break;
		//Case 2 calculates averages and displays, call on function average
		case(2):{
			printf("Getting Grade Average.");
			Average(a,b,i);
		}break;
		//Default statement that should never happen
		default:{
			printf("You broke it!");
		}
		
	}
	
	//Prompt the user and record the input
	printf("Do something else? (y/n) ");
	scanf("%c",&goagain);
	
	//This decision return to the beginning of main if the user wants to goagain and ends the program if not
	if(goagain == 'y'){
		main();
	}
	else{
		printf("Goodbye Friends.");
	}
	
	return 0;
}

//This function has nothing to return although the string is changed and a string input for password
/*void userCheck(char pass[20]){
	
	//This loop error checks while the password is incorrectly enteres
	while(pass != '4669'){
	printf("Please enter the password. ");
	scanf("%s",pass);
	}
}*/

//This function has no inputs and returns an integer
int Option(void){
	 int response=0;
	 
	 //This lopp error checks indefinetely while response is not equal to 1 or 2 
	 while(response != 1 && response != 2){
	 printf("Would you like to (1) Replace/update grade, or (2) Get average grades? ");
	 scanf("%d",&response);
	}
	
	//Return response to main
	return response;
}
 
//This function has to double array inputs as well as an integer.
//This function returns nothing although the arrays are updated.
void Average(double a[12],double b[12],int i){
	double sum1,sum2,k,n,avg1,avg2;
		
	//This loop sums the elements of the first column
	for(int j=0;j<=12;j=j+1){
		sum1 = a[j] + k;
	}
	avg1 = k/i;
	
	//This loop sums the elements of the second column
	for(int m=0;m<=12;m=m+1){
		sum2 = a[m] + n;
	}
	avg2 = n/i;
	
	printf("The average of the midterms is %.2lf",avg1);
	printf("The average of the finals is %.2lf",avg2);
}

//This function has to double array inputs as well as an integer.
//This function returns nothing although the arrays are updated.
void Change(double a[12],double b[12],int i){
	int decision=-1;

	//This loop error checks while the decision is less then zero and exceeds the number of rows
	while(decision < 0 || decision > i){
		printf("Which students grade would you like to change? (Student 1, 2, 3....n). ");
		scanf("%d",&decision);	
	}
	
	//These statements prompt the user for new inputs and records said inputs
	printf("Please enter the new midterm grade. ");
	scanf("%lf",&a[decision]);
	printf("Please enter the new final grade. ");
	scanf("%lf",&b[decision]);
}
