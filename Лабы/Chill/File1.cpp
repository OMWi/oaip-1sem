#include<iostream>
#include<math.h>
#include <conio.h>

using namespace std;

	int main()
	{   double x, y, S = 1, s = -1, f = 0;
		int c = 1, n, k, i = 1;

		cout << "n=";
		cin >> n;
		cout << "k=";
		cin >> k;

		do
		{cout << i << " value of X in interval -2:-0.1 = ";
        cin >> x;
			if (x > -2 && x < -0.1)
			{for (c = 1; c <= n; c++)
				{S *= (1 + x)*(1 + x);
				y = s * S / c;
				s = -s;
				f += y;
				}


			cout << x << "\ts(x)=" << f << "\ty(x)=" << log(1.0 / (2 + 2 * x + x*x)) << endl;
            i++;
			}

        }
		while (i<=k);

	getch();
	return 0;
	}


