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
		fputs("Студент ", fp);
		fprintf(fp, "%d", i+1);
		fputs("\nФИО ", fp);
		fputs((spis + i)->fio, fp);
		fputs("\nГруппа ", fp);
		fprintf(fp, "%d",(spis+i)->group);
		fputs("\nБалл ", fp);
		fprintf(fp, "%f", (spis + i)->ball);
		fputs("\nСредний доход члена семьи ", fp);
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
		}		else printf ("Файл не открывается\n");	}	else printf ("Файл не открывается\n");}
*/

void toFile2(FILE *fp, char *name, Stud *spis, int students)
{	if ((fp = fopen(name,"w"))==NULL) {
		cout << "Cannot open file";
		return;
	}
	fp = fopen(name,"w");
	for (int i = 0; i < students; i++) {
		fputs("Студент ", fp);
		fprintf(fp, "%d", i+1);
		fputs("\nФИО ", fp);
		fputs((spis + i)->fio, fp);
		fputs("\nГруппа ", fp);
		fprintf(fp, "%d",(spis+i)->group);
		fputs("\nБалл ", fp);
		fprintf(fp, "%f", (spis + i)->ball);
		fputs("\nСредний доход члена семьи ", fp);
		fprintf(fp, "%f", (spis + i)->doxod);
		fputs("\n\n", fp);
	}
	fclose(fp);
}

void Fill(Stud *arr, int students)
{   for (int i = 0; i < students; i++) {
		cout << "\n\t\tВведите данные студента №" << i+1 << endl;
		cout << "Введите ФИО ";
		gets((arr+i)->fio);
		gets((arr+i)->fio);
		cout << "Введите группу ";
		cin >> (arr+i)->group;
		cout << "Введите средний балл ";
		cin >> (arr+i)->ball;
		cout << "Введите средний доход на члена семьи ";
		cin >> (arr+i)->doxod;
	}
}

void PrintAll(Stud *arr, int students)
{	for (int i = 0; i < students; i++) {
		cout << "Студент №" << i << endl;
		cout << "\nФИО " << (arr+i)->fio;
		cout << "\nГруппа " << (arr+i)->group;
		cout << "\nБалл " << (arr+i)->ball;
		cout << "\nСредний доход " << (arr+i)->doxod << endl << endl;
	}
}

void PrintOne(Stud *arr, int num)
{  	num++;
	cout << "Студент №" << num << endl;
		cout << "\nФИО " << (arr+num)->fio;
		cout << "\nГруппа " << (arr+num)->group;
		cout << "\nБалл " << (arr+num)->ball;
		cout << "\nСредний доход " << (arr+num)->doxod << endl << endl;
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
        cout << "\n\t\tВведите данные студента №" << i+1 << endl;
		cout << "Введите ФИО ";
		cin >> (arr+i)->fio;
		cout << "Введите группу ";
		cin >> (arr+i)->group;
		cout << "Введите средний балл ";
		cin >> (arr+i)->ball;
		cout << "Введите средний доход на члена семьи ";
		cin >> (arr+i)->doxod;
	}
	arr = narr;
	students +=add;
}

void DeleteStud(Stud *&arr, int &students)
{   cout << "Введите номер студента для удаления ";
	int num;
	cin >> num;
	Stud *narr = new Stud[students-1];
	for (int i = 0, j = 0; j <= students; j++) {
		if (j == num-1) {
			cout << "Студент №" << j+1 << " удален" << endl;
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
	cout << "Введите номер студента для изменения данных ";
	cin >> num;
	if (num > students) {
		cout << "Такого студента нет";
		return;
	}
	PrintOne(arr, num-1);
	cout << "Введите новые данные";
	cout << "\n\t\tВведите данные студента №" << num << endl;
	cout << "Введите ФИО ";
	cin >> (arr+num-1)->fio;
	cout << "Введите группу ";
	cin >> (arr + num - 1)->group;
	cout << "Введите средний балл ";
	cin >> (arr + num - 1)->ball;
	cout << "Введите средний доход на члена семьи ";
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
	cout << "Введите количество студентов ";
	int students;
	cin >> students;
	Stud *spis = new Stud[students];

	Fill(spis, students);
	toFile1(fp1, name1, spis, students);

	cout << "Выберите функцию:\n1.Вывод данных\n2.Добавить студентов\n3.Удалить студента\n4.Изменить студента\n5.Список на общежитие\n";
	char choo;
	cin >> choo;
	switch(choo)
	{   case '1':
		{   PrintAll(spis, students);
			toFile2(fp2, name2, spis, students);			
		}break;
		case '2':
		{	cout << "Введите количество новых студентов ";
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
		{	cout << "Неправильная цифра";
			getch();
			return 1;
		}
	}

	getch();
	return 0;
}
