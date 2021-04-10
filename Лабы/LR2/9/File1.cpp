#pragma hdrstop
#pragma argsused

#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{   SetConsoleOutputCP(1251);
	int g,t;
	cout << "¬ведите год рождени€ ";
	cin >> g;
	cout << "¬ведите текущий год ";
	cin >> t;
	t -= g;
	cout << t;

	switch(t % 100)
	{case 11:cout << " лет";g = -1;break;
	case 12:cout << " лет";g = -1;break;
	case 13:cout << " лет";g = -1;break;
	case 14:cout << " лет";g = -1;break;
	}
	if (g != -1)
	switch(t % 10)
	{case 1: cout << " год";break;
	case 2:cout << " года";break;
	case 3:cout << " года";break;
	case 4:cout << " года";break;
	case 5:cout << " лет";break;
	case 6:cout << " лет";break;
	case 7:cout << " лет";break;
	case 8:cout << " лет";break;
	case 9:cout << " лет";break;
	case 0:cout << " лет";break;
	}
	;

	getch();
	return 0;
}



