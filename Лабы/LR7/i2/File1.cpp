#pragma hdrstop
#pragma argsused

#include <iostream>
#include <conio.h>

using namespace std;

int Length(char *str)
{   int i;
	for (i = 0; str[i] != '\0'; i++) {
	}
	return i;
}

bool Check(char *dop)
{   for (int i = 0; i < Length(dop); i++) {
		if (!((dop[i] >= '0' && dop[i] <= '9') || dop[i] == '.')) {
			return false;
		}
	}
	return true;
}

char *Transform(char *dop)
{   int len = Length(dop);
	if (dop[0] == '1') {

		for (int i = len - 2, result = 0; i > 0; i--) {
			if (dop[len - 1] == '1') {
				dop[len - 1] -= 1;
				break;
			}
			else {
				if (dop[i] == '1') {
					dop[i] = '0';
					dop[len-1] = '1';
					break;
				}
				else dop[i] = '1';
			}
		}

		for (int i = 2; i < len; i++) {
			if (dop[i] == '0') {
				dop[i] = '1';
			}
			else dop[i] = '0';
		}
	}
	return dop;
}



int _tmain(int argc, _TCHAR* argv[])
{   char dop[25];
	cout << "Enter additional code:";
	gets(dop);
	if (!Check(dop)) {
		cout << "Error";
		getch();
		return 1;
	}
	char *pr = new char[20];
	pr = Transform(dop);
	cout << "Straigt code:" << pr;


	getch();
	return 0;
}
