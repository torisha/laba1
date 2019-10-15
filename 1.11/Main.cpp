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
	int n = 1;

	int num = 0;
	int num2 = 0;
	int w = 0;
	int dat = 0;

	char number;
	do
	{
		cout << "*********МЕНЮ**********" << endl << endl;
		cout << "1) Создать структуру " << endl << endl;
		cout << "2) Удалить все элементы" << endl << endl;

		cout << "3) Добавить элемент" << endl<<endl;
		cout << "4) Удалить элемент" << endl<<endl;
		cout << "5) Вывести на экран" << endl << endl;

		cout << "6) Записать в файлы" << endl << endl;
		cout << "7) Очистить файлы" << endl << endl;
		cout << "8) Выход" << endl << endl;
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
				cout << "Как будем работать?" << endl;
				cout << "1 - Создать новый объект" << endl;
				cout << "2 - Загрузить данные из файла" << endl;
				cout << "Введите команду: ";
				cin >> num;
				cout << endl;
				if (num != 1 && num != 2 && num != 3)
				{
					throw "!!! НЕКОРРЕКТНАЯ КОМАНДА !!!";
					cout << endl << endl;
				}
				if (num == 1)
				{
					cout << "Что создать?" << endl << "0 лист" << endl << "1 стек" << endl << "3 дек" << endl;
					cin >> num2;
					if (num2 != 1 && num2 != 2 && num2 != 0)
					{
						throw "!!! НЕКОРРЕКТНАЯ КОМАНДА !!!";
						cout << endl << endl;
					}
					else
					{
						cout << "Введите размер: ";
						cin >> w;
						cout << endl;
						keep.Fill(num2, w);
					}
				}

				if (num == 2)
				{
					keep.Read_F();
					//читаем все файлы
				}
				cout << endl << endl;
				break;
			case'2':
				cout << "Что очистить?" << endl << "0 лист" << endl << "1 стек" << endl << "2 дек" << endl;
				cout << "3 всё!" << endl;
				cin >> num;
				if (num != 1 && num != 2 && num != 3 && num != 4)
				{
					throw "!!! НЕКОРРЕКТНАЯ КОМАНДА !!!";
					cout << endl << endl;
				}
				if (num == 3)
				{
					keep.Clear(0);
					keep.Clear(1);
					keep.Clear(2);
				}
				else
				{
					keep.Clear(num);
				}
				cout << ">>> Информация стерта" << endl;
				cout << endl << endl;
				break;
			case'3':
				cout << ">>> ДОБАВИТЬ ЭЛЕМЕНТ:" << endl;
				cout << "1 в начало " << endl;
				cout << "2 в конец " << endl;
				cout << "3 по индексу" << endl;
				cout << "Выберете действие: ";
				cin >> w;
				cout << endl;

				keep.Show(0);
				cout << endl;
				keep.Show(1);
				cout << endl;
				keep.Show(2);
				cout << endl;

				cout << "С чем будем работать?" << endl;
				cout << "0 - Список " << endl;
				cout << "1 - Стек" << endl;
				cout << "2 - Дек" << endl;
				cout << "Введите команду: ";
				cin >> num;

				cout << endl;
				cout << "Введите элемент:";
				cin >> dat;
				cout << endl << endl;

				if (num != 1 && num != 2 && num != 0)
				{
					throw "!!! НЕКОРРЕКТНАЯ КОМАНДА !!!";
					cout << endl << endl;
				}
				
				if (w == 1)
				{
					keep.PushFront(dat, num);
				}
				if (w == 2)
				{
					keep.PushBack(dat, num);
				}
				if (w == 3)
				{
					cout << "Введите индекс элемента, послк которого добавим новый:";
					cin >> num2;
					keep.InsertAt(dat, num2, num);
				}
				cout << "\n>>> Результат\n";
				keep.Show(num);
				cout << endl << endl;
				break;
			case'4':
				cout << ">>> УДАЛИТЬ ЭЛЕМЕНТ:" << endl;
				cout << "1 из начала " << endl;
				cout << "2 из конца " << endl;
				cout << "3 по индексу" << endl;
				cout << "Выберете действие: ";
				cin >> w;
				cout << endl;
				keep.Show(0);
				cout << endl;
				keep.Show(1);
				cout << endl;
				keep.Show(2);
				cout << endl;
				cout << "С чем будем работать?" << endl;
				cout << "0 - Список " << endl;
				cout << "1 - Стек" << endl;
				cout << "2 - Дек" << endl;
				cout << "Введите команду: ";
				cin >> num;
				if (num != 1 && num != 2 && num != 0)
				{
					throw "!!! НЕКОРРЕКТНАЯ КОМАНДА !!!";
					cout << endl << endl;
				}

				if (w == 1)
				{
					keep.PopFront(num);
				}
				if (w == 2)
				{
					keep.PopBack(num);
				}
				if (w == 3)
				{
					
						cout << "Введите индекс элемента для удаления:";
						cin >> num2;
						keep.RemAt(num2, num);
					
				}
				cout << "\n>>> Результат\n";
				keep.Show(num);
				cout << endl;
				
				cout << endl << endl;

				cout << endl << endl;
				break;
			case'5':
				cout << "Что показать?" << endl << "0 лист" << endl << "1 стек" << endl << "2 дек" << endl;
				cout << "3 всё!!!" << endl;
				cin >> num;
				if (num != 1 && num != 2 && num != 3 && num != 0)
				{
					throw "!!! НЕКОРРЕКТНАЯ КОМАНДА !!!";
					cout << endl << endl;
				}
				else if (num == 3)
				{
					keep.Show(0);
					cout << endl;
					keep.Show(1);
					cout << endl;
					keep.Show(2);
					cout << endl;
				}
				else
				{
					keep.Show(num);
				}
				cout << endl << endl;
				break;
			case'6':
				keep.Write_F();
				break;
			case'7':
				keep.Dell_F();
				break;
			case'8':
				break;
			}
		}
		catch (const char* msg)
		{
			cout << endl << msg << endl;
		}
	}
	while (number != '8');

	
	

	system("pause");
	return 0;
}