#pragma hdrstop
#pragma argsused

#include <iostream>
#include <conio.h>

using namespace std;

int foo(int n)
{   if (n % 10 > 0) {
		return n % 10;
	}
	else if (n == 0) {
			return 0;
		 }
		else return foo(n/10);

}

int soo(int p, int q)
{   if (p>q) {
		return 0;
	}

	return foo(p) + soo(p + 1, q);
}


int _tmain(int argc, _TCHAR* argv[])
{   int p, q;
	while (1) {
		cout << "Enter data:";
		cin >> p >> q;
		if (p < 0 && q < 0) {
			cout << "The end";
			getch();
			return 0;
		}
        cout << "The result " << soo(p, q) << endl;
	}
}
