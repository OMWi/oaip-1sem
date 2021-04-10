#pragma hdrstop
#pragma argsused

#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{   int a, sum = 0, i = 1;
	SetConsoleOutputCP(1251);
	cout << "Enter the number ";
	cin >> a;

	while (i < a)
		{if (a % i == 0)
			{sum += i;			
			}
		i++;
		}
	 
		if (sum == a)
		{cout << "\nЧисло является совершенным";
		}
		else
		{cout << "\nЧисло не является совершенным";
		}

	getch();
	return 0;
}
