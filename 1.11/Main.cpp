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
		cout << "*********����**********" << endl << endl;
		cout << "1) ������� ���������" << endl << endl;
		cout << "2) ������������� ������" << endl << endl;
		cout << "3) ����� �� �����" << endl << endl;
		cout << "4) ������� ���������" << endl << endl;
		cout << "5) �������� �����" << endl << endl;
		cout << "5) �����" << endl << endl;
		cout << "***********************" << endl << endl;
		cout << "������� �������: ";
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