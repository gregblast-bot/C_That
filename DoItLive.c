#include <stdio.h>
#include <stdlib.h>

int main (void) {

int a[4][4] = {{2,7,8,10},{11,3,1,9},{6,4,7,12},{3,5,8,1}},userdiv,count,i,j,k;
int goagain=1;

while (goagain == 1){
printf("Give me a number you would like to determine divisibility by ");
scanf("%d",&userdiv);
k=1;

while (k<=userdiv){
	count=0;
	for (i=0;i<4;i=i+1){
		for (j=0;j<4;j=j+1){
			if(a[i][j]%k==0){
				count=count+1;
			}
		}	
	}
	printf("The number %d is divisible by %d of the element of the array\n",k,count);
	k=k+1;
}

printf("Wanna try again, (1) for yes, (2) for no. ");
scanf("%d",&goagain);

while (goagain!=1 && goagain!=2){
	printf("Wanna try again");
	scanf("%d",&goagain);
}
}

printf("Goodbye");
return 0;

}
