#pragma hdrstop
#pragma argsused

#include <iostream>
#include <conio.h>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{   const int line = 3;
	const int column = 2;

	int a[line][column];
	for (int i = 0; i < line; i++)
	{	for (int u = 0; u < column; u++)
		{cout << "a[" << i+1 << "][" << u+1 << "] = ";
		cin >> a[i][u];
		}
	}

	int sum = 0;
	for (int u = 1; u < line; u += 2)
	{	for (int i = 0; i < column; i++)
		{sum += a[u][i];
		}
	}

	cout << "Sum = " << sum;

	getch();
	return 0;
}
