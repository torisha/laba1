#pragma once
#include"Queue.h"
//работает с производными объектами абстрактного класса Base
/*
добавление и удаление производных объектов абстрактного класса Base
полное сохранение себя в файле;
полное восстановление себя из файла.
*/
class Keeper
{
private:
	Queue* l;
	Queue* s;
	Queue* d;

	Queue* keeper[3];
	
public:
	
	Keeper();
	~Keeper();

	void PushBack(int dat, int n) //dat это данные, n это номер структуры с которой работаем
	{	
			keeper[n]->push(dat);	
	}

	void PushFront(int dat, int n)
	{
		keeper[n]->push_front(dat);
	}

	void InsertAt(int dat, int index, int n)
	{
		keeper[n]->insert(dat, index);
	}

	void RemAt(int index, int n)
	{
		keeper[n]->removeAt(index);
	}

	void PopFront(int n)
	{
		keeper[n]->pop();
	}

	void PopBack(int n)
	{
		keeper[n]->pop_back();
	}

	void Show(int n)
	{
		keeper[n]->show();		
	}

	void Clear(int n)
	{
		keeper[n]->clear();
	}

	

	void Fill(int n, int quantity)
	{
		keeper[n]->fill(quantity);	
	}
	
	void Write_F();//записывает все в файлы
	void Dell_F(); //очищает файлы
	void Read_F();


	
};
