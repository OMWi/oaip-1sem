#pragma hdrstop
#pragma argsused

#include <iostream>
#include <cstring>
#include <windows.h>

using namespace std;

struct Trains
{   int trainNumber;
	char destination[16]{};
	int freeplaces;
	char depTime[5]{};
	int allplaces;
	int occupplaces;
};

void CreateArr(Trains *&arr, int &trains)
{	cout << "Введите количество поездов " << endl;
	cin >> trains;
	arr = new Trains[trains];
}

void DeleteArr(Trains *&arr, int &trains)
{   cout << "Введите номер поезда для удаления ";
	int num;
	cin >> num;
	Trains *narr = new Trains[trains-1];
	for (int i = 0, j = 0; j <= trains; j++) {
		if (j == num-1) {
			cout << "Поезд №" << j+1 << " удален" << endl;
			trains--;
			continue;
		}
		(narr+i)->trainNumber = i+1;
		for (int k = 0; (arr+j)->destination[k] != '\0' ; k++) {
			(narr+i)->destination[k] = (arr+j)->destination[k];
		}
		(narr+i)->allplaces = (arr+j)->allplaces;
		(narr+i)->freeplaces = (arr+j)->freeplaces;
		(narr+i)->occupplaces = (arr+j)->occupplaces;
		for (int k = 0; (arr+i)->depTime[k] != '\0' ; k++) {
			(narr+i)->depTime[k] = (arr+j)->depTime[k];
		}
		i++;
	}
	arr = narr;
}

void Fill(Trains *arr, int trains)
{   for (int i = 0; i < trains; i++) {
		(arr+i)->trainNumber = i+1;
		cout << "\n\t\tВведите данные поезда №" << i+1 << endl;
		cout << "Введите пункт назначения ";
		cin >> (arr+i)->destination;
		cout << "Введите общее количество мест в поезде ";
		cin >> (arr+i)->allplaces;
		cout << "Введите количество свободных мест в поезде ";
		cin >> (arr+i)->freeplaces;
		(arr+i)->occupplaces = (arr+i)->allplaces - (arr+i)->freeplaces;
		cout << "Количество занятых мест " << (arr+i)->occupplaces << endl;
		cout << "Введите время отправления ";
		cin >> (arr+i)->depTime;
	}
}

void PrintAll(Trains *arr, int trains)
{	for (int i = 0; i < trains; i++) {
		cout << "Поезд №" << (arr+i)->trainNumber << endl;
		cout << "\nВремя отправления " << (arr+i)->depTime;
		cout << "\tПункт назначения " << (arr+i)->destination;
		cout << "\nВсего мест " << (arr+i)->allplaces;
		cout << "\tСвободных " <<(arr+i)->freeplaces;
		cout << "\tЗанятых " << (arr+i)->occupplaces << endl << endl;
	}
}

void PrintOne(Trains *arr, int num)
{  	num--;
	cout << "Поезд №" << (arr+num)->trainNumber << endl;
	cout << "\nВремя отправления " << (arr+num)->depTime;
	cout << "\tПункт назначения " << (arr+num)->destination;
	cout << "\nВсего мест " <<(arr+num)->allplaces;
	cout << "\tСвободных " <<(arr+num)->freeplaces;
	cout << "\tЗанятых " << (arr+num)->occupplaces << endl << endl;
}

void AddTrains(Trains *&arr, int trains, int add)
{	Trains *narr = new Trains[trains + add];
	for (int i = 0; i < trains; i++) {
		(narr+i)->trainNumber = i+1;
		for (int j = 0; (arr+i)->destination[j] != '\0' ; j++) {
			(narr+i)->destination[j] = (arr+i)->destination[j];
		}
		(narr+i)->allplaces = (arr+i)->allplaces;
		(narr+i)->freeplaces = (arr+i)->freeplaces;
		(narr+i)->occupplaces = (arr+i)->occupplaces;
		for (int j = 0; (arr+i)->depTime[j] != '\0' ; j++) {
			(narr+i)->depTime[j] = (arr+i)->depTime[j];
		}
	} 
	for (int i = trains; i < trains + add; i++) {
		(narr+i)->trainNumber = i+1;
		cout << "\t\tВведите данные поезда №" << i+1 << endl;
		cout << "Введите пункт назначения ";
		cin >> (narr+i)->destination;
		cout << "Введите общее количество мест в поезде ";
		cin >> (narr+i)->allplaces;
		cout << "Введите количество свободных мест в поезде ";
		cin >> (narr+i)->freeplaces;
		(narr+i)->occupplaces = (narr+i)->allplaces - (narr+i)->freeplaces;
		cout << "Количество занятых мест " << (narr+i)->occupplaces << endl;
		cout << "Введите время отправления ";
		cin >> (narr+i)->depTime;
	}
	arr = narr;
}

void Search(Trains *arr, int trains)
{	cout << "Введите место назначения:" << endl;
	char place[20]{};
	cin >>	place;
	bool isFind = false;
	for (int j = 0; j < trains; j++) {
		bool check = true;	
		for (int i = 0; i < strlen(place); i++) {
			if (place[i] != (arr+j)->destination[i]) {
				check = false;
				break;
            }
		}
		if (check) {
			PrintOne(arr, j+1);
			isFind = true;
		}
	}
	if (!isFind) {
		cout << "Such trains not found" << endl;
	}
}

void Change(Trains *arr, int trains)
{   int i;
	cout << "Введите номер поезда для изменения данных ";
	cin >> i;
	if (i > trains) {
		cout << "Такого поезда нет";
		return;
	}
	PrintOne(arr, i);
    i--;
	cout << "Введите новые данные";
	cout << "Введите пункт назначения ";
	cin >> (arr+i)->destination;
	cout << "Введите общее количество мест в поезде ";
	cin >> (arr+i)->allplaces;
	cout << "Введите количество свободных мест в поезде ";
	cin >> (arr+i)->freeplaces;
	(arr+i)->occupplaces = (arr+i)->allplaces - (arr+i)->freeplaces;
	cout << "Количество занятых мест " << (arr+i)->occupplaces << endl;
	cout << "Введите время отправления ";
	cin >> (arr+i)->depTime;
}

void Equal(Trains *arr, Trains *brr)
{	int x = arr->trainNumber;
	arr->trainNumber = brr->trainNumber;
	brr->trainNumber = x;
	x = arr->allplaces;
	arr->allplaces = brr->allplaces;
	brr->allplaces = x;
	x = arr->freeplaces;
	arr->freeplaces = brr->freeplaces;
	brr->freeplaces = x;
	x = arr->occupplaces;
	arr->occupplaces = brr->occupplaces;
	brr->occupplaces = x;
	char y[20]{};
	strcpy(y, arr->destination);
	strcpy(arr->destination, brr->destination);
	strcpy(brr->destination, y);
}

void Sort(Trains *arr, int trains)
{   cout << "Отсортировано по количеству свободных мест\n\n";
	for (int i = 1; i < trains; i++) {
		for (int j = i; j > 0 && (arr+j)->freeplaces > (arr+j-1)->freeplaces ; j--) {
			Equal(arr+j, arr+j-1);
		}
	}
}

void Help()
{	cout << "Функции:\n1.Создание структуры\n2.Просмотр содержимого\n3.Дополнение\n4.Поиск структуры\n5.Удаление элемента\n6.Изменения элемента\n7.Сортировать\n8.Памагити\n9.Закончить программу"<<endl;
}

bool isBad(int trains)
{   if (!trains) {
		return true;
	}
	return false;
}

int _tmain(int argc, _TCHAR* argv[])
{   SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Help();
	char f = '0';
	int trains = 0;
	Trains *arr;
	while (f != '9') {
		cin >> f;
		switch(f)
		{   case '1':
			{   CreateArr(arr,trains);
				Fill(arr, trains);
			}break;
			case '2':
			{   if (isBad(trains)) {
					cout << "Поломкаа...полл...ппп..";
					break;
				}
				l1:
				cout << "1.Нажмите 0 для вывода информации о всех поездах\n2.Введите номер поезда для вывод информации о конкретном поезде" << endl;
				int x;
				cin >> x;
				if (x == 0) {
					PrintAll(arr, trains);
				}
				else if (x <= trains) {
						 PrintOne(arr, x);
					 }
					 else {
						 cout << "Error" << endl;
						 goto l1;
					 }

			}break;
			case '3':
			{   cout << "Введите количество новых поездов ";
				int add;
				cin >> add;
				AddTrains(arr, trains, add);
				trains += add;

			}break;
			case '4':
			{   if (isBad(trains)) {
					cout << "Поломкаа...полл...ппп..";
					break;
				}
				Search(arr, trains);
			}break;
			case '5':
			{	DeleteArr(arr, trains);
			}break;
			case '6':
			{	Change(arr, trains);
			} break;
			case '7':
			{   if (isBad(trains)) {
					cout << "Поломкаа...полл...ппп..";
					break;
				}
				Sort(arr, trains);
				PrintAll(arr, trains);
			} break;
			case '8':
			{   Help();
			} break;
			case '9': break;
			default: cout << "Неправильная цифра";
		}
	}

	return 0;
}
