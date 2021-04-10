#pragma hdrstop
#pragma argsused

#include <iostream>
#include <conio.h>
#include <fstream>
#include <windows.h>
#include <cstring>
#include <cctype>

using namespace std;

struct Stud
{   char fio[40];
	int group;
	float ball;
	float doxod;
};

void toFile1(FILE *fp, char *name, Stud *spis, int students)
{	if ((fp = fopen(name,"w"))==NULL) {
		cout << "Cannot open file";
		return;
	}
	fp = fopen(name,"w");
	for (int i = 0; i < students; i++) {
		fputs("������� ", fp);
		fprintf(fp, "%d", i+1);
		fputs("\n��� ", fp);
		fputs((spis + i)->fio, fp);
		fputs("\n������ ", fp);
		fprintf(fp, "%d",(spis+i)->group);
		fputs("\n���� ", fp);
		fprintf(fp, "%f", (spis + i)->ball);
		fputs("\n������� ����� ����� ����� ", fp);
		fprintf(fp, "%f", (spis + i)->doxod);
		fputs("\n\n", fp);
	}
	fclose(fp);
}

/*
void fromFile(FILE *fp, char *name, Stud *&spis, int &students)
{   students = 0;
	char *str = new char[80]{};
	if ((fp = fopen(name, "r") ) != NULL)     {		int numbOfLines = 0;		int numbOfStrings = 4;		char *str = new char[80];		while (fgets(str, 80, fp)) {			numbOfLines++;
		}		int numbOfObj = (numbOfLines-1)/numbOfStrings;		spis = new Stud[numbOfObj];		students = numbOfObj;		cout << students;		fclose(fp);		if ((fp = fopen(name, "r") ) != NULL) {			for (int i = 0; i < students; i++) {
				str = {};
				fgets(str, 30, fp);
				strcpy(str, str+4);
				strcpy((spis+i)->fio, str);
				fgets(str, 30, fp);
				strcpy(str, str + 7);
				(spis+i)->group = atoi(str);
				fgets(str, 30, fp);
				strcpy(str, str + 5);
				(spis+i)->ball = atoi(str);
				fgets(str, 40, fp);
				strcpy(str, str + 26);
				(spis+i)->doxod = atoi(str);
			}
		}		else printf ("���� �� �����������\n");	}	else printf ("���� �� �����������\n");}
*/

void toFile2(FILE *fp, char *name, Stud *spis, int students)
{	if ((fp = fopen(name,"w"))==NULL) {
		cout << "Cannot open file";
		return;
	}
	fp = fopen(name,"w");
	for (int i = 0; i < students; i++) {
		fputs("������� ", fp);
		fprintf(fp, "%d", i+1);
		fputs("\n��� ", fp);
		fputs((spis + i)->fio, fp);
		fputs("\n������ ", fp);
		fprintf(fp, "%d",(spis+i)->group);
		fputs("\n���� ", fp);
		fprintf(fp, "%f", (spis + i)->ball);
		fputs("\n������� ����� ����� ����� ", fp);
		fprintf(fp, "%f", (spis + i)->doxod);
		fputs("\n\n", fp);
	}
	fclose(fp);
}

void Fill(Stud *arr, int students)
{   for (int i = 0; i < students; i++) {
		cout << "\n\t\t������� ������ �������� �" << i+1 << endl;
		cout << "������� ��� ";
		gets((arr+i)->fio);
		gets((arr+i)->fio);
		cout << "������� ������ ";
		cin >> (arr+i)->group;
		cout << "������� ������� ���� ";
		cin >> (arr+i)->ball;
		cout << "������� ������� ����� �� ����� ����� ";
		cin >> (arr+i)->doxod;
	}
}

void PrintAll(Stud *arr, int students)
{	for (int i = 0; i < students; i++) {
		cout << "������� �" << i << endl;
		cout << "\n��� " << (arr+i)->fio;
		cout << "\n������ " << (arr+i)->group;
		cout << "\n���� " << (arr+i)->ball;
		cout << "\n������� ����� " << (arr+i)->doxod << endl << endl;
	}
}

void PrintOne(Stud *arr, int num)
{  	num++;
	cout << "������� �" << num << endl;
		cout << "\n��� " << (arr+num)->fio;
		cout << "\n������ " << (arr+num)->group;
		cout << "\n���� " << (arr+num)->ball;
		cout << "\n������� ����� " << (arr+num)->doxod << endl << endl;
}

void AddStud(Stud *&arr, int &students, int add)
{	Stud *narr = new Stud[students + add];
	for (int i = 0; i < students; i++) {
		for (int j = 0; (arr+i)->fio[j] != '\0' ; j++) {
			(narr+i)->fio[j] = (arr+i)->fio[j];
		}
		(narr+i)->group = (arr+i)->group;
		(narr+i)->ball = (arr+i)->ball;
		(narr+i)->doxod = (arr+i)->doxod;
	}
	for (int i = students; i < students + add; i++) {
        cout << "\n\t\t������� ������ �������� �" << i+1 << endl;
		cout << "������� ��� ";
		cin >> (arr+i)->fio;
		cout << "������� ������ ";
		cin >> (arr+i)->group;
		cout << "������� ������� ���� ";
		cin >> (arr+i)->ball;
		cout << "������� ������� ����� �� ����� ����� ";
		cin >> (arr+i)->doxod;
	}
	arr = narr;
	students +=add;
}

void DeleteStud(Stud *&arr, int &students)
{   cout << "������� ����� �������� ��� �������� ";
	int num;
	cin >> num;
	Stud *narr = new Stud[students-1];
	for (int i = 0, j = 0; j <= students; j++) {
		if (j == num-1) {
			cout << "������� �" << j+1 << " ������" << endl;
			students--;
			continue;
		}
		for (int k = 0; (arr+j)->fio[k] != '\0' ; k++) {
			(narr+i)->fio[k] = (arr+j)->fio[k];
		}
		(narr+i)->group = (arr+j)->group;
		(narr+i)->ball = (arr+j)->ball;
		(narr+i)->doxod = (arr+j)->doxod;
		i++;
	}
	arr = narr;
}

void Change(Stud *arr, int students)
{   int num;
	cout << "������� ����� �������� ��� ��������� ������ ";
	cin >> num;
	if (num > students) {
		cout << "������ �������� ���";
		return;
	}
	PrintOne(arr, num-1);
	cout << "������� ����� ������";
	cout << "\n\t\t������� ������ �������� �" << num << endl;
	cout << "������� ��� ";
	cin >> (arr+num-1)->fio;
	cout << "������� ������ ";
	cin >> (arr + num - 1)->group;
	cout << "������� ������� ���� ";
	cin >> (arr + num - 1)->ball;
	cout << "������� ������� ����� �� ����� ����� ";
	cin >> (arr + num - 1)->doxod;
}

void Equal(Stud *arr, Stud *narr)
{   for (int k = 0; arr->fio[k] != '\0' ; k++) {
		narr->fio[k] = arr->fio[k];
	}
	narr->group = arr->group;
	narr->ball = arr->ball;
	narr->doxod = arr->doxod;
}

void Swip(Stud *arr, Stud *brr)
{   char y[20]{};
	strcpy(y, arr->fio);
	strcpy(arr->fio, brr->fio);
	strcpy(brr->fio, y);
	int x = arr->group;
	arr->group = brr->group;
	brr->group = x;
	x = arr->ball;
	arr->ball = brr->ball;
	brr->ball = x;
	x = arr->doxod;
	arr->doxod = brr->doxod;
	brr->doxod = x;
}

void Sort(Stud *&spis, int students)
{   int maloMoney = 0;
	float minDoxod = spis->doxod;
	for (int i = 0; i < students; i++) {
		if ((spis+i)->doxod < minDoxod) {
			minDoxod = (spis+i)->doxod;
		}
	}
	Stud *narr = new Stud[students];
	for (int i = 0, j = students - 1; i < students; i++) {
		if ((spis+i)->doxod < 2*minDoxod) {
			Equal(spis+i, narr+maloMoney);
			maloMoney++;
		}
		else {
			Equal(spis + i, narr + j);
			j--;
		}
	}
	for (int i = maloMoney + 1; i < students; i++) {
		for (int j = i; j >= maloMoney && (narr+j)->ball > (narr+j-1)->ball ; j--) {
			Swip(narr+j, narr+j-1);
		}
	}

	for (int i = 0; i < maloMoney; i++) {
		for (int j = i; j > 0 && (narr+j)->ball > (narr+j-1)->ball ; j--) {
			Swip(narr+j, narr+j-1);
		}
	}
	spis = narr;
}

int _tmain(int argc, _TCHAR* argv[])
{   SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	FILE *fp1, *fp2;
	char name1[]{"TempData.txt"};
	char name2[]{"Result.txt"};
	cout << "������� ���������� ��������� ";
	int students;
	cin >> students;
	Stud *spis = new Stud[students];

	Fill(spis, students);
	toFile1(fp1, name1, spis, students);

	cout << "�������� �������:\n1.����� ������\n2.�������� ���������\n3.������� ��������\n4.�������� ��������\n5.������ �� ���������\n";
	char choo;
	cin >> choo;
	switch(choo)
	{   case '1':
		{   PrintAll(spis, students);
			toFile2(fp2, name2, spis, students);			
		}break;
		case '2':
		{	cout << "������� ���������� ����� ��������� ";
			int add;
			cin >> add;
			AddStud(spis, students, add);
			toFile2(fp2, name2, spis, students);
		}break;
		case '3':
		{   DeleteStud(spis, students);
			toFile2(fp2, name2, spis, students);
		}break;
		case '4':
		{   Change(spis, students);
			toFile2(fp2, name2, spis, students);
		}break;
		case '5':
		{   Sort(spis, students);
			toFile2(fp2, name2, spis, students);
		}break;
		default:
		{	cout << "������������ �����";
			getch();
			return 1;
		}
	}

	getch();
	return 0;
}
