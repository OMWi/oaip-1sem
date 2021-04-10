#pragma hdrstop
#pragma argsused

#include <iostream>
#include <conio.h>

using namespace std;

int Length(char *str)
{   int i;
	for (i = 0; str[i] != '\0'; i++) {
	}
	return i;
}

void toLower(char *str)
{   for (int i = 0; i < Length(str); i++) {
		if (str[i] >= 'A' && str[i] <= 'Z') {
			str[i] += 32;
		}
	}
}

int Power(int n, int deg)
{  	if (deg == 0) {
		return 1;
	}

	for (int i = 1, c = n; i < deg; i++) {
		n *= c;
	}
	return n;
}

int getNum(char *str)
{   int num = 0;
	for (int i = 0, j = Length(str) - 1; i < Length(str); i++, j--) {
		num += (str[i] - '0') * Power(10,j);
	}
	return num;
}

void Reverse(char *str)
{   char *reverse = new char[Length(str)+1];
	for (int i = Length(str)-1, j = 0; i >= 0; i--, j++) {
		reverse[j] = str[i];
	}
	for (int i = 0; i < Length(str); i++) {
		str[i] = reverse[i];
	}
	delete[] reverse;
}

int toDec(char *num, const int basis)
{   int res = 0;
	for (int x, i = 0, j = Length(num) - 1; i < Length(num); i++, j--) {
		if (num[i] > '9') {
			x = num[i] - 'a';
			x += 10;
		}
		else x = num[i] - '0';
		res += x*Power(basis, j);
	}
	return res;
}

void fromDec(int num, const int basis, char *&res)
{   for (int i = 0; num > 0 ; i++) {
		char x = num % basis + '0';
		if (x > '9') {
			x += 7;
		}
		res[i] = x;
		num -= num % basis;
		num /= basis;
	}
	Reverse(res);
}

bool Check(char *num, const int bas)
{	for (int i = 0; i < Length(num); i++) {
		if (!(num[i] >= '0' && num[i] <= '9')) {
			if (bas > 10) {
				if (!(num[i] >= 'a' && num[i] <= 'a' + bas - 11)) {
					return false;
				}
			}
			else {
				return false;
			}
		}
	}
	return true;
}

int _tmain(int argc, _TCHAR* argv[])
{   char num[100]{};
	const int basis1 = 14;
	const int basis2 = 3;

	cout << "Number : ";
	gets(num);
	toLower(num);
	if (!Check(num, basis1)) {
		cout << "Error";
		getch();
		return 1;
	}
	char *result = new char[100];
	fromDec(toDec(num, basis1), basis2, result);
	cout << result << endl;
	delete[] result;

	getch();
	return 0;
}
