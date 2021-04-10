#pragma hdrstop
#pragma argsused

#include <iostream>
#include <conio.h>

using namespace std;

void Print(int **arr,int  size)
{   for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cout << arr[i][j] << '\t';
		}
		cout << endl;
	}
}

int** CrArr(int size)
{   int **arr = new int *[size];
	for (int i = 0; i < size; i++) {
		arr[i] = new int [size];
	}
	return arr;
}

void InitArr(int **arr, int size)
{	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			arr[i][j] = 0;
		}
	}
}

void DelArr(int **arr, int size)
{	for (int i = 0; i < size; i++) {
		delete arr[i];
	}
	delete []arr;
}

void OddFill(int **arr, int size)
{   for (int i = 0, j = (size-1)/2, value = 1; value <= size*size ; value++) {
		arr[i][j] = value;
		if ((i-1<0) && (j+1>size-1)) {
			i++;
		}
		else
		{   if (i-1<0) {
				if (!arr[size-1][j+1]) {
					i = size-1;
					j++;
				}
				else
				{   i++;
				}
			}
			else if (j+1 > size-1) {
				if (!arr[i-1][0]) {
					i--;
					j=0;
				}
				else {
					i++;
				}
			}
			else if (!arr[i-1][j+1]) {
				i--;j++;
			}
			else {
				i++;
			}
		}
	}
}

void SinglyEvenFill(int **arr, int size)
{   int **arrA = CrArr(size/2);
	InitArr(arrA, size/2);
	OddFill(arrA, size/2);
	for (int i = 0; i < size/2; i++) {
		for (int j = 0; j < size/2; j++) {
			arr[i][j] = arrA[i][j];
		}
	}
	DelArr(arrA, size/2);
	for (int i = 0; i < size/2; i++) {
		for (int j = 0; j < size/2; j++) {
			arr[i+size/2][j+size/2] = arr[i][j] + size*size/4;
			arr[i+size/2][j] = arr[i][j] + 3*size*size/4;
			arr[i][j+size/2] = arr[i][j] + 2*size*size/4;
		}
	}
	int temp;
	for (int i = 0; i < size/2; i++) {
		for (int j = 0; j < (size/2 - 1)/2; j++) {
			temp = arr[i][j];
			arr[i][j] = arr[i+size/2][j];
			arr[i+size/2][j] = temp;
		}
	}
	for (int i = (size/2 - 1)/2, j = 0; j < (size/2 + 1)/2; j++) {
		temp = arr[i][j];
		arr[i][j] = arr[i+size/2][j];
		arr[i+size/2][j] = temp;
	}
	if ((size-6)/4>0) {
		for (int j = size-1;  j>= size - (size - 6)/4; j--) {
			for (int i = 0; i < size/2; i++) {
				temp = arr[i][j];
				arr[i][j] = arr[i+size/2][j];
				arr[i+size/2][j] = temp;
			}
		}
	}
}

void DoublyEvenFill(int **arr, int size)
{   int *arr1 = new int[size*size];
	for (int i = 0; i < size*size; i++) {
		arr1[i] = i+1;
	}
	for (int i = 0, value = 1; i < size; i++) {
		for (int j = 0; j < size; j++,value++) {
			arr[i][j] = value;
		}
	}
	for (int i = 0; i < size/4; i++) {
		for (int j = size/4; j < 3*size/4 ; j++) {
			arr[i][j] = 0;
		}
	}
	for (int i = size-1; i >= 3*size/4; i--) {
		for (int j = size/4; j < 3*size/4; j++) {
			arr[i][j] = 0;
		}
	}
	for (int i = size/4; i < 3*size/4; i++) {
		for (int j = 0; j < size/4; j++) {
			arr[i][j] = 0;
		}
	}
	for (int i = size/4; i < 3*size/4; i++) {
		for (int j = 3*size/4; j < size; j++) {
			arr[i][j] = 0;
		}
	}
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			for (int k = 0; k < size*size; k++) {
				if (arr1[k] == arr[i][j]) {
					arr1[k] = 0;
				}
			}
		}
	}
	for (int k = 0; k < size*size; k++) {
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				if (arr[i][j] == arr1[k]) {
					arr1[k] = 0;
				}
			}
		}
	}
	for (int i = 0, k = size*size-1; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (!arr[i][j]) {
				do {
					arr[i][j] = arr1[k];
				}
				while (!arr1[k--]);
			}
		}
	}
	delete []arr1;
}

int _tmain(int argc, _TCHAR* argv[])
{   int ord;
	cout << "Order = ";
	cin >> ord;

	switch (ord) {
	case 1: cout << 1; break;
	case 2: cout << "Doesn\'t exist"; break;
	default:
		int **arr = CrArr(ord);
		InitArr(arr, ord);
		if (ord % 2 == 1) {
			OddFill(arr, ord);
			Print(arr, ord);
		}
		else if (ord % 4 == 0) {
				 DoublyEvenFill(arr, ord);
				 Print(arr, ord);
			 }
			 else if (ord % 4 == 2) {
					  SinglyEvenFill(arr, ord);
					  Print(arr, ord);
				  }
		DelArr(arr, ord);
	}

	getch();
	return 0;
}
