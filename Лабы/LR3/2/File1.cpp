#pragma hdrstop
#pragma argsused

#include <iostream>
#include <conio.h>
#include <math.h>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{   float d, e = 0.001, s = 0;
	int n = 1;

	do
	{d = pow( 1.0/2 , n ) + pow( 1.0/3 , n );
	s += d;
	n++;
	}
	while (d >= e);
	cout << "Row sum is " << s << "\nLast element is " << d;

	getch();
	return 0;
}
