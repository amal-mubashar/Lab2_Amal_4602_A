#include<stdio.h>
#include<stdlib.h>
#include <iostream>
#include <math.h>
#include "Header.h"

int** Add(int** A, int** B ,int n);
int** Sub(int** A, int** B, int n);
int** Strassen(int** A, int** B, int n);
int** MatrixMultiply(int r1, int c1, int r2, int c2, int** Arr1, int** Arr2);
int** StrassenMultiplication(int r1, int c1, int r2, int c2, int** Arr1, int** Arr2);

using namespace std;

int main(){


	int n;
	int m1 = 4;
	int n1 = 3;
	int m2 = 3;
	int n2 = 4;

	cout << "Enter value of n \n";
	cin >> n;

	int **A = new int*[n], **B = new int*[n];
	int **C = new int*[n];


	for (int i = 0; i < m1; i++) {
		for (int j = 0; j < n1; j++){

			A[i][j] = rand() % (m1*n1);
		}
	}

	for (int i = 0; i < m2; i++) {
		for (int j = 0; j < n2; j++){
			B[i][j] = rand() % (m1*n1);

		}
	}


	for (int i = 0; i<n; ++i)
	{
		for (int j = 0; j < n; ++j){
			A[i][j] = B[i][j] = C[i][j] = j + 1;
		}
	}

	Strassen(A, B, n);
	A = MatrixMultiply(m1, n1, m2, n2, A, B);
	B = StrassenMultiplication(m1, n1, m2, n2, A, B);


	for (int i = 0; i<n; ++i)
	{
		for (int j = 0; j < n; ++j){
			cout << C[i][j] << " ";
			cout << endl;
		}
	}
}