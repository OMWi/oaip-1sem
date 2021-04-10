#pragma hdrstop
#pragma argsused

#include <iostream>
#include <conio.h>

using namespace std;

void Translate(char *text)
{   char res[100]{};
	strcat(text, " ");


	for (int i = 0, j = 0; i < strlen(text); i++, j++) {
		if (text[i] == 'c' || text[i] == 'C') {
			if (text[i+1] == 'e' || text[i+1] == 'i' || text[i+1] == 'y' || text[i+1] == 'E' || text[i+1] == 'I' || text[i+1] == 'Y') {
				res[j] = text[i] + 's' - 'c';
			}
			else res[j] = text[i] +'k' - 'c';
            continue;
		}
		if (text[i] == 'q' || text[i] == 'Q') {
			if (text[i+1] == 'u' || text[i+1] == 'U') {
				res[j++] = text[i++] - 'q' + 'k';
				res[j] = 'v';
			}
			else res[j] = text[i] - 'q' + 'k';
			continue;
		}
		if (text[i] == 'x' || text[i] == 'X') {
			res[j++] = text[i] - 'x' + 'k';
			res[j] = 's';
			continue;
		}
		if (text[i] == 'w' || text[i] == 'W') {
			res[j] = text[i] - 'w' + 'v';
			continue;
		}
		if (text[i] == 'p' || text[i] == 'P') {
			if (text[i+1] == 'h' || text[i+1] == 'H') {
				res[j] = text[i++] - 'p' + 'f';
				continue;
			}
		}
		if (text[i] == 'y' || text[i] == 'Y') {
			if (text[i+1] == 'o' || text[i+1] == 'O') {
				if (text[i+2] == 'u' || text[i+2] == 'U') {
					res[j] = text[i] - 'y' + 'u';
					i += 2;
                    continue;
				}
			}
		}
		if (text[i] == 'o' || text[i] == 'O') {
			if (text[i+1] == 'o' || text[i+1] == 'O') {
				res[j] = text[i++] - 'o' + 'u';
				continue;
			}
		}
		if (text[i] == 'e' || text[i] == 'E') {
			if (text[i+1] == 'e' || text[i+1] == 'E') {
				res[j] = text[i++] - 'e' + 'i';
				continue;
			}
		}
		if (text[i] == 't' || text[i] == 'T') {
			if (text[i+1] == 'h' || text[i+1] == 'H') {
				res[j] = text[i++] - 't' + 'z';
				continue;
			}
		}
		res[j] = text[i];
	}
	cout << "Translated" << endl;
	for (int i = 0; i < strlen(res); i++) {
		cout << res[i];
		if (res[i] == res[i+1] || res[i] + 32 == res[i+1] || res[i] - 32 == res[i+1]) {
			i++;
		}
	}
}

int _tmain(int argc, _TCHAR* argv[])
{   char text[100]{};
	cout << "Your text:" << endl;
	gets(text);

	Translate(text);
	getch();
	return 0;
}
