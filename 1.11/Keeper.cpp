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

void Keeper::Write()
{
	for (int i = 0; i < 3; i++)
	{
		keeper[i]->write_f();
	}
	cout << endl << ">>> Инфа была записана в файлы <<<" << endl << endl;
}

void Keeper::Dell()
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

void Keeper::Read()
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

/*void Keeper::create_el()
{
	//сначала спросить будем ли мы загружать данные из файла или создадим новые
	int num = 0;
	int num2 = 0;
	int w = 0;
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
		cout << "Что создать?" << endl << "1) лист" << endl << "2) дек" << endl << "3) стек" << endl;
		cin >> num2;
		if (num2 != 1 && num2 != 2 && num2 != 3)
		{
			throw "!!! НЕКОРРЕКТНАЯ КОМАНДА !!!";
			cout << endl << endl;
		}
		if (num2 == 1)
		{
			cout << "Введите размер: ";
			cin >> w;
			cout << endl;
			l->fill(w);
		}
		if (num2 == 2)
		{
			cout << "Введите размер: ";
			cin >> w;
			cout << endl;
			d->fill(w);
		}
		if (num2 == 3)
		{
			cout << "Введите размер: ";
			cin >> w;
			cout << endl;
			s->fill(w);
		}
		this->write();//записывам все в файлы
	}
	if (num == 2)
	{
		this->read();
		//читаем все файлы
	}
}
void Keeper::show_el()
{
	int num = 0;
	cout << "Что показать?" << endl << "1) лист" << endl << "2) дек" << endl << "3) стек" << endl;
	cout << "4) всё!!!" << endl;
	cin >> num;
	if (num != 1 && num != 2 && num != 3 && num != 4)
	{
		throw "!!! НЕКОРРЕКТНАЯ КОМАНДА !!!";
		cout << endl << endl;
	}
	if (num == 1)
	{
		l->show();
		cout << endl;
	}
	if (num == 2)
	{
		d->show();
		cout << endl;
	}
	if (num == 3)
	{
		s->show();
		cout << endl;
	}
	if (num == 4)
	{
		l->show();
		d->show();
		s->show();
		cout << endl;
	}
}
void Keeper::dell_el()
{
	int num = 0;
	cout << "Что удалить?" << endl << "1) лист" << endl << "2) дек" << endl << "3) стек" << endl;
	cout << "4) всё!" << endl;
	cin >> num;
	if (num != 1 && num != 2 && num != 3 && num != 4)
	{
		throw "!!! НЕКОРРЕКТНАЯ КОМАНДА !!!";
		cout << endl << endl;
	}
	if (num == 1)
	{
		l->clear();
		l->show();
		cout << endl;
	}
	if (num == 2)
	{
		d->clear();
		d->show();
		cout << endl;
	}
	if (num == 3)
	{
		s->clear();
		s->show();
		cout << endl;
	}
	if (num == 4)
	{
		l->clear();
		d->clear();
		s->clear();
		cout << ">>> Информация стерта" << endl;
	}
	//this->write();
}
void Keeper::edit()
{
	int dat = 0;
	int cnt = 0;
	int num = 0;
	int cnt2 = 0;
	cout << "С чем будем работать?" << endl;
	cout << "1 - Дек " << endl;
	cout << "2 - Стек" << endl;
	cout << "3 - Список" << endl;
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
		d->show();
		cout << "1 Добавить элемент в начало дека" << endl;
		cout << "2 Извлечь элемент из начала дека" << endl;
		cout << "3 Добавить элемент в конец дека" << endl;
		cout << "4 Извлечь элемент из конца дека" << endl;
		cout << "Выберете действие: ";
		cin >> cnt;
		cout << endl;
		if (cnt == 1)
		{
			cout << "Введите элемент: ";
			cin >> dat;
			cout << endl;
			d->push_front(dat);
			d->show();
		}
		if (cnt == 2)
		{
			d->pop();
			cout << "Элемент был извлечен!" << endl;
			d->show();
		}
		if (cnt == 3)
		{
			cout << "Введите элемент: ";
			cin >> dat;
			cout << endl;
			d->push(dat);
			d->show();
		}
		if (cnt == 4)
		{
			d->pop_back();
			cout << "Элемент был извлечен!" << endl;
			d->show();
		}
	}
	if (num == 2)
	{
		s->show();
		cout << "1 Добавить элемент в стек " << endl;
		cout << "2 Извлечь элемент из стека" << endl;
		cout << "Выберете действие: ";
		cin >> cnt;
		cout << endl;
		if (cnt == 1)
		{
			cout << "Введите элемент: ";
			cin >> dat;
			cout << endl;
			s->push(dat);
			s->show();
		}
		if (cnt == 2)
		{
			s->pop();
			cout << "Элемент был извлечен!" << endl;
			s->show();
		}
	}
	if (num == 3)
	{
		l->show();
		cout << "1 Добавить элемент по индексу" << endl;
		cout << "2 Извлечь элемент по индексу" << endl;
		cout << "Выберете действие: ";
		cin >> cnt;
		cout << endl;
		if (cnt == 1)
		{
			cout << "Введите элемент для добавления: ";
			cin >> dat;
			cout << endl;
			cout << "Введите индекс: ";
			cin >> cnt2;
			cout << endl;
			l->insert(dat, cnt2);
			l->show();
		}
		if (cnt == 2)
		{
			cout << "Введите индекс элемента для удаления: ";
			cin >> dat;
			cout << endl;
			l->removeAt(dat);
			l->show();
		}
	}
	this->write();//обновляем инфу в файле
}
void Keeper::write()
{
	//записывает все!!
	d->write_f();
	l->write_f();
	s->write_f();
	cout << endl << ">>> Инфа была записана в файлы <<<" << endl << endl;
}
void Keeper::read()
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
		while (fd >> buff)
		{
			d->push(buff);
		}
		d->show();
		while (fl >> buff2)
		{
			l->push(buff2);
		}
		l->show();
		while (fs >> buff3)
		{
			s->push(buff3);
		}
		s->show();
	}
	fl.close();
	fs.close();
	fd.close();
}
void Keeper::dell()
{
	fstream f;
	f.open("List.txt", fstream::out | fstream::trunc);
	f.close();
	f.open("Deque.txt", fstream::out | fstream::trunc);
	f.close();
	f.open("Stack.txt", fstream::out | fstream::trunc);
	f.close();
	cout << ">>> Вся информация была стерта из файлов <<<" << endl;
}*/
