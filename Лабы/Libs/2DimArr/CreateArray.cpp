int **CreateArr(int line, int col)
{   int **arr = new int *[line];
	for (int i = 0; i < line; i++) {
		arr[i] = new int [col];
	}
	return arr;
}
