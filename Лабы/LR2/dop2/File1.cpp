#pragma hdrstop
#pragma argsused

#include <iostream>
#include <conio.h>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{   float s1, s2, a, r;
	cout << "a=";
	cin >> a;
	cout << "r=";
	cin >> r;
	if (a<0 || r<0) {
		cout << "Error";
		getch();
        return 1;
	}
	s1 = M_PI * r * r;
	s2 = a * a;

	if (s1>s2) {
		cout << "Area of circle is larger\tS=" << s1;
	}

	else if (s1<s2) {
			cout << "Area of square is larger\tS=" << s2;
		 }

		 else {
			 cout << "Areas are equal";
		 }

	getch();
	return 0;
}
