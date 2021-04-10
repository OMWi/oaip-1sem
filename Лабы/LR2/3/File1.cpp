#pragma hdrstop
#pragma argsused

#include <iostream>
#include <conio.h>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{   float a,b;
	cout << "a=";
	cin >> a;
	cout << "b=";
	cin >> b;
	bool c = a > b;

	c ? cout << "Max = " << a:cout << "Max = " << b;

	getch();
	return 0;
}

