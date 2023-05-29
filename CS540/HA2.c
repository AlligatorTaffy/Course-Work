/*
AlligatorTaffy
February 19th 2019
Homework Assignment #2
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Struct Template
typedef struct MATRIX {
	int i;
	int j;
} MATRIX;

// Function Declarations
void printMatrix(int x, int y, int** ref);
void setMatrix(int x, int y, int** ref);
void mulMatrix(int** refA, int** refB, int** refZ);
void *threadMatrix(void *t);

//Global Variables
int m, n, p, q;
int **MatA;
int **MatB;
int **MatZ;



int main() {
	printf("Enter the Column and Row of the FIRST Matrix::\n");
	scanf("%d %d", &m, &n);		// Get user input for size of MatrixA
	MatA = malloc(m * sizeof *MatA);	// Create memory for ROW of MatrixA
	for (int i = 0; i < m; i++) {
    	MatA[i] = malloc(n * sizeof *MatA[i]);	// Create memory for COL of MatrixA
 	}
	setMatrix(m, n, MatA);	// Gets values from user for MatrixA
	//printMatrix(m, n, MatA);  // Print Matrix for debugging


	printf("Enter the Column and Row of the SECOND Matrix::\n");
	scanf("%d %d", &p, &q);		// Get user input for size of MatrixB
	MatB = malloc(p * sizeof *MatB);	// Create memory for ROW of MatrixB
	for (int i = 0; i < p; i++) {
    	MatB[i] = malloc(q * sizeof *MatB[i]);	// Create memory for COL of MatrixB
 	}
	setMatrix(p, q, MatB);		// Gets values from user for MatrixB
	//printMatrix(p, q, MatB);	// Print Matrix for debugging


	if(n == p) {	// Check condition to make sure the matrices are compatible
		MatZ = malloc(m * sizeof *MatZ);	// Create memory for ROW of MatrixZ
			for (int i = 0; i < m; i++) {
    			MatZ[i] = malloc(q * sizeof *MatZ[i]);	// Create memory for COL of MatrixZ
 		}

		pthread_t ZMat[m][q];	// Create a matrix with type pthread to make MatZ

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < q; j++) {	
				struct MATRIX *values = (MATRIX *)malloc(sizeof(MATRIX));	// Create memory for a structure sized MATRIX
				values-> i = i;	// Count i is set to values i of struct
				values-> j = j;	// Count j is set to values j of struct
				pthread_create(&ZMat[i][j], NULL, threadMatrix, (void*) values);	// Create a thread for each iteration of i and j
				pthread_join(ZMat[i][j], NULL);	// Wait for the threads to complete
			}
		
		}
		//mulMatrix(MatA, MatB, MatZ);	// Multiply matrices WITHOUT threads
		printf("\nProduct of Matrix Operations\n");;
		printMatrix(m, q, MatZ);	// Print MatrixZ
	} 
	else {
		printf("\nCannot Multiply Matrix, Incompatible Sizes!\n");
	}

	return 0;
}

// Function that gets user input and assigns them to the matrix passed
void setMatrix(int x, int y, int** ref) {
	for(int i = 0; i < x; i++){
		for(int j = 0; j < y; j++) {
			scanf("%d", &ref[i][j]);
		}
	}
}

// Function that prints the contents of passed matrix
void printMatrix(int x, int y, int** ref) {
	for(int i = 0; i < x ; i++) {
		for(int j = 0; j < y; j++) {
			printf("%d ", ref[i][j]);
		}
		printf("\n");
	}
}

// Debug function that completed the matrix multiplication WITHOUT threads
void mulMatrix(int** refA, int** refB, int** refZ) {
	int sum = 0;
	for (int c = 0; c < m; c++) {
  		for (int d = 0; d < q; d++) {
    		for (int e = 0; e < n; e++) {
	  			sum = sum + refA[c][e] * refB[e][d];
        	}
        	refZ[c][d] = sum;
        	sum = 0;
    	}
    }
}

// Function that completed the matrix multiplication WITH threads
void *threadMatrix(void *ptr) {
	int sum = 0;
	MATRIX *p = (MATRIX*)ptr;
	for (int i = 0; i < n; i++) {
		sum += MatA[p->i][i] * MatB[i][p->j];
	}
	MatZ[p->i][p->j] = sum;
	pthread_exit(NULL);
}
