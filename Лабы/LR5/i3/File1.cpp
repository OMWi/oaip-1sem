#pragma hdrstop
#pragma argsused

#include <iostream>
#include <conio.h>
#include <windows.h>
#include <math.h>

using namespace std;

float f1(float x)
{   return ( sqrt(0.6*x + 1.5) ) / ( sqrt(x*x + 3) + 2*x );
}

float f2(float x)
{   return ( sin(0.8*x*x + 0.3) ) / ( cos(1.2*x + 0.3) + 0.7);
}

float f3(float x)
{   return 1 / (sqrt(x*x + 0.6));
}

float f4(float x)
{   return x*x*log10(x);
}

int _tmain(int argc, _TCHAR* argv[])
{   float a[] = {0.7, 0.2, 1.2, 1.4};
	float b[] = {2.1, 1.0, 2.6, 3.0};
	int part;
	cout << "The number of parts is ";
	cin >> part;

	HINSTANCE load;
	load = LoadLibrary("Integral.dll");

	typedef float (__stdcall *pf)(float (*)(float), float, float, int);
	pf  LeftReck, RightReck, CenterReck, Trap;
	LeftReck =(pf)GetProcAddress(load, "LeftReck");
	RightReck =(pf)GetProcAddress(load, "RightReck");
	CenterReck =(pf)GetProcAddress(load, "CenterReck");
	Trap =(pf)GetProcAddress(load, "Trap");

	cout << "\nFunction 1:" << "\nLeftReck " << LeftReck(f1, a[0], b[0], part) <<\
	"\tRightReck " << RightReck (f1, a[0], b[0], part) << "\tCenterReck " <<CenterReck\
	(f1, a[0], b[0], part) << "\tTrap " << Trap(f1, a[0], b[0], part) << endl;

	cout << "\nFunction 2:" << "\nLeftReck " << LeftReck(f2, a[1], b[1], part) <<\
	"\tRightReck " << RightReck (f2, a[1], b[1], part) << "\tCenterReck " <<CenterReck\
	(f2, a[1], b[1], part) << "\tTrap " << Trap(f2, a[1], b[1], part) << endl;

	cout << "\nFunction 3:" << "\nLeftReck " << LeftReck(f3, a[2], b[2], part) <<\
	"\tRightReck " << RightReck (f3, a[2], b[2], part) << "\tCenterReck " <<CenterReck\
	(f3, a[2], b[2], part) << "\tTrap " << Trap(f3, a[2], b[2], part) << endl;

	cout << "\nFunction 4:" << "\nLeftReck " << LeftReck(f4, a[3], b[3], part) <<\
	"\tRightReck " << RightReck (f4, a[3], b[3], part) << "\tCenterReck " <<CenterReck\
	(f4, a[3], b[3], part) << "\tTrap " << Trap(f4, a[3], b[3], part) << endl;

	FreeLibrary(load);
	getch();
	return 0;
}
