#pragma hdrstop
#pragma argsused

#include <iostream>
#include <conio.h>

using namespace std;

int foo(int n, int r, int k)
{   int f = 0;
	if (n==0 && r==0) {
		f = 1;
	}
	else if ((n>0) && r >= 0 && r < n*(k-1)+1)) {
			for (int i = 0; i <= k-1; i++) {
				f += foo(n-1, r-i, k);
			}
		 }
		 else f = 0;
    return
}

int _tmain(int argc, _TCHAR* argv[])
{
	getch();
	return 0;
}
