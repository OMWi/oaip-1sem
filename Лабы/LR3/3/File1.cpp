#pragma hdrstop
#pragma argsused

#include <iostream>
#include <conio.h>
#include <math.h>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{   int m = 20, a = 0;
	float b = M_PI / 2, y, h, x;

	for (int i = 0; i < 21; i++) {
	x = a + i * (b - a) / m;
	y = sin (x) - cos (x);
	cout << "x = " << x << "\t\ty = " << y << endl;
	}

	getch();
	return 0;
}
