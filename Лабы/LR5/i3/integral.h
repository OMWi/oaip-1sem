extern "C" float __declspec(dllexport) __stdcall LeftReck(float (*foo)(float x), float a, float b, int part);
extern "C" float __declspec(dllexport) __stdcall RightReck(float (*foo)(float x), float a, float b, int part);
extern "C" float __declspec(dllexport) __stdcall CenterReck(float (*foo)(float x), float a, float b, int part);
extern "C" float __declspec(dllexport) __stdcall Trap(float (*foo)(float x), float a, float b, int part);
