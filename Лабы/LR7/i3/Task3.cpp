#pragma hdrstop
#pragma argsused

#include <iostream>
#include <conio.h>

using namespace std;

int length(char *str)
{   int i;
	for (i = 0; str[i] != '\0'; i++) {
	}
	return i;
}

bool Check(char *x)
{   int len = length(x);
	for (int i = 0; i < len; i++) {
		if (!(x[i]=='0'||x[i]=='1'||x[i]=='.'||x[i]=='+'||x[i]=='-')) {
			return false;
		}
	}
	return true;
}

void NatToDir(char *x)
{   int len = length(x);
	char *copy = new char[len+1];
	for (int i = 0; i < len; i++) {
		copy[i] = x[i];
	}
	if (x[0] == '+') {
		x[0] = '0';
		for (int i = 3, j = 1; j < len; i++, j++) {
			x[j] = copy[i];
		}
	}
	else if (x[0] == '-') {
			x[0] = '1';
			for (int i = 3, j = 1; j < len; i++, j++) {
				x[j] = copy[i];
			}
		 }
		 else {
			x[0] = '0';
			for (int i = 2, j = 1; j < len; i++, j++) {
			x[j] = copy[i];
			}
         }
}

void DirToDop(char *x)
{   if (x[0] == '0') {
		return;
	}
	int len = length(x);
	for (int i = 1; i < len; i++) {
		if (x[i] == '1') {
			x[i] = '0';
		}
		else x[i] = '1';
	}
	for (int i = len-1; ; i--) {
		if (i-1 == 0) {
			x[i] = '1';
			x[len-1] = '1';
		}
		else {
			if (x[i] == '0') {
				x[i] = '1';
				break;
			}
			else x[i] = '1';
        }
	}
}

void DopToDir(char *x)
{   if (x[0] == '0') {
		return;
	}
	int len = length(x);
	for (int i = len-1; ; i--) {
		if (x[i] == '1') {
			x[i] = '0';
			break;
		}
		else x[i] = '1';
	}
	for (int i = 1; i < len; i++) {
		if (x[i] == '1') {
			x[i] = '0';
		}
		else x[i] = '1';
	}
}

void DirToNat(char *x)
{   int len = length(x);
	char *copy = new char[len+1];
	for (int i = 0; i < len; i++) {
		copy[i] = x[i];
	}
	if (copy[0] == '0') {
		x[0] = '+';
	}
	else x[0] = '-';
	x[1] = '0';
	x[2] = '.';
	for (int i = 1,j = 3; i < len; i++, j++) {
		x[j] = copy[i];
	}
}

void Sum(char *a, char *b, char *sum)
{   int lena = length(a);
	int lenb = length(b);
	int max;
	if (lena > lenb) {
		max = lena;
		while (length(b) != max) {
			b[length(b)] = '0';
		}
	}
	else {
		max = lenb;
		while (length(a) != max) {
			a[length(a)] = '0';
        }
	}

	DirToDop(a);
	DirToDop(b);
	char rest = '0';
	for (int i = max; i >= 0; i--) {
		char res = '0';
		res += a[i] + b[i] + rest - 3*'0';
		switch(res)
		{   case '0' : rest = '0'; sum[i] = '0'; break;
			case '1': rest = '0'; sum[i] = '1'; break;
			case '2': rest = '1'; sum[i] = '0'; break;
			case '3': rest = '1'; sum[i] = '1'; break;
		}
	}
	DopToDir(sum);
	DirToNat(sum);
}

int _tmain(int argc, _TCHAR* argv[])
{   char a[30]{};
	char b[30]{};
	cout << "First number:";
	gets(a);
	cout << "Second number:";
	gets(b);
	if (!Check(a)) {
		cout << "Error";
		getch();
		return 0;
	}
	if (!Check(b)) {
		cout << "Error";
		getch();
		return 0;
	}
	NatToDir(b);
	NatToDir(a);
	char sum[30]{};
	Sum(a, b, sum);
	cout << "Sum:" << sum;

	getch();
	return 0;
}
