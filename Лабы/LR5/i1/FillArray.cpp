#include <iostream>
using namespace std;

void FillArr(int **arr, int line, int col)
{	for (int i = 0; i < line; i++) {
		for (int j = 0; j < col; j++) {
			//cout << "arr[" << i+1 << "][" << j+1 << "] = ";
			cin >> arr[i][j];
		}
	}
}
