#include "stdafx.h"
#include "CppUnitTest.h"
#include "Header.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>

using namespace std;

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest2
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int ** x;
			x = new int*[];
			int** y;
			y = new int*[];

			int m1 = 4;
			int n1 = 3;
			int m2 = 3;
			int n2 = 4;

			for (int i = 0; i < m1; i++) {
				for (int j = 0; j < n1; j++){

					x[i][j] = rand() % (m1*n1);
				}
			}

			for (int i = 0; i < m2; i++) {
				for (int j = 0; j < n2; j++){
					y[i][j] = rand() % (m1*n1);

				}
			}

			// TODO: Your test code here
			// comparing results of both methods
			A = MatrixMultiply(m1, n1, m2, n2, A, B);
			B = StrassenMultiplication(m1, n1, m2, n2, A, B);
			int r = 1;
			for (int i = 0; i < m1; i++)
			for (int j = 0; j < n2; j++)
			{
				if (x[i][j] != y[i][j])
				{
					r = 0;
					cout << "Matrix equal\n";
					break;
				}
			}
			Assert::AreEqual(1, r);
		
		}

	};

