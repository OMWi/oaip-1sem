#pragma hdrstop
#pragma argsused

#include <iostream>
#include <conio.h>
#include <cstring>

using namespace std;
long long Factorial(int n)
{   if (n == 1 || n == 0) {
		return 1;
	}
	return n * Factorial(n-1);
}

int _tmain(int argc, _TCHAR* argv[])
{   char str[80];
	cout << "Text:" << endl;
	gets(str);
	if (strlen(str) > 14) {
		cout << "Too many letters...";
		getch();
		return 1;
	}

	cout << Factorial(strlen(str));

	getch();
	return 0;
}
