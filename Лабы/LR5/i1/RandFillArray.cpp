#include <iostream>
#include <ctime>


void RandFillArr(int **arr, int line, int col)
{   srand(time(0));
	for (int i = 0; i < line; i++) {
		for (int j = 0; j < col; j++) {
			arr[i][j] = rand()%101-50;
		}
	}
}

