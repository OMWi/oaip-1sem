#pragma hdrstop
#pragma argsused

#include <iostream>
#include <conio.h>
#include <tchar.h>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{  int h1,min1,h2,min2;
	cout << "h1=";
	cin >> h1;
	cout << "min1=";
	cin >> min1;
	cout << "h2=";
	cin >> h2;
	cout << "min2=";
	cin >> min2;
	int x,y,min;
	x = h1*60 + min1;
	y = h2*60 + min2;
	if (y>x) {
	min = y - x;
	}
	if (x>y) {
	min = 1440 - x + y;
	}
	cout << "Wasted time : " << min/60 << " h  " << min%60 << " min";

	getch();
	return 0;
}
