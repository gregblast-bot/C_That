#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.14159265358979323846264338327

int main(void)
{
	printf("We in Team 02 certify that we have completed this assignment in an honest manner.\n");
	printf("Celia Davis\n");
	printf("Gregory Wagonblast\n");
	printf("Kaizen Edwin C. Rodriguez\n");

	double t, t2, t1, vSum, Voltage, Voltage2, Voltage1, epsilon, VoltageDif;
	int n, loop;
	char choice;

	loop = 0;
	printf("How would you like to calculate voltage?\n(a) Input time(t) and number of terms(n)\n(b) Input time(t) and Epsilon\n(c) Change in Voltage between two times.\nChoice: "); 
	while( loop == 0)
	{	
		scanf(" %c", &choice);

		switch(choice)
		{
			case 'a':
		
				printf("Enter time (t) (where -3<t<3): ");
				scanf(" %lf", &t);
				printf("Enter the number of terms (n): ");
				scanf(" %d", &n);

				for(int i = 1; i<=n; i++)
				{
					vSum = vSum + (1/pow((2*i-1),2))*cos(((2*i-1)*M_PI*t)/3);
				}
				Voltage = (3.0/2.0) - (12.0*vSum/pow(M_PI,2));

				printf("\nt = %lf\nn = %d\nVoltage = %lf\n",t,n, Voltage);
				// Output value off by 0.0004171% compared to value on sheet.
				
				loop = 1;
				break;

			case 'b':
						
				printf("Enter time (t) (where -3<t<3): ");
				scanf(" %lf", &t);
				printf("Enter an epsilon value: ");
				scanf(" %lf", &epsilon);
				
				for(double i = 0.0; i<=epsilon; i++)
				{
					vSum = vSum + (1/pow((2*i-1),2))*cos(((2*i-1)*M_PI*t)/3);
				}

				
				Voltage = (3.0/2.0) - (12*vSum/pow(M_PI,2));
				printf(" %lf\n", Voltage);
				loop = 1;
				break;

			case 'c':
				
				printf("\nEnter t2 value: ");
				scanf(" %lf", &t2);
				printf("\nEnter t1 value: ");
				scanf(" %lf", &t1);

				while(t1>t2)
				{
					printf("\nt1 is greater than t2! Re-enter values");
					printf("\nEnter t2 value: ");
					scanf(" %lf", &t2);
					printf("\nEnter t1 value: ");
					scanf(" %lf", &t1);
				}
				printf("\nEnter the number of terms (n): ");
				scanf(" %d", &n);

				//Calculating t2
				vSum = 0;
				for(int i = 1; i<=n; i++)
				{
					vSum = vSum + (1/pow((2*i-1),2))*cos(((2*i-1)*M_PI*t2)/3);
				}
				Voltage2 = (3.0/2.0) - (12.0*vSum/pow(M_PI,2));

				//Calculating t1
				vSum = 0;
				for(int i = 1; i<=n; i++)
				{
					vSum = vSum + (1/pow((2*i-1),2))*cos(((2*i-1)*M_PI*t1)/3);
				}
				Voltage1 = (3.0/2.0) - (12.0*vSum/pow(M_PI,2));

				//Calculating Change in Voltage
				VoltageDif = Voltage2-Voltage1;

				printf("\nt2: %lf\nt1: %lf\nn: %d\nVoltage(t2): %lf\nVoltage(t1): %lf\nChange in Voltage: %lf\n", t2, t1, n, Voltage2, Voltage1, VoltageDif );

				loop = 1;
				break;

			default:
			printf("Bad Input. Choose (a, b, c)! \n");
			break;
		}
	}

	//"Have the entire program in a loop to allow the user to do a different option (a, b or c). "
	// Asks user if they want to run program again. (Done by calling main method if they enter yes)
	char runAgain;
	int runAgainCon = 0;
	printf("Would you like to run the program again? (y/n) ");
	while(runAgainCon == 0)
	{
		scanf(" %c", &runAgain);
		switch(runAgain)
		{
			case 'y':
				runAgainCon = 1;
				printf("\n\n");
				main();
				break;

			case 'n':
				runAgainCon = 1;
				printf("---PROGRAM END---\n");
				break;

			default:
				printf("Bad Input \nWould you like to run the program again? (y/n) ");
		}
	}
	return 0;
}
