#pragma hdrstop
#pragma argsused

extern "C" int _libmain(unsigned long reason)
{
	return 1;
}

extern "C" float __declspec(dllexport) __stdcall LeftReck(float (*foo)(float x), float a, float b, int part)
{   float step = (b-a)/part;
	float I = 0; float x;
	for (int i = 0; i < part; i++) {
		x = a + i*step;
		I += foo(x);
	}
	I *= step;
	return I;
}

extern "C" float __declspec(dllexport) __stdcall RightReck(float (*foo)(float x), float a, float b, int part)
{   float step = (b-a)/part;
	float I = 0; float x;
	for (int i = 1; i <= part; i++) {
		x = a + i*step;
		I += foo(x);
	}
	I *= step;
	return I;
}

extern "C" float __declspec(dllexport) __stdcall CenterReck(float (*foo)(float x), float a, float b, int part)
{   float step = (b-a)/part;
	float I = 0; float x;
	for (int i = 0; i < part; i++) {
		x = a + i*step + step/2;
		I += foo(x);
	}
	I *= step;
	return I;
}

extern "C" float __declspec(dllexport) __stdcall Trap(float (*foo)(float x), float a, float b, int part)
{   float step = (b-a)/part;
	float I =0; float x = 0;
	for (int i = 1; i <= part; i++) {
		x = a + i*step;
		I += foo(x);
	}
	I += (foo(a) + foo(a + step*part))/2;
	I *= step;
	return I;
}
