#pragma hdrstop
#pragma argsused

#include <iostream>
#include <conio.h>
#include <math.h>
#include <windows.h>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{   float x1, y1, x2, y2, r, f;
	int a;
	SetConsoleOutputCP(1251);
	sk1:cout << "¬ыберите систему координат дл€ 1ой точки:\n1)ѕол€рна€\n2)ƒекартова\n";
	cin >> a;

	if (a != 1 && a != 2) {
	cout << "ќшибка";
	goto sk1;
	}

	if (a == 1) {
		cout << "¬ведите пол€рный радиус ";
		cin >> r;
		cout << "¬ведите пол€рный угол(в радианах) ";
		cin >> f;
		x1 = r * cos(f);
		y1 = r * sin(f);
	}

	if (a == 2) {
		cout << "¬ведите координату х ";
		cin >> x1;
		cout << "¬ведите координату у ";
		cin >> y1;
	}

	sk2:cout << "\n¬ыберите систему координат дл€ 2ой точки:\n1)ѕол€рна€\n2)ƒекартова\n";
	cin >> a;

	if (a != 1 && a != 2) {
	cout << "ќшибка";
	goto sk2;
	}

	if (a == 1) {
		cout << "¬ведите пол€рный радиус ";
		cin >> r;
		cout << "¬ведите пол€рный угол(в радианах) ";
		cin >> f;
		x2 = r * cos(f);
		y2 = r * sin(f);
	}

	if (a == 2) {
		cout << "¬ведите координату х ";
		cin >> x2;
		cout << "¬ведите координату у ";
		cin >> y2;
	}

	r = sqrt( pow ( (x1 - x2 ) , 2 ) + pow ( ( y1 - y2 ) , 2) );
	cout << "–ассто€ние между точками " << r;
	getch();
	return 0;
}
