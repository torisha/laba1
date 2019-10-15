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
		cout << "*********����**********" << endl << endl;
		cout << "1) ������� ��������� " << endl << endl;
		cout << "2) ������� ��� ��������" << endl << endl;

		cout << "3) �������� �������" << endl<<endl;
		cout << "4) ������� �������" << endl<<endl;
		cout << "5) ������� �� �����" << endl << endl;

		cout << "6) �������� � �����" << endl << endl;
		cout << "7) �������� �����" << endl << endl;
		cout << "8) �����" << endl << endl;
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
				cout << "��� ����� ��������?" << endl;
				cout << "1 - ������� ����� ������" << endl;
				cout << "2 - ��������� ������ �� �����" << endl;
				cout << "������� �������: ";
				cin >> num;
				cout << endl;
				if (num != 1 && num != 2 && num != 3)
				{
					throw "!!! ������������ ������� !!!";
					cout << endl << endl;
				}
				if (num == 1)
				{
					cout << "��� �������?" << endl << "0 ����" << endl << "1 ����" << endl << "3 ���" << endl;
					cin >> num2;
					if (num2 != 1 && num2 != 2 && num2 != 0)
					{
						throw "!!! ������������ ������� !!!";
						cout << endl << endl;
					}
					else
					{
						cout << "������� ������: ";
						cin >> w;
						cout << endl;
						keep.Fill(num2, w);
					}
				}

				if (num == 2)
				{
					keep.Read_F();
					//������ ��� �����
				}
				cout << endl << endl;
				break;
			case'2':
				cout << "��� ��������?" << endl << "0 ����" << endl << "1 ����" << endl << "2 ���" << endl;
				cout << "3 ��!" << endl;
				cin >> num;
				if (num != 1 && num != 2 && num != 3 && num != 4)
				{
					throw "!!! ������������ ������� !!!";
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
				cout << ">>> ���������� ������" << endl;
				cout << endl << endl;
				break;
			case'3':
				cout << ">>> �������� �������:" << endl;
				cout << "1 � ������ " << endl;
				cout << "2 � ����� " << endl;
				cout << "3 �� �������" << endl;
				cout << "�������� ��������: ";
				cin >> w;
				cout << endl;

				keep.Show(0);
				cout << endl;
				keep.Show(1);
				cout << endl;
				keep.Show(2);
				cout << endl;

				cout << "� ��� ����� ��������?" << endl;
				cout << "0 - ������ " << endl;
				cout << "1 - ����" << endl;
				cout << "2 - ���" << endl;
				cout << "������� �������: ";
				cin >> num;

				cout << endl;
				cout << "������� �������:";
				cin >> dat;
				cout << endl << endl;

				if (num != 1 && num != 2 && num != 0)
				{
					throw "!!! ������������ ������� !!!";
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
					cout << "������� ������ ��������, ����� �������� ������� �����:";
					cin >> num2;
					keep.InsertAt(dat, num2, num);
				}
				cout << "\n>>> ���������\n";
				keep.Show(num);
				cout << endl << endl;
				break;
			case'4':
				cout << ">>> ������� �������:" << endl;
				cout << "1 �� ������ " << endl;
				cout << "2 �� ����� " << endl;
				cout << "3 �� �������" << endl;
				cout << "�������� ��������: ";
				cin >> w;
				cout << endl;
				keep.Show(0);
				cout << endl;
				keep.Show(1);
				cout << endl;
				keep.Show(2);
				cout << endl;
				cout << "� ��� ����� ��������?" << endl;
				cout << "0 - ������ " << endl;
				cout << "1 - ����" << endl;
				cout << "2 - ���" << endl;
				cout << "������� �������: ";
				cin >> num;
				if (num != 1 && num != 2 && num != 0)
				{
					throw "!!! ������������ ������� !!!";
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
					
						cout << "������� ������ �������� ��� ��������:";
						cin >> num2;
						keep.RemAt(num2, num);
					
				}
				cout << "\n>>> ���������\n";
				keep.Show(num);
				cout << endl;
				
				cout << endl << endl;

				cout << endl << endl;
				break;
			case'5':
				cout << "��� ��������?" << endl << "0 ����" << endl << "1 ����" << endl << "2 ���" << endl;
				cout << "3 ��!!!" << endl;
				cin >> num;
				if (num != 1 && num != 2 && num != 3 && num != 0)
				{
					throw "!!! ������������ ������� !!!";
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