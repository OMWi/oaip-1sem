#pragma hdrstop
#pragma argsused

#include <iostream>
#include <conio.h>
#include <math.h>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{   float x, s = 0, y;
	int n, i = 1, a, c = 1;
	cout << "Enter the number of row members ";
	cin >> n;
	cout << "Enter the number of x ";
	cin >> a;

	while (i <= a) {
		cout << "Enter x" << i << ' ';
		sk1:cin >> x;
		if ( (x > 1) || (x < 0.1) ) {
		cout << "Error. Enter other x in the range [0.1;1]" << endl;
		goto sk1;
		}
		y = log ( 1 / ( 2 + 2*x + x*x ) );
		while (c <= n) {
			s += pow(-1 , c) * pow(1 + x , 2*c) / c;
			c++;
		}

		cout << "y(" << x << ") = " << y;
		cout << "\ns(" << x << ") = " << s << '\n';
		i++;
	}

	getch();
	return 0;
}
