#pragma hdrstop
#pragma argsused

#include <iostream>
#include <conio.h>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{   float a, b, c;
	cout << "A=";
	cin >> a;
	cout << "B=";
	cin >> b;
	cout << "C=";
	cin >> c;

	if (a > b)
		{if ( a > c) a -= 0.3;
		else c -= 0.3;
		}
	else if (c > b) c -= 0.3;
			else  b -= 0.3;

	cout << "\nA=" << a << "\tB=" << b << "\tC=" << c << '\n';

	getch();
	return 0;
}
