#pragma hdrstop
#pragma argsused

#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{   SetConsoleOutputCP(1251);
	int g,t;
	cout << "������� ��� �������� ";
	cin >> g;
	cout << "������� ������� ��� ";
	cin >> t;
	t -= g;
	cout << t;

	switch(t % 100)
	{case 11:cout << " ���";g = -1;break;
	case 12:cout << " ���";g = -1;break;
	case 13:cout << " ���";g = -1;break;
	case 14:cout << " ���";g = -1;break;
	}
	if (g != -1)
	switch(t % 10)
	{case 1: cout << " ���";break;
	case 2:cout << " ����";break;
	case 3:cout << " ����";break;
	case 4:cout << " ����";break;
	case 5:cout << " ���";break;
	case 6:cout << " ���";break;
	case 7:cout << " ���";break;
	case 8:cout << " ���";break;
	case 9:cout << " ���";break;
	case 0:cout << " ���";break;
	}
	;

	getch();
	return 0;
}



