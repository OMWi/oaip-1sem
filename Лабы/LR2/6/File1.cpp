#pragma hdrstop
#pragma argsused

#include <iostream>
#include <conio.h>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{   int N;
	float a,b,c,y;
	cout << "a=";
	cin >> a;
	cout << "b=";
	cin >> b;
	cout << "c=";
	cin >> c;
	cout << "N=";
	cin >> N;

	switch(N)
	{case 2 : y = b*c - a*a;  break;
	case 56 : y = b*c; break;
	case 7 : y = a*a + c; break;
	case 3 : y = a - b*c; break;
	default : y = (a+b)*(a+b)*(a+b);
	}
	cout << "Y = " << y;

	getch();
	return 0;
}
