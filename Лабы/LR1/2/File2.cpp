#pragma hdrstop
#pragma argsused

#include <iostream>
#include <conio.h>
#include <tchar.h>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{	int x;
	cout << "What do you want?" << "\n 1)int" << "\n 2)float\n";
	v: cin >> x;

	if (x==1)
		{
		int a,b;
		cout << "a=";
		cin >> a;
		cout << "b=";
		cin >> b;
		cout << "a/b = "<< a/b << ". The remainder of the division is " << a%b;
		}

	if (x==2)
		{
		float a,b;
		cout << "a=";
		cin >> a;
		cout << "b=";
		cin >> b;
		cout << "a/b = "<< a/b;
		}

	if (x!=1 && x!=2)
		{
		cout << "Print 1 or 2!!!\n";
		goto v;
		}

	getch();
	return 0;
}
