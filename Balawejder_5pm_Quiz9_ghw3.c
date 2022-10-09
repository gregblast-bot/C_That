//Create headers
#include <stdio.h>
#include <stdlib.h>

int main(void){
	//Initialize variables	
	int a[20],b[20],status,i=0,id=0;
	double c[20];

	//Integrity statement
	printf("I, Gregory Wagonblast, certify that I have completed this assignment in an honest manner.");

	//Point to the file
	FILE *filein;

	//Read from the file menudata.txt
	filein = fopen("menudata.txt","r");

	//Loop through to the end of the file
	for(status=fscanf(filein,"%d %d %lf",&a[i],&b[i],&c[i]);status!=EOF;status=fscanf(filein,"%d %d %lf",&a[i],&b[i],&c[i])){
		printf("\n%d %d %lf\n",a[i],b[i],c[i]);
		printf("%d",status);
		i=i+1;
	}
	printf("\n%d",status);

	//Loop indefinitely while the product id does not exist
	while(id != a[i]){ 
		printf("\nEnter product number from the menu above.");
	}

	//Tell the user what they selected
	printf("For product %d, the available quantity is %d and the price is %lf",a[i],b[i],c[i]);


	//Close the file
	fclose(filein);

	//Return 0 to main
	return 0;
	}
