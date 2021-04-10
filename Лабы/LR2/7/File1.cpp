#pragma hdrstop
#pragma argsused

#include <iostream>
#include <conio.h>
#include <math.h>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{   double a,b,c,t1,t2;
	cout << "ax^4 + bx^2 + c = 0\n";
	cout << "a=";
	cin >> a;
	cout << "b=";
	cin >> b;
	cout << "c=";
	cin >> c;

	double x1=0, x2=0, x3=0, x4=0, d = b*b - 4*a*c;
	t1 = (-b + sqrt(d))/(2*a);
	t2 = (-b - sqrt(d))/(2*a);
	if (t1 > 0)
	{x1 = sqrt(t1);
	x2 = -x1;
	}
	if (t2 > 0)
	{x3 = sqrt(t2);
	x4 = -x3;
	}

	if (t1 >= 0) {
	cout << "\nx1=" << x1;
	}
	if (x2 != x1) {
	cout << "\nx2=" << x2;
	}
	if (t2 >= 0 && x1 != x3) {
	cout << "\nx3=" << x3;
	}
	if (x4 != x3) {
	cout << "\nx4=" << x4;
	}
	if ((t1 < 0 && t2 < 0) || d < 0) cout << "No roots";

	getch();
	return 0;
}
