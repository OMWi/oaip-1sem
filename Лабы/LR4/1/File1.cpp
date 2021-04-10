#pragma hdrstop
#pragma argsused

#include <iostream>
#include <conio.h>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{   const int k = 7;
	float a[k];

	for (int i = 0; i < k; i++)
	{cout << "a[" << i+1 << "] = ";
	cin >> a[i];
	}

	float avVal = 0;
	for (int i = 0; i < k; i++)
	{avVal += a[i];
	}
	avVal /= k;

	int n = 0;
	for (int i = 0; i < k; i++)
	{	if (a[i] > avVal)
		{n++;
		}
	}
	cout << "Average value is " << avVal << endl;
	cout << "The number of elements bigger than average value is " << n;

	getch();
	return 0;
}
