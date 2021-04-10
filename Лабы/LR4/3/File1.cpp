#pragma hdrstop
#pragma argsused

#include <iostream>
#include <conio.h>
#include <ctime>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{   int size;
	int sum = 0, prod = 1;
	cout << "Size = ";
	cin >> size;

	int **mas = new int *[size];
	for (int i = 0; i < size; i++) {
	mas[i] = new int [size];
	}

	srand(time(0));
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			mas[i][j] = rand()%201-100;
			cout << mas[i][j] << '\t';
		}
		cout << endl;
	}
	cout << "Elements:";
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if ( (j>i && j<size-1-i)||(j>size-1-i && j<i) ) {
				sum += mas[i][j];
				prod *= mas[i][j];
				cout << mas[i][j] << ' ';
			}
		}
	}
	cout << "\nProduct = " << prod << endl;
	cout << "Sum = " << sum;

	for (int i = 0; i < size; i++) {
		delete mas[i];
	}
	delete []mas;
	getch();
	return 0;
}
