#pragma hdrstop
#pragma argsused

#include <iostream>
#include <conio.h>
#include <tchar.h>
#include <math.h>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{    float Y,K,A,B,C,D,p,x;
		cout << "\tY = 1 + ((K^2)/(2AB)) - B + DC\n\tA = x + sin(p)\n\tB = e^K\n\n";
		cout << "K = ";
		cin >> K;
		cout << "C = ";
		cin >> C;
		cout << "D = ";
		cin >> D;
		cout << "x = ";
		cin >> x;
		cout << "p = ";
		cin >> p;

	A=x+sin(p);
	B=exp(K);
	Y=1+(pow(K,2))/(2*A*B)-B+D*C;
	cout<<"Y="<<Y;

	getch();
	return 0;
}
