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
	sk1:cout << "�������� ������� ��������� ��� 1�� �����:\n1)��������\n2)���������\n";
	cin >> a;

	if (a != 1 && a != 2) {
	cout << "������";
	goto sk1;
	}

	if (a == 1) {
		cout << "������� �������� ������ ";
		cin >> r;
		cout << "������� �������� ����(� ��������) ";
		cin >> f;
		x1 = r * cos(f);
		y1 = r * sin(f);
	}

	if (a == 2) {
		cout << "������� ���������� � ";
		cin >> x1;
		cout << "������� ���������� � ";
		cin >> y1;
	}

	sk2:cout << "\n�������� ������� ��������� ��� 2�� �����:\n1)��������\n2)���������\n";
	cin >> a;

	if (a != 1 && a != 2) {
	cout << "������";
	goto sk2;
	}

	if (a == 1) {
		cout << "������� �������� ������ ";
		cin >> r;
		cout << "������� �������� ����(� ��������) ";
		cin >> f;
		x2 = r * cos(f);
		y2 = r * sin(f);
	}

	if (a == 2) {
		cout << "������� ���������� � ";
		cin >> x2;
		cout << "������� ���������� � ";
		cin >> y2;
	}

	r = sqrt( pow ( (x1 - x2 ) , 2 ) + pow ( ( y1 - y2 ) , 2) );
	cout << "���������� ����� ������� " << r;
	getch();
	return 0;
}
