#pragma hdrstop
#pragma argsused

#include <iostream>
#include <conio.h>
#include <cstdio>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{   char str[80];
	cout << "Enter your words:";
	gets(str);
	cout << "\n\nYour text:" << str << endl;
	strcat(str, " ");
	int count = 0;
	int max = 0;
	for (int i = 0; i < strlen(str); i++) {
		count++;
		if (str[i] == ' ') {
			count--;
			if (count > max) {
				max = count;
			}
			count = 0;
		}
	}
	int words = 0;
	count = 0;
	for (int i = 0; i < strlen(str); i++) {
		count++;
		if (str[i] == ' ' && str[i-1] != ' ') {
			words++;
		}
		if (str[i] == ' ') {
			count--;
			if (count == max) {
				cout << "Serial number is " << words  << endl;
				cout << "Position is " << i + 1 - max << endl;
			}
			count = 0;
		}
	}

    getch();
	return 0;
}
