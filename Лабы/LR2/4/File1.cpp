#pragma hdrstop
#pragma argsused

#include <iostream>
#include <conio.h>
#include <math.h>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{   double k,m,L,x1,x2;
	cout << "m=";
	cin >> m;
	cout << "x1=";
	cin >> x1;
	cout << "x2=";
	cin >> x2;

	k = pow( cos( pow(x1 , 2) ) , 3) + pow( sin( pow(x2 , 3) ) , 2);
	if (k < 1)
		{L = pow(k,3) + pow(m,0.2);
		}
	else
		{L = pow(k,2) - exp(m);
		}
	cout << "\nk = " << k << "\n\n";
	cout << "L = " << L;
	getch();
	return 0;
}
