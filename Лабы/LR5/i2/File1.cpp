#pragma hdrstop
#pragma argsused

#include <iostream>
#include <conio.h>
#include <ctime>

using namespace std;

bool check_array(int* arr, int a, int b) {
	bool t = arr[a] <= (a+1)*(a+1);
	if(a == b) {
		return arr[a] <= (a+1)*(a+1);
	}
	return t || check_array(arr, a + 1, b);
}

void Fill(int *arr, int size)
{   srand(time(0));
	for (int i = 0; i < size; i++) {
		arr[i] = rand()%101;
	}
}

void Print(int *arr, int size)
{   cout << "arr:\t";
	for (int i = 0; i < size; i++) {
		cout << arr[i] << '\t';
	}
	cout << endl;
}

int _tmain(int argc, _TCHAR* argv[])
{   int size;
	cout << "Size ";
	cin >> size;
	int *arr = new int[size];
	Fill(arr, size);
	Print(arr, size);
	cout << "i:\t";
	for (int i = 0; i < size; i++) {
		cout << i + 1 << '\t';
	}
	cout << "\n\nThere at least one A[i] <= i^2?" << endl;
	cout << "First half ";
	if (check_array(arr, 0, size/2-1)) {
		cout << "+";
	}
	else cout << "-";
	cout << endl;
	cout << "Second half ";
	if (check_array(arr, size/2, size-1)) {
		cout << "+";
	}
	else cout << "-";
	cout << endl;

	delete []arr;
	getch();
	return 0;
}
