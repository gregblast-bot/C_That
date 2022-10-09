//Include headers
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Make function prototypes
void fun1(void);
int fun2(void);
double fun3(double,double,char);
void fun4(double,char);
void fun5(double,double [],double []);
void fun6(double,double [],double []);

int main(void){
	//Declare variables
	int decision,goagain=1;
	double x,y,op,a[5],i=0,maxandloc[2]={-100,0};
	char choice;
	
	//Point to file, and write to file results.txt
	FILE *fileout;
	fileout = fopen("results.txt","w");
			
	//Print integrity statement and call on funtion 1 to display date, team, names and purpose 
	printf("We in Team 2 certify that we have completed this assignment in an honest manner.\n\n");
	fun1();

//Continue to loop while the users wants to go again 	
while(goagain==1){
	//If this escape sequenceisn't here, program gets stuck in decision 2 loop....WEIRD
	printf("\n");
	//Call on function 2 and set equal to decision
	decision=fun2();
	
	//If decision is equal to 1, perform a math operation. If not create an array
	if(decision==1){
		printf("Please provide two real numbers.\n");
		scanf("%lf%lf",&x,&y);
		
		//Reset choice in order to continue into next loop
		choice=0;
		
		//Loop while the chocies are not viable
		while(choice!='a' && choice!='s' && choice!='m' && choice!='d'){
			printf("What operation would you like to perform?\n");
			printf("Addition (a), Subtration (s), Multiplication (m), Divisor (d).\n");
			scanf(" %c",&choice);
			//Call on function 3 and set equal to op and call on function 4
			op=fun3(x,y,choice);
			fun4(op,choice);
		}
	}
	if(decision == 2){
		//Prompt user and loop while array size does not meet requirements
		printf("Between 1 and 5 elements, how many elements would you like your array to consist of?\n");
		scanf("%lf",&i);
		while(i<1 || i>5){
		printf("Between 1 and 5 elements, how many elements would you like your array to consist of?\n");
		scanf("%lf",&i);
		}
		//Enter a number for each poition in the array
		for(int j=0;j<i;j=j+1){
			printf("Enter element in position %d ",j);
			scanf("%lf",&a[j]);
		}
		//Call on functions 5 and 6
		fun5(i,maxandloc,a);
		fun6(i,maxandloc,a);
	}	
	
	//Prompt user to go again
	printf("\nWould you like to go again? Yes(1), No(0). ");
	scanf("%d",&goagain);
}
	//Always close the file
	fclose(fileout);
	//Indicate the end of the program
	printf("End Program.");
	//Return zero to main
	return 0;
}

//Function 1 is void and only displays
void fun1(void){
	printf("Team 2\n");
	printf("Team Member Names: Celia Davis, Gregory Wagonblast, Kaizen Edwin C. Rodriguez\n");
	printf("Date: 18NOV2019\n");
	printf("This program displays the use of functions.\n");
}

//Function 2 has no elements passed in but an integer passed out to main
int fun2(void){
	int decision;
	while(decision!=1 && decision!=2){
	printf("Peform a math operation (1), or create an array (2)? ");
	scanf("%d",&decision);
	}
	return(decision);
}

//Function 3 has two doubles and a character passed in and a double passed out
double fun3(double x,double y,char choice){
	//Initialize variable being passed out to main
	double op;
	//Switch statement in order to decide what operation to perform
	switch(choice){
		
		case 'a':{
			op=x+y;
		}break;
		
		case 's':{
			op=x-y;
		}break;
		
		case 'm':{
			op=x*y;
		}break;
		
		case 'd':{
			op=((double)x/(double)y);
		}break;
		
		default:{
			printf("You done goofed!");
		}break;
	}
	//Return the result of the specific operation performed to main
	return(op);
}

//Function 4 has one double and a character passed in and displays
void fun4(double op,char choice){
	
	//Utilize a switch statement again corresponding to the specific operation that was performed
	//Also append whatever is chosen to the output file results.txt
	switch(choice){
		
		case 'a':{
			printf("The result of your addition is %.2lf.\n",op);
			FILE *fileout;
			fileout = fopen("results.txt","a");
			fprintf(fileout,"The result of your addition is %.2lf.\n",op);
		}break;
		
		case 's':{
			printf("The result of your subtraction is %.2lf.\n",op);
			FILE *fileout;
			fileout = fopen("results.txt","a");
			fprintf(fileout,"The result of your subtraction is %.2lf.\n",op);
		}break;
		
		case 'm':{
			printf("The result of your multiplication is %.2lf.\n",op);
			FILE *fileout;
			fileout = fopen("results.txt","a");
			fprintf(fileout,"The result of your multiplication is %.2lf.\n",op);
			fclose(fileout);
		}break;
		
		case 'd':{
			printf("The result of your divisor is %.2lf.\n",op);
			FILE *fileout;
			fileout = fopen("results.txt","a");
			fprintf(fileout,"The result of your divisor is %.2lf.\n",op);
		}break;
		
		default:{
			printf("You done goofed!");
			FILE *fileout;
			fileout = fopen("results.txt","a");
			fprintf(fileout,"You done goofed!");
		}break;
	}	
}

//Function 5 passes in three doubles, two of which are arrays
void fun5(double i,double maxandloc[2],double a[5]){
	// If current element is greater than max it is max, location is k+1, the zeroth element is location 1
	for(int k=0;k<i;k=k+1){
		if(a[k] > maxandloc[0]){
			maxandloc[0] = a[k];
			maxandloc[1]=k+1;	
		}
	}
}

//Function 6 passes in three doubles, two of which are arrays
void fun6(double i,double maxandloc[2], double a[5]){
	printf("The array you entered was: ");
	for(int j=0;j<i;j=j+1){
		printf("%.2lf ",a[j]);
	}
	//Also append whatever is chosen to the output file results.txt
	printf("\nThe maximum number is %.2lf at location %.2lf.\n",maxandloc[0],maxandloc[1]);
	FILE *fileout;
	fileout = fopen("results.txt","a");
	fprintf(fileout,"The maximum number is %.2lf at location %.2lf.\n",maxandloc[0],maxandloc[1]);
}
