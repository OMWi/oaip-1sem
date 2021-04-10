#pragma hdrstop
#pragma argsused

#include <iostream>
#include <conio.h>
#include <math.h>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{   const float a = 1.0, b = 1.4, h = 0.1;
	float x, y;
	x = a;
	while (x <= b)
	{   y = log(x*x);
		cout << "x=" << x << "\ty=" << y << endl;
		x += h;
	}

	getch();
	return 0;
}
