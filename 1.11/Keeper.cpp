#include"Keeper.h"
#include"Node.h"
#include"Queue.h"
#include"Deque.h"
#include"List.h"
#include"Stack.h"
#include<fstream>
Keeper::Keeper()
{
	cout << "\n KEEPER\n\n";
	l = new List;
	s = new Stack;
	d = new Deque;
	keeper[0] = l;
	keeper[1] = s;
	keeper[2] = d;
}
Keeper::~Keeper()
{
	cout << "\ndestructor KEEPER\n";
	delete l;
	delete s;
	delete d;
}

void Keeper::Write_F()
{
	for (int i = 0; i < 3; i++)
	{
		keeper[i]->write_f();
	}
	cout << endl << ">>> Инфа была записана в файлы <<<" << endl << endl;
}

void Keeper::Dell_F()
{
	fstream f;
	f.open("List.txt", fstream::out | fstream::trunc);
	f.close();
	f.open("Deque.txt", fstream::out | fstream::trunc);
	f.close();
	f.open("Stack.txt", fstream::out | fstream::trunc);
	f.close();
	cout << ">>> Вся информация была стерта из файлов <<<" << endl;
}

void Keeper::Read_F()
{
	int buff = 0;
	int buff2 = 0;
	int buff3 = 0;
	fstream fd;
	fstream fl;
	fstream fs;
	fd.open("Deque.txt", fstream::in);
	fl.open("List.txt", fstream::in);
	fs.open("Stack.txt", fstream::in);
	if (!fd.is_open() || !fs.is_open() || !fl.is_open())
	{
		throw "!!! Ошибка открытия файла !!!";
	}
	else
	{
		while (fl >> buff2)
		{
			keeper[0]->push(buff2);
		}
		keeper[0]->show();
		while (fs >> buff3)
		{
			keeper[1]->push(buff3);
		}
		keeper[1]->show();
		while (fd >> buff)
		{
			keeper[2]->push(buff);
		}
		keeper[2]->show();
	}
	fl.close();
	fs.close();
	fd.close();
}


