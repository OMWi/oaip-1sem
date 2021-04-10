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
cout << "a=" << a << "\t b=" << b << endl;
a = a + b;
cout << "a=" << a << "\t b=" << b << endl;
b = a - b;
cout << "a=" << a << "\t b=" << b << endl;
a = a - b;
cout << "a=" << a << "\t b=" << b << endl;

	getch();
	return 0;
}
