#pragma hdrstop
#pragma argsused

#include <iostream>
#include <conio.h>
#include <cstdlib>

using namespace std;

void Error()
{   cout << "Error";
	getch();
}

void Convert(int &l, int &m, char arr[])
{   char lch[12]{};
	char mch[6]{};
	int i = 0;
	for (; arr[i] != ' ' && arr[i] != '\0'; i++) {
		lch[i] = arr[i];
	}
	while (arr[i] == ' ') i++;
	for (int j = 0; arr[i] != ' ' && arr[i] != '\0'; j++, i++) {
		mch[j] = arr[i];
	}
	l = atoi(lch);
	m = atoi(mch);
}

void Sum()
{

}

void Options(int length)
{   char a[1000000];
	for (int i = 0; i < 999999; i++) {
		a[i] = '0';
	}
	char b[10];
	for (int i = 0; i < 9; i++) {
        b[i] = '0';
	}
	int lena = strlen(a);
	int lenb = strlen(b); 
	int *result = new int[lena+lenb];
	for (int i = 0; i < lena+lenb; i++) {
		result[i] = 0;
	}
	
	int **arr = new int*[lenb];
	for (int i = lenb-1, c = i; i >= 0; i--) {
		arr[i] = new int[lena+1];
		for (int k = 0; k < lena + lenb; k++) {
			arr[i][k] = 0;
		}
		for (int j = lena-1; j >= 0; j--) {
			int x = int(a[j] - '0')*int(b[i] - '0');
			arr[i][j] += x % 10;
			x -= x % 10;
			x /= 10;
			arr[i][j-1] += x;			
		}				
	}
	
	for (int i = lena - 1; i >= 0; i--) {
		int y = 0; 
		for (int j = lenb - 1; j >= 0; j--) {
			y += arr[j][i];		
		}
		
			result[i] += y % 10;
			y -= y % 10;
			y /= 10;
			result[i] += y;
		
	}
}

int _tmain(int argc, _TCHAR* argv[])
{   char tch[4];
	char lmch[20];
	char s1[200];
	char s2[200];
	int result[100];
	gets(tch);
	int t = atoi(tch);
	int l, m;
	for (int q = 0; q < t; q++) {
		gets(lmch);
		gets(s1);
		gets(s2);
		Convert(l, m, lmch);
		int length = l - strlen(s1) - strlen(s2);
		Options(length);
		//result[q] = Options(length) % m;
	}
	for (int i = 0; i < t; i++) {
		cout << result[i] << endl;
	}
	getch();
	return 0;
}
