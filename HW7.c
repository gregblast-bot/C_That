//We in Team 2, cerify that we have completed this assignment in an honest manner
//Gregory Wagonblast, Celia Davis, Kaizen Rodriguez
#include <stdio.h>
#include <stdlib.h>

int main(void){
	
int A = 1;
double B = 2.34;
char C;
int G[4] = {3, 5, 8, 9};
float H[2][2] = {{4.4, 5.5}, {6.6, 7.7}};

printf("The first \\n puts the text on a new line, the double slash by the ");
printf("n is needed to allow the printing of the \\n in this printout.\n");
printf("If you want to add a tab in the printout you insert \\t\t it will ");
printf("tab the text as shown here.\n\n");

printf("Sometimes it is nice to print out a text in \"double quotes\", ");
printf("this requires the double quotes escape sequence \\\". ");
printf("Sometimes it is nice to print out text in \'single quotes\', ");
printf("this requires the single quotes escape sequence \\\'.\n\n");

printf("Want to print out a %%? You need to use the escape sequence \"%%%%\", ");
printf("do you \n understand \n the code required to print this sequence out\\?");

printf("Enter whatver you want: ");
scanf("%d %lf %c", &A, &B, &C);
printf("\n\n\"Proper Printing\" %d %.2lf %c", A, B, C);
printf("\n\n\"Proper Printing\" %d %d %d", A, B, C);
printf("\n\n\"Proper Printing\" %.2lf %.2lf %.2lf", A, B, C);
printf("\n\n\"Proper Printing\" %c %c %c", A, B, C);

printf("\n\nG=[%d %d %d %d]", G[0], G[1], G[2], G[3]);
printf("\n\nH=%.2f\t%.2f\n  %.2f\t%.2f", H[0][0], H[0][1], H[1][0], H[1][1]);
 
return 0;
}
