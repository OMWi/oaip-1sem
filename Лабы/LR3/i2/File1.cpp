#pragma hdrstop
#pragma argsused

#include <iostream>
#include <conio.h>
#include <math.h>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{   const int x1 = -1, x2 = 1;
	float step, y, x, ymin, root;
	int part;

	cout << "Enter the number of parts ";
	cin >> part;
	step = (x2 - x1) / (float)part;
	cout << "Step = " << step;

	root = x = x1;
	ymin = fabs( sin(x) + tan(x) - 1/(1 + x*x) );

	while (x <= x2)
	{   y = fabs( sin(x) + tan(x) - 1/(1 + x*x) );
		if (y < ymin)
		{root = x;
		ymin = y;
		}
		cout << "\nx=" << x;
		cout << "\t|ymin|=" << ymin << "\t root=" << root;
		x += step;
    }
	cout << "\n\nx=" << root;
	getch();
	return 0;
}
