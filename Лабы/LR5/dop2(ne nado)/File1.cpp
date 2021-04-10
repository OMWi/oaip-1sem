#pragma hdrstop
#pragma argsused

#include <iostream>
#include <conio.h>
#include <ctime>

using namespace std;
float **Create(int line, int col)
{   float **arr = new float *[line];
	for (int i = 0; i < line; i++) {
		arr[i] = new float [col];
	}
	return arr;
}

void Delete(float **arr, int line)
{   for (int i = 0; i < line; i++) {
		delete arr[i];
	}
	delete []arr;
}

void Print(float **arr, int line, int col)
{   for (int i = 0; i < line; i++) {
		for (int j = 0; j < col; j++) {
			cout << arr[i][j] << '\t';
		}
		cout << endl;
	}
	cout << endl;
}

void Fill(float **arr, int line, int col)
{   srand(time(0));
	for (int i = 0; i < line; i++) {
		for (int j = 0; j < col; j++) {
			arr[i][j] = (rand()%1001-500)/10;
		}
	}
}

int Check (float **arr, int line, int col)
{   for (int i = 0, check = 0; i < line; i++) {
		for (int j = 0; j < col; j++) {
			if (!arr[i][j]) {
				check++;    
			}
		}               
	}                   
}

int _tmain(int argc, _TCHAR* argv[])
{   int line, col;
	cout << "Line ";
	cin >> line;
	cout << "Column ";
	cin >> col;
	float **arr = Create(line, col);
	Fill(arr, line, col);
	Print(arr, line, col);
	int size = Check(arr, line, col);
	float *arr1 = new float [size];
	
	for (int i = 0, c = 0; i < line; i++) {
		for (int j = 0; j < col; j++) {
			if (!arr[i][j]) {
				arr1[c++] = arr[i][j];    
			}
		}               
	}

	for (int i = 0; i < size; i++) {
        cout << arr1[i] << '\t';
	}
	 






	Delete(arr, line);
	getch();
	return 0;
}
