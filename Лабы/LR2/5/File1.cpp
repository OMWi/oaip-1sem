#pragma hdrstop
#pragma argsused

#include <iostream>
#include <conio.h>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{float a,b,c,d,z;
	cout << "a=";
	cin >> a;
	cout << "b=";
	cin >> b;
	cout << "c=";
	cin >> c;
	cout << "d=";
	cin >> d;

	if (c >= d && a < d)
	{z = a + b/c;
	cout << "z = a + b/c";
	}
	else if (c < d && a >= d)
	{z = a - b/c;
	cout << "z = a - b/c";
	}
	else z = 0;

	cout << "\nz = " << z;

	getch();
	return 0;
}
