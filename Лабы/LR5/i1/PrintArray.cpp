#include <iostream>
using namespace std;

void PrintArr(int **arr, int line, int col)
{   for (int i = 0; i < line; i++) {
		for (int j = 0; j < col; j++) {
			cout << arr[i][j] << '\t';
		}
		cout << endl;
	}
    cout << endl;
}
