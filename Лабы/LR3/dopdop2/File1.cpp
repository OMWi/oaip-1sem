#pragma hdrstop
#pragma argsused

#include <iostream>
#include <conio.h>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{   int number = 1, sum = 0, k, dig;
	int c = 10, i = 1;
	cout << "k=";
    cin >> k;

	do
	{if (number / c == 1)
		{c *= 10;
		i++;
		}
	sum += i;

		if (sum >= k)
		{	while (sum >= k)
			{dig = number % 10;
			number -= dig;
			number /=10;
			//cout << "dig=" << dig << "\tnumber=" << number << "\tsum=" << sum << endl;
			sum--;
			}
		goto sk1;
		}
    //cout << "n = " << number << "\tc = " << c << "\ti=" << i << "\tsum = " << sum << endl;
	number++;
	}
	while (sum < k);

	sk1:cout << dig;

	getch();
	return 0;
}
