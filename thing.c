#include <stdlib.h>
#include <stdio.h>

int** createArray(int, int);
void destroyArray(int**);
void drawLine(const int**, int, int);

int main(){
	int size = 256;
	int N1[size][size], N2[size][size], N3[size][size];

	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){
			N1[i][j] = rand();
			N2[i][j] = rand();
		}
	}

	N3[size][size] = matrixMultiply(N1, N2);

	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){
			printf(N3[i][j]);
		}
	}

}

int** createArray(int m, int n)
{
    int* values = calloc(m*n, sizeof(int));
    int** rows = malloc(n*sizeof(int*));
    
    for (int i=0; i<n; ++i)
    {
        rows[i] = values + i*m;
    }
    
    return rows;
}

void destroyArray(float** arr)
{
    free(*arr);
    free(arr);
}

void drawLine(const float** coords, int m, int n);
