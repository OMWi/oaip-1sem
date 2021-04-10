#pragma hdrstop
#pragma argsused

#include <iostream>
#include <conio.h>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{   int a;
	cout << "Enter the integer ";
	cin >> a;

	for (int x = 1; x < 10; x++) {

		for (int y = 0; y < 10; y++) {

			for (int z = 0; z < 10; z++) {
				if (x + y + z == a) {
					cout << '\n' << x << y << z;
				}
			}
		}
	}

   /*	for (int x = -9; x < 0; x++) {

		for (int y = -9; y < 1; y++) {

			for (int z = -9; z < 1; z++) {
				if (x + y + z == a) {
					cout << '\n' << x << -y << -z;
				}
			}
		}
	}
     */
	getch();
	return 0;
}
