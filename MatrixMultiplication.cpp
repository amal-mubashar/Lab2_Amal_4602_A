// MatrixMultiplication.cpp : Defines the entry point for the console application.
//

#include "MatrixMultiplication.h"
#include "stdafx.h"

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

int** MatrixMultiply(int rows1, int col1, int row2, int col2, int** Arr1, int** Arr2)
{
	int **result;  // result input
	result = new int *[];
	if (col1 == row2)
	{
		// Initializing elements of matrix result to 0.
		for (int i = 0; i < rows1; ++i)
		for (int j = 0; j < col2; ++j)
		{
			result[i][j] = 0;
		}

		// Multiplying matrix Arr1 and Arr2 and storing in array result 
		for (int i = 0; i < rows1; ++i)
		for (int j = 0; j < col2; ++j)
		for (int k = 0; k < col1; ++k)
		{
			result[i][j] += Arr1[i][k] * Arr2[k][j];
		}

		return result;

	}
	else
	{
		//throw exception 
	}

}

//function we will need for this

int** StrassenMultiplication(int rows1, int col1, int row2, int col2, int** Arr1, int** Arr2)
{
	int **result;  // result input
	result = new int *[];
	if (col1 == row2)
	{
		int** A;
		A = new int*[];
		int** B;
		B = new int*[];
		// make dimensions of matrix into power of 2 and square
		int n = rows1;
		if (col1 > n)
			n = col1;
		if (col2 > n)
			n = col2;
		// nearest power of 2
		n = pow(2, ceil(log(n) / log(2)));
		//filling extra with zero
		for (int i = 0; i < n;i++)
		for (int j = 0; j < n; j++)
		{
			A[i][j] = 0;
			B[i][j] = 0;
		}
		//coping matrix
		for(int i = 0; i < rows1;i++)
		for (int j = 0; j < col1; j++)
		{
			A[i][j] = Arr1[i][j];
		}
		for (int i = 0; i < rows1; i++)
		for (int j = 0; j < col1; j++)
		{
			B[i][j] = Arr2[i][j];
		}
		

		// apply function to multiply
		// modify result 
		int** C = Strassen(A,B,n);
		for (int i = 0; i < rows1;i++)
		for (int j = 0; j < col2; j++)
		{
			result[i][j] = C[i][j];
		}
		
		return result;

	}
	else
	{
		//throw exception 
	}

}




int** Strassen(int** A, int** B, int n)
{
	//convert matrix to 2 raised to power n
	int **result;  // result input
	result = new int *[];

	if (n = 1)
	{
		result[0][0] = A[0][0] * B[0][0];
		return result;
	}
	else
	{
		int** P1 = NULL;
		int** P2 = NULL;
		int** P3 = NULL;
		int** P4 = NULL;
		int** P5 = NULL;
		int** P6 = NULL;
		int** P7 = NULL;
		//copy matrix copy 4 parts making 4 new matrices
		//for A11
		int ** A11 = NULL;
		result = new int *[];
		for (int i = 0; i < n / 2; i++)
		{
			for (int j = 0; j < n / 2; j++)
			{
				A11[i][j] = A[i][j];
			}
		}
		//for A12
		int ** A12 = NULL;
		result = new int *[];
		for (int i = 0; i < n / 2; i++)
		{
			for (int j = 0; j < n / 2; j++)
			{
				A12[i][j] = A[i][j + n / 2];
			}
		}
		//for A21
		int ** A21 = NULL;
		result = new int *[];
		for (int i = 0; i < n / 2; i++)
		{
			for (int j = 0; j < n / 2; j++)
			{
				A21[i][j] = A[i + n / 2][j];
			}
		}
		//for A22
		int ** A22 = NULL;
		result = new int *[];
		for (int i = 0; i < n / 2; i++)
		{
			for (int j = 0; j < n / 2; j++)
			{
				A22[i][j] = A[i + n / 2][j + n / 2];
			}
		}
		//for B11
		int ** B11 = NULL;
		result = new int *[];
		for (int i = 0; i < n / 2; i++)
		{
			for (int j = 0; j < n / 2; j++)
			{
				A11[i][j] = A[i][j];
			}
		}
		//for B12
		int ** B12 = NULL;
		result = new int *[];
		for (int i = 0; i < n / 2; i++)
		{
			for (int j = 0; j < n / 2; j++)
			{
				B12[i][j] = B[i][j + n / 2];
			}
		}
		//for B21
		int ** B21 = NULL;
		result = new int *[];
		for (int i = 0; i < n / 2; i++)
		{
			for (int j = 0; j < n / 2; j++)
			{
				B21[i][j] = B[i + n / 2][j];
			}
		}
		//for B22
		int ** B22 = NULL;
		result = new int *[];
		for (int i = 0; i < n / 2; i++)
		{
			for (int j = 0; j < n / 2; j++)
			{
				B22[i][j] = B[i + n / 2][j + n / 2];
			}
		}

		P1 = Strassen(A11, Sub(B12, B22, n / 2), n / 2);
		P2 = Strassen(Add(A11, A12, n / 2), B22, n / 2);
		P3 = Strassen(Add(A21, A22, n / 2), B11, n / 2);
		P4 = Strassen(A22, Sub(B21, B11, n / 2), n / 2);
		P5 = Strassen(Add(A11, A22, n / 2), Add(B11, B22, n / 2), n / 2);
		P6 = Strassen(Sub(A12, A22, n / 2), Add(B21, B22, n / 2), n / 2);
		P7 = Strassen(Sub(A11, A21, n / 2), Add(B11, B12, n / 2), n / 2);

		int** C11 = NULL;
		int** C12 = NULL;
		int** C21 = NULL;
		int** C22 = NULL;
		C11 = Sub(Add(P5, P4, n / 2), Add(P2, P6, n / 2), n / 2);
		C12 = Add(P1, P2, n / 2);
		C21 = Add(P3, P4, n / 2);
		C22 = Sub(Add(P1, P5, n / 2), Sub(P3, P7, n / 2), n / 2);

		//combining c
		int ** C = NULL;
		result = new int *[];
		//for C11
		for (int i = 0; i < n / 2; i++)
		{
			for (int j = 0; j < n / 2; j++)
			{
				C[i][j] = C11[i][j];
			}
		}
		//for C12
		for (int i = 0; i < n / 2; i++)
		{
			for (int j = 0; j < n / 2; j++)
			{
				C[i][j + n / 2] = C12[i][j];
			}
		}
		//for C21
		for (int i = 0; i < n / 2; i++)
		{
			for (int j = 0; j < n / 2; j++)
			{
				C[i + n / 2][j] = C21[i][j];
			}
		}
		//for C22
		for (int i = 0; i < n / 2; i++)
		{
			for (int j = 0; j < n / 2; j++)
			{
				C[i + n / 2][j + n / 2] = C22[i][j];
			}
		}
		return C;

	}

}

int** Add(int** A, int** B, int n)
{
	int ** result;
	result = new int *[];
	for (int i = 0; i < n; i++)
	for (int j = 0; j < n; j++)
	{
		result[i][j] = A[i][j] + B[i][j];
	}
	return result;
}

int** Sub(int** A, int** B, int n)
{
	int ** result;
	result = new int *[];
	for (int i = 0; i < n; i++)
	for (int j = 0; j < n; j++)
	{
		result[i][j] = A[i][j] - B[i][j];
	}
	return result;
}