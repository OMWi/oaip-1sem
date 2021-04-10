#pragma hdrstop
#pragma argsused

#include <iostream>
#include <conio.h>
#include <cstring>
#include <cctype>

using namespace std;

int WordsAmount(char *text)
{	int amount = 0;
	for (int i = 0; i < strlen(text); i++) {
		if (text[i] == ' ' && text[i-1] != ' ') {
			amount++;
		}
	}
	return amount;
}

char** CreateArrOfWords(char *text, int amount)
{   char **word = new char*[amount];
	for (int j = 0, c = 0, i = 0; j < strlen(text); j++) {
		c++;
		if (text[j] == ' ') {
			c--;
		}
		if (text[j] == ' ' && text[j-1] != ' ') {
			word[i] = new char[c+1];
			strncpy(word[i], text+j-c, c);
			c = 0;
			i++;
		}
	}
	return word;
}

void ToLower(char **word, int amount)
{	for (int i = 0; i < amount; i++) {
		for (int j = 0; j < strlen(word[i]); j++) {
			if (isupper(word[i][j])) {
				word[i][j] = tolower(word[i][j]);
			}
		}
	}
}

bool* ArrFreeWords(int amount)
{	bool *freeword = new bool[amount];
	for (int i = 0; i < amount; i++) {
		freeword[i] = 1;
	}
	return freeword;
}

void Result(int **option, char **word, bool *freeword, int amount)
{   int *length = new int[amount];
	for (int i = 0; i < amount; i++) {
		int now = i;
		length[i] = 1;
		option[i][0] = i;
		freeword[i] = 0;
		bool check = true;
		while (check == true) {
			check = false;
			for (int j = 0; j < amount; j++) {
				if (freeword[j] && word[j][0] == word[now][strlen(word[now])-1]) {
					option[i][length[i]] = j;
					now = j;
					check = true;
					freeword[j] = 0;
					length[i]++;
				}
			}
		}
		for (int i = 0; i < amount; i++) {
			freeword[i] = 1;
		}
	}
	int max = length[0];
	int pos = 0;
	for (int i = 0; i < amount; i++) {
		if (length[i] > max) {
			max = length[i];
			pos = i;
		}
	}
	delete []length;
	for (int i = 0; i < max; i++) {
		cout << word[option[pos][i]] << ' ';
	}                                
}

int _tmain(int argc, _TCHAR* argv[])
{   char *text = new char[80];
	cout << "Text:";
	gets(text);
	strcat(text, " ");
	int amount = WordsAmount(text);
	char **word = CreateArrOfWords(text, amount);
	delete []text;
	ToLower(word, amount);
	bool *freeword = ArrFreeWords(amount);
	int **option = new int*[amount];
	for (int i = 0; i < amount; i++) {
		option[i] = new int[amount];
	}
	Result(option, word, freeword, amount);

	for (int i = 0; i < amount; i++) {
		delete word[i];
		delete option[i];
	}
	delete []word;
	delete []option;
	delete []freeword;
	getch();
	return 0;
}
