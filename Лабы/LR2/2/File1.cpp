#pragma hdrstop
#pragma argsused

#include <iostream>;
#include <conio.h>

using namespace std;

int _tmain(int argc, _TCHAR* argv[]) 
{   float a,b,d;
char zn,y;
sk1:cin >> a >> zn >> b;

switch(zn)
{case '-': d = a-b;break;
case '+': d = a+b;break;
case '*': d = a*b;break;
case '/': d = a/b;break;
default:
cout << "Error" << "\nEnter '-', '+', '/' or '*'. Enter y to repeat" << endl;
cin >> y;
if (y == 'y') {goto sk1;
}
else return 1;
}
cout << a << zn << b << "=" << d;

	getch();
	return 0;
}
