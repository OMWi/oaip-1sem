#pragma hdrstop
#pragma argsused

#include <iostream>
#include <conio.h>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{ 	int x, y;
	cout << "X=";
	cin >> x;
	cout << "Y=";
	cin >> y;

	if (x == y)
	{y = 0;
	x = 0;
	}
	else if (x > y) {y = 0;
					}
					else x = 0;

	cout << "\nX=" << x;
	cout << "\tY=" << y;

	getch();
	return 0;
}
