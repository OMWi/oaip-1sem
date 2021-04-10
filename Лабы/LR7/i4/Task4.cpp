#pragma hdrstop
#pragma argsused

#include <iostream>
#include <cstdio>
#include <conio.h>

using namespace std;

int length(char *str)
{   int i;
	for (i = 0; str[i] != '\0'; i++) {
	}
	return i;
}

void toLower(char *str)
{   for (int i = 0; i < length(str); i++) {
		if (str[i] >= 'A' && str[i] <= 'Z') {
			str[i] += 32;
		}
	}
}

void add0(char *&a, char *&b)
{   char *arr = new char[30]{};
	int max, min, dif;
	
	if (length(a) >= length(b)) {
		max = length(a);
		min = length(b);
		dif = max - min;
		for (int i = 0, j = dif; i < max; i++, j++) {
			arr[j] = b[i];
		}
		b = arr;	
	}
	else {
		max = length(b);
		min = length(a);
		dif = max - min;
		for (int i = 0, j = dif; i < max; i++, j++) {
			arr[j] = a[i];
		}
		a = arr;
	}
	for (int i = 0; i < dif; i++) {
		arr[i] = '0';
	}
}

void del0(char *&str)
{   while (str[0] == '0') {
		str++;
	}
}

int equal(char x, const int basis)
{   if (x > '9') {
		return x - 'a' + 10;
	}
	else {
		return x - '0';
	}
}

char rEqual(int x, const int basis)
{   if (x > 9) {
		return 'a' + x - 10;
	}
	else return '0' + x;
}

void asArr(char *start, char *end)
{   for (int i = 0; i < length(start); i++) {
		end[i] = start[i];
	}
}

void Sum(char *a, char *b, char *&sum, const int basis)
{   add0(a, b);
	int len = length(a);
	int rest = 0;
	int res;   	
	for (int i = len-1; i >= 0; i--) {
		res = rest + equal(a[i], basis) + equal(b[i], basis);
		if (res >= basis) {
			rest = 1;
			res -= basis;
			sum[i+1] = rEqual(res, basis);
		}
		else {
			rest = 0;
			sum[i+1] = rEqual(res, basis);
		}
	}
	sum[0] = '0' + rest;
	del0(sum);
}

void Sub(char *a, char *b, char *&sub, bool &isNegative, const int basis)
{   add0(a, b);
	int len = length(a);
	int rest = 0;
	int res;
	char max[30]{};
	char min[30]{};	
	if (length(a) > length(b)) {
		asArr(a, max);
		asArr(b, min);
		isNegative = 0;
	}
	else {
		asArr(a, min);
		asArr(b, max);
		isNegative = 1;
	}
	if (length(a) == length(b)) {
		for (int i = 0; i < length(a); ) {
			if (a[i] > b[i]) {
				asArr(a, max);
				asArr(b, min);
				isNegative = 0;
				break;
			}
			else if (b[i] > a[i]) {
					asArr(b, max);
					asArr(a, min);
					isNegative = 1;
					break;					 
				 }
				 else if (length(a) - 1 == i) {
						asArr(b, max);
						asArr(a, min);
						isNegative = 0;
						break;	
					  }
					  else i++;
		}
	}

	for (int i = len-1; i >= 0; i--) {
		res = rest + equal(max[i], basis) - equal(min[i], basis);
		if (res >= 0) {
			sub[i] = rEqual(res, basis);
			rest = 0;
		}
		else {		
			sub[i] = rEqual(res + basis, basis);
			rest = -1;  			
		}
	}
	del0(sub);
}

void delsign(char *a)
{ 	if (a[0] == '+' || a[0] == '-') {
		a[0] = '0';
	}
}

bool Check(char *a, const int basis)
{   bool err = false;
	for (int i = 0; i < length(a); i++) {
		if (basis > 10) {
			if (!(a[i] == '+' || a[i] == '-' || (a[i] >= '0' && a[i] <= '9') || (a[i] >= 'a' && a[i] <= 'a' + basis - 11))) {
				err = true;
			}
		}
		else {
			if (!(a[i] == '+' || a[i] == '-' || (a[i] >= '0' && a[i] <= '0' + basis - 1))) {
				err = true;
			}
		}
	}
	return err;                      
}

int _tmain(int argc, _TCHAR* argv[])
{   const int basis = 19;
	char *a = new char[30]{};
	cout << "First number:";
	gets(a);
	toLower(a);
	char sign;
	cout << "+ or -:";
	cin >> sign;
	char *b = new char[30]{};
	cout << "Second number:";
	gets(b);gets(b);
	toLower(b);
	if (Check(a, basis)) {
		cout << "Error";
		getch();
		return 1;
	}
	if (Check(b, basis)) {
    	cout << "Error";
		getch();
		return 1;    
	}
	
	char *res = new char[30]{};
	bool isNeg;
	

	switch(sign) {
		case '+': {
			if ((a[0] != '-' && b[0] != '-') || (a[0] == '-' && b[0] == '-')) {
				if (a[0] == '-') {
					isNeg = 1;					
				}
				else isNeg = 0;
				delsign(a);
				delsign(b);
				Sum(a, b, res, basis);				
			}
			else if (a[0] != '-' && b[0] == '-') {
					delsign(a);
					delsign(b);
					Sub(a, b, res, isNeg, basis);					 
				 }
				 else if (a[0] == '-' && b[0] != '-') {
						delsign(a);
						delsign(b);
						Sub(b, a, res, isNeg, basis);			
					  }
		};break;
		case '-': {
			if (a[0] != '-' && b[0] != '-') {
				delsign(a);
				delsign(b);
				Sub(a, b, res, isNeg, basis);
			}
			else if (a[0] == '-' && b[0] == '-') {
					delsign(a);
					delsign(b);
					Sub(b, a, res, isNeg, basis);	
				 }	
				 else if (a[0] != '-' && b[0] == '-') {
						isNeg = 0;
						delsign(a);
						delsign(b);
						Sum(a, b, res, basis);
					  }
					  else if (a[0] == '-' && b[0] != '-') {
							isNeg = 1;
							delsign(a);
							delsign(b);
							Sum(a, b, res, basis);
						   }
		};break;
		default: {
			cout << "Wrong sign";
			getch();
			return 1;
        }
	}
	cout << "Result:";
	if (isNeg) {
		cout << '-';
	}
	cout << res;
	cout << endl;
	
	getch();
	return 0;
}
