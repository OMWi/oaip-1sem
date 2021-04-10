#pragma hdrstop
#pragma argsused

#include <iostream>
#include <conio.h>
#include <cmath>
#include "dArrTwo.h"

using namespace std;

void FillArrA(int **a, int **b, int **c, int size)
{   for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (fabs(b[i][j]) > fabs(c[i][j])) {
				a[i][j] = b[i][j];
			}
			else a[i][j] = c[i][j];
		}
	}
}

int _tmain(int argc, _TCHAR* argv[])
{   int size;
	cout << "Size = ";
	cin >> size;
	int **arrA = CreateArr(size, size);
	int **arrB = CreateArr(size, size);
	int **arrC = CreateArr(size, size);

	cout << "Input array B:" << endl;
	FillArr(arrB, size, size);
	cout << "Input array C:" << endl;
	FillArr(arrC, size, size);
	cout << endl;
	cout << "Array B:" << endl;
	PrintArr(arrB, size, size);
	cout << "Array C:" << endl;
	PrintArr(arrC, size, size);
	cout << endl;

	FillArrA(arrA, arrB, arrC, size);
	cout << "Array A:" << endl;
	PrintArr(arrA, size, size);

	DeleteArr(arrA, size);
	DeleteArr(arrB, size);
	DeleteArr(arrC, size);
	getch();
	return 0;
}
