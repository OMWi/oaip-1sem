#pragma hdrstop
#pragma argsused

#include <iostream>
#include <conio.h>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{   int i = 1, b, a, n = 0;

	for(;i <= 30;) {
		if (i % 2 == 1)
		{a = i;
		b = i * i;
		}
		else
		{a = i/2;
		b = i * i * i;
		}
	n += (a - b) * (a - b);
	i++;
    }
	cout << "N=" << n;

	getch();
	return 0;
}
