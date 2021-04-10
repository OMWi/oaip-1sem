#pragma hdrstop
#pragma argsused

#include <iostream>
#include <conio.h>

using namespace std;

int Length(char text[])
{   int i;
	for (i = 0; text[i] != '\0'; i++);
	return i;
}

//32..126

int _tmain(int argc, _TCHAR* argv[])
{   char text[80];
	cout << "Text:" << endl;
	gets(text);
	cout << "Characters:" << endl;
	for (int i = 32; i <= 126 ; i++) {
		for (int j = 0; j < Length(text); j++) {
			if (text[j] == char(i)) {
				cout << char(i);
				break;
			}
		}
	}  
	
	getch();
	return 0;
}
