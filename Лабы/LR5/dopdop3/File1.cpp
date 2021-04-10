#pragma hdrstop
#pragma argsused

#include <iostream>
#include <conio.h>

using namespace std;

int foo(int n, int max)
{   if (n == 1) {
		return 1;
	}
	else if (n % 2 == 1) {
			max = n;
		 }
		 else {
			while (n % max != 0 || max % 2 != 1)
			{   max --;
			}
		 }
	return max + foo(n-1, n-1);
}

int _tmain(int argc, _TCHAR* argv[])
{   int n;
	cout << "n ";
	sk1:cin >> n;
	if (n < 1) {
		cout << "Enter other number ";
		goto sk1;
	}
	cout << foo(n, n);
	getch();
	return 0;
}
