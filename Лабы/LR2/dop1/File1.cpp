#pragma hdrstop
#pragma argsused

#include <iostream>
#include <conio.h>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{   float a, b, c, max;
	cout << "a=";
	cin >> a;
	cout << "b=";
	cin >> b;
	cout << "c=";
	cin >> c;

	max = a;
	if (b>max) {
		max = b;
	}

	if (c>max) {
		max = c;
	}

	if (a + b + c - max > max) {
		cout << "Triangle exists";
	}

	else {
		cout << "Triangle does not exist";
	}

	getch();
	return 0;
}
