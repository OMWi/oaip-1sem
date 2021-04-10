#pragma hdrstop
#pragma argsused

#include <iostream>
#include <conio.h>
#include <math.h>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{   float x,y,s;
	cout << "x=";
	cin >> x;
	cout << "y=";
	cin >> y;

	if (y == 0)
		{s = pow(x,(float)2/3) + y;
		cout << "s = y + x^(2/3) \ns = " << s;
		}
	else if ( (x / y) > 0 )
	{s = pow( (x + log(fabs(y)) ) , 3 );
	cout << "s = (x + ln(|y|))^3 \ns = " << s;
	}
		else if ( (x / y) < 0)
		{s = log(fabs(sin(y))) + (float)2/3;
		cout << "s = 2/3 + ln(|sin(y)|) \ns = " << s;
		}

	getch();
	return 0;
}
