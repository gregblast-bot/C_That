#include <stdio.h>
#include <stdlib.h>

int main (void) {

int a[3][5] = {{2,3,1,5,1},{6,5,1,2,7},{8,1,2,7,9}},i,j;

for (i=0;i<3;i=i+1){
	for (j=0;j<5;j=j+1){
	printf("%d\t",a[i][j]);
	}
	printf("\n");
}

return 0;

}
