#pragma hdrstop
#pragma argsused

#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{   SetConsoleOutputCP(1251);
	int n,k;
	cout << "N=";
	cin >> n;
	cout << "k=";
	cin >> k;
	n += k;
	cout << n << ' ';
	switch(n)
	{case 11:cout << "Рублей";k=100;break;
	case 12:cout << "Рублей";k=100;break;
	case 13:cout << "Рублей";k=100;break;
	case 14:cout << "Рублей";k=100;break;
	}
	if (k != 100)
	switch(n % 10)
	{case 1: cout << "Рубль";break;
	case 2:cout << "Рубля";break;
	case 3:cout << "Рубля";break;
	case 4:cout << "Рубля";break;
	case 5:cout << "Рублей";break;
	case 6:cout << "Рублей";break;
	case 7:cout << "Рублей";break;
	case 8:cout << "Рублей";break;
	case 9:cout << "Рублей";break;
	case 0:cout << "Рублей";break;
	}
	;

	getch();
	return 0;
}
