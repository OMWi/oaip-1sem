void DeleteArr(int **arr, int line)
{	for (int i = 0; i < line; i++) {
		delete arr[i];
	}
	delete []arr;
}
