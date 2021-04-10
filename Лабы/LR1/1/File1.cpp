#pragma hdrstop
#pragma argsused

#include <iostream>
#include <conio.h>
#include <tchar.h>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{   int a,b;
	cout << "a=";
	cin >> a;
	cout << "b=";
	cin >> b;
	int y=a*b;
	cout << "y=" << y;

	getch();
	return 0;
}
