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
{	cout << "������� ���������� ������� " << endl;
	cin >> trains;
	arr = new Trains[trains];
}

void DeleteArr(Trains *&arr, int &trains)
{   cout << "������� ����� ������ ��� �������� ";
	int num;
	cin >> num;
	Trains *narr = new Trains[trains-1];
	for (int i = 0, j = 0; j <= trains; j++) {
		if (j == num-1) {
			cout << "����� �" << j+1 << " ������" << endl;
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
		cout << "\n\t\t������� ������ ������ �" << i+1 << endl;
		cout << "������� ����� ���������� ";
		cin >> (arr+i)->destination;
		cout << "������� ����� ���������� ���� � ������ ";
		cin >> (arr+i)->allplaces;
		cout << "������� ���������� ��������� ���� � ������ ";
		cin >> (arr+i)->freeplaces;
		(arr+i)->occupplaces = (arr+i)->allplaces - (arr+i)->freeplaces;
		cout << "���������� ������� ���� " << (arr+i)->occupplaces << endl;
		cout << "������� ����� ����������� ";
		cin >> (arr+i)->depTime;
	}
}

void PrintAll(Trains *arr, int trains)
{	for (int i = 0; i < trains; i++) {
		cout << "����� �" << (arr+i)->trainNumber << endl;
		cout << "\n����� ����������� " << (arr+i)->depTime;
		cout << "\t����� ���������� " << (arr+i)->destination;
		cout << "\n����� ���� " << (arr+i)->allplaces;
		cout << "\t��������� " <<(arr+i)->freeplaces;
		cout << "\t������� " << (arr+i)->occupplaces << endl << endl;
	}
}

void PrintOne(Trains *arr, int num)
{  	num--;
	cout << "����� �" << (arr+num)->trainNumber << endl;
	cout << "\n����� ����������� " << (arr+num)->depTime;
	cout << "\t����� ���������� " << (arr+num)->destination;
	cout << "\n����� ���� " <<(arr+num)->allplaces;
	cout << "\t��������� " <<(arr+num)->freeplaces;
	cout << "\t������� " << (arr+num)->occupplaces << endl << endl;
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
		cout << "\t\t������� ������ ������ �" << i+1 << endl;
		cout << "������� ����� ���������� ";
		cin >> (narr+i)->destination;
		cout << "������� ����� ���������� ���� � ������ ";
		cin >> (narr+i)->allplaces;
		cout << "������� ���������� ��������� ���� � ������ ";
		cin >> (narr+i)->freeplaces;
		(narr+i)->occupplaces = (narr+i)->allplaces - (narr+i)->freeplaces;
		cout << "���������� ������� ���� " << (narr+i)->occupplaces << endl;
		cout << "������� ����� ����������� ";
		cin >> (narr+i)->depTime;
	}
	arr = narr;
}

void Search(Trains *arr, int trains)
{	cout << "������� ����� ����������:" << endl;
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
	cout << "������� ����� ������ ��� ��������� ������ ";
	cin >> i;
	if (i > trains) {
		cout << "������ ������ ���";
		return;
	}
	PrintOne(arr, i);
    i--;
	cout << "������� ����� ������";
	cout << "������� ����� ���������� ";
	cin >> (arr+i)->destination;
	cout << "������� ����� ���������� ���� � ������ ";
	cin >> (arr+i)->allplaces;
	cout << "������� ���������� ��������� ���� � ������ ";
	cin >> (arr+i)->freeplaces;
	(arr+i)->occupplaces = (arr+i)->allplaces - (arr+i)->freeplaces;
	cout << "���������� ������� ���� " << (arr+i)->occupplaces << endl;
	cout << "������� ����� ����������� ";
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
{   cout << "������������� �� ���������� ��������� ����\n\n";
	for (int i = 1; i < trains; i++) {
		for (int j = i; j > 0 && (arr+j)->freeplaces > (arr+j-1)->freeplaces ; j--) {
			Equal(arr+j, arr+j-1);
		}
	}
}

void Help()
{	cout << "�������:\n1.�������� ���������\n2.�������� �����������\n3.����������\n4.����� ���������\n5.�������� ��������\n6.��������� ��������\n7.�����������\n8.��������\n9.��������� ���������"<<endl;
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
					cout << "��������...����...���..";
					break;
				}
				l1:
				cout << "1.������� 0 ��� ������ ���������� � ���� �������\n2.������� ����� ������ ��� ����� ���������� � ���������� ������" << endl;
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
			{   cout << "������� ���������� ����� ������� ";
				int add;
				cin >> add;
				AddTrains(arr, trains, add);
				trains += add;

			}break;
			case '4':
			{   if (isBad(trains)) {
					cout << "��������...����...���..";
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
					cout << "��������...����...���..";
					break;
				}
				Sort(arr, trains);
				PrintAll(arr, trains);
			} break;
			case '8':
			{   Help();
			} break;
			case '9': break;
			default: cout << "������������ �����";
		}
	}

	return 0;
}
