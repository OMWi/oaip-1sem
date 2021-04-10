#pragma hdrstop
#pragma argsused

#include <iostream>
#include <conio.h>
#include "D:\C++\Libs\2DimArr\dArrTwo.h"

using namespace std;

void PrintAr(int *a, int size)
{	for (int i = 0; i < size; i++) {
		cout << a[i] << '\t';
	}
	cout << endl;
}

int _tmain(int argc, _TCHAR* argv[])
{   int line, col;
	cout << "Line ";
	cin >> line;
	cout << "Column ";
	cin >> col;
	int **arr = CreateArr(line, col);
	FillArr(arr, line, col);
	cout << "\nArray:" << endl;
	PrintArr(arr, line, col);

	int size;
	for (int i = 0, j = 0; i < line && j < col; i++, j++) {
		if (arr[i][j] % 2 == 0) {
			size++;
		}
	}
	int *arr1 = new int [size];
	int prod = 1;

	for (int i = 0, j = 0, c = 0; i < line && j < col; i++, j++) {
		if (arr[i][j] % 2 == 0) {
		arr1[c] = arr[i][j];
		prod *= arr1[c];
		c++;
		}
	}
	PrintAr(arr1, size);
	cout << "The product is " << prod;
	getch();
	return 0;
}

