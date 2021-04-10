#pragma hdrstop
#pragma argsused

#include <iostream>
#include <conio.h>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{  	double z, y, n, f, k, x, m;
	int a;
	cout << "y = sin(f(x)*n) + cos(k*x) + log(m*x)";
	cout << "\nz = ";
	cin >> z;
	if (z > 1)
		{x = z;
		cout << "x = z";
		}
	else
		{x = pow(z,2) + 1;
		cout << "x = z^2 + 1";
		}
	cout << "\nn = ";
	cin >> n;
	cout << "k = ";
	cin >> k;
	cout << "m = ";
	cin >> m;

	L1:cout << "\nSelect function value \nf(x)=: \n1)2x \n2)x^2 \n3)x/3\n";
	cin >> a;
	switch(a)
	{case 1 : f=2*x; cout << "f(x) = 2x"; break;
	case 2 : f=pow(x,2); cout << "f(x) = x^2"; break;
	case 3 : f=x/3; cout << "f(x) = x/3"; break;
	default :
	cout << "Try again";
	goto L1;
	}

	y = sin(f*n) + cos(k*x) + log(m*x);
	cout << "\ny = " << y;

	getch();
	return 0;
}
