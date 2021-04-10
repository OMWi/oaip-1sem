float **CreateArr(int line, int col)
{   float **arr = new float *[line];
	for (int i = 0; i < line; i++) {
		arr[i] = new float [col];
	}
	return arr;
}
