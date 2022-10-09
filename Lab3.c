#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(){
	clock_t start_t, end_t, total_t;
	start_t = clock();
	int size = 0, temp, sum;
	// Time variable
    time_t t;
    // Intializes random number generator
    srand((unsigned) time(&t));
	
	printf("Choose N for two NxN matrices to be multiplied.\n");
	scanf("%d", &size);
	
	// Allocate memory of size*size*4B
	int *N1 = (int*)malloc(size*size*sizeof(int));
	int *N2 = (int*)malloc(size*size*sizeof(int));
	int *N3 = (int*)malloc(size*size*sizeof(int));
	
    // Fills arrays pseudo randomly from 0 to 1
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){
			*(N1 + i*size + j) = rand()%2;
			*(N2 + i*size + j) = rand()%2;
		}
	}

	// Matrix multiply
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){
			for(int k = 0; k < size; k++){
				temp = *(N1 + i*size + k) * *(N2 + k*size + j);
				sum = sum + temp;
		    }
		    // Result for specified index
		    *(N3 + i*size + j) = sum;
		    sum = 0;
		}
	}
	
	// Print N1
	printf("N1: \n");
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){
			if((j+1)%size == 0)
				printf("%d\n", *(N1 + i*size + j));
				
			else
				printf("%d ", *(N1 + i*size + j));
		}
	}
	
	// Print N2
	printf("N2: \n");
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){
			if((j+1)%size == 0)
				printf("%d\n", *(N2 + i*size + j));
				
			else
				printf("%d ", *(N2 + i*size + j));
		}
	}
	
	// Print N3
	printf("N3: \n");
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){
			if((j+1)%size == 0)
				printf("%d\n", *(N3 + i*size + j));
				
			else
				printf("%d ", *(N3 + i*size + j));
		}
	}
	
	end_t = clock();
	total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
    printf("Total time taken by CPU: %0.9f\n", (double)total_t );
    
	free(N1);
	free(N2);
	free(N3);
	
	return 0;
}
