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
	{case 11:cout << "������";k=100;break;
	case 12:cout << "������";k=100;break;
	case 13:cout << "������";k=100;break;
	case 14:cout << "������";k=100;break;
	}
	if (k != 100)
	switch(n % 10)
	{case 1: cout << "�����";break;
	case 2:cout << "�����";break;
	case 3:cout << "�����";break;
	case 4:cout << "�����";break;
	case 5:cout << "������";break;
	case 6:cout << "������";break;
	case 7:cout << "������";break;
	case 8:cout << "������";break;
	case 9:cout << "������";break;
	case 0:cout << "������";break;
	}
	;

	getch();
	return 0;
}
