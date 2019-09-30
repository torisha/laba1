#include<iostream>
#include<time.h>
#include"Node.h"
#include"Queue.h"
#include"Deque.h"
#include"List.h"
#include"Stack.h"
#include"Keeper.h"
using namespace std;
int main()
{
	setlocale(LC_ALL, "rus");
	srand(time(NULL));

	Keeper keep;
	char number;
	do
	{
		cout << "*********МЕНЮ**********" << endl << endl;
		cout << "1) Создать структуру" << endl << endl;
		cout << "2) Редакторовать данные" << endl << endl;
		cout << "3) Вывод на экран" << endl << endl;
		cout << "4) Удалить структуру" << endl << endl;
		cout << "5) Очистить файлы" << endl << endl;
		cout << "5) Выход" << endl << endl;
		cout << "***********************" << endl << endl;
		cout << "Введите команду: ";
		cin >> number;
		cout << "***********************" << endl << endl;
		cout << endl << endl;
		try
		{
			switch (number)
			{
			case'1':
				keep.create_el();
				cout << endl << endl;
				break;
			case'2':
				keep.edit();
				cout << endl << endl;
				break;
			case'3':
				keep.show_el();
				cout << endl << endl;
				break;
			case'4':
				keep.dell_el();
				cout << endl << endl;
				break;
			case'5':
				keep.dell();
				cout << endl << endl;
				break;
			case'6':
				break;
			}
		}
		catch (const char* msg)
		{
			cout << endl << msg << endl;
		}
	}
	while (number != '6');


	system("pause");
	return 0;
}