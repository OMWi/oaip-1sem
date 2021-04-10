#pragma hdrstop
#pragma argsused

#include <iostream>
#include <conio.h>

using namespace std;

void Fill(int **arr, int size)
{   for (int i = 0; i < size; i++) {
		cout << "arr[" << i+1 << "]";
		for (int j = 0; j < size; j++) {
			cin >> arr[i][j];
		}
	}  
}

void Transp(int **arr, int size)
{   int temp;
	for (int i = 0; i < size; i++) {
		for (int j = i; j < size; j++) {
			temp = arr[i][j];
			arr[i][j] = arr[j][i];
			arr[j][i] = temp;
		}
	}
	cout << "Transpose completed" << endl; 
}

void RevTransp(int **arr, int size)
{   int temp;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size - i; j++) {
			temp = arr[i][j];
			arr[i][j] = arr[size - 1 - j][size - 1 - i];
			arr[size - 1 - j][size - 1 - i] = temp;
		}
	}
	cout << "Reverse transpose completed" << endl; 
}

void Print(int **arr, int size)
{   for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cout << arr[i][j] << '\t';
		}
		cout << endl;
	}
	cout << endl;
}

int Check (int **arr1, int **arr2, int size)
{   for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (arr1[i][j] != arr2[i][j]) {
				return 0;
			}
		}
	}
	return 1;
}

int _tmain(int argc, _TCHAR* argv[])
{   int size;
	cout << "Size = ";
	cin >> size;

	int **arr1 = new int *[size];
	int **arr2 = new int *[size];
	for (int i = 0; i < size; i++) {
		arr1[i] = new int [size];
		arr2[i] = new int [size];
	}
	cout << "Enter first array:" << endl;
	Fill(arr1, size);
	cout << "Enter second array:" << endl;
	Fill(arr2, size);
	cout << "Array1:" << endl;
	Print(arr1, size);
	cout << "Array2:" << endl;
	Print(arr2, size);

	if (Check(arr1, arr2, size)) {
		cout << "Matrix are equal";		
	}
	else
	{	Transp(arr1, size);
		if (Check(arr1, arr2, size)) {
			cout << "Matrix are equal";			
		}
		else 
		{   RevTransp(arr1, size);
			if (Check(arr1, arr2, size)) {
				cout << "Matrix are equal"; 				
			}
			else
			{   Transp(arr1, size);
				if (Check(arr1, arr2, size)) {
					cout << "Matrix are equal";	
				}
				else cout << "Matrix aren\'t equal";
			}   
		}       
	}

	for (int i = 0; i < size; i++) {
		delete arr1[i];
		delete arr2[i];
	}
	delete []arr1;
	delete []arr2;

	getch();
	return 0;
}
