#include "Stack.h"
#include<iostream>
#include<fstream>
#include<time.h>
Stack::Stack(const Stack & other)
{
	Node* temp1 = other.last;
	int sz = other.size;
	for (int i = sz; i > 0; i--)
	{
		temp1 = other.last;
		for (int j = i - 1; j > 0; j--)//доходим до последнего
		{
			temp1 = temp1->GetNext();
		}
		this->push(temp1->GetData());
	}
}
Stack::~Stack()
{
	while (size)
	{
		pop();//pop back
	}
}
void Stack::pop()
{
	if (size > 1)
	{
		Node *b = last;//сохраняем указатель на последний
		last = b->GetNext();//бывший предпоследний становится последним
		delete b;//удаляем наш последний
		size--;
	}
	else if (size == 1)
	{
		Node *b = last;//сохраняем указатель на последний
		last = nullptr;
		delete b;
		size--;
	}
	else
	{
		cout << ">>> СТЕК ПУСТОЙ " << endl;;
	}
}
void Stack::push(int n)
{
	if (size > 0)
	{
		Node *temp = last;
		last = new Node(n, last);
		size++;
	}
	if (size == 0)
	{
		last = new Node(n, nullptr);
		size++;
	}
}
void Stack::show()
{
	if (size > 0)
	{
		Node *temp = last;
		int number = size - 1;
		cout << "Вот весь стек: ";
		for (int i = 0; i < size; i++)
		{
			temp = last;
			for (int i = 0; i < number; i++)
			{
				temp = temp->GetNext();
			}
			number--;
			cout << temp->GetData() << " ";
		}
	}
	else
	{
		cout << ">>> СТЕК ПУСТОЙ " << endl;
	}
}
void Stack::clear()
{
	while (this->size)
	{
		this->pop();
	}
	cout << endl;
}
void Stack::write_f()
{
	fstream fs;
	fs.open("Stack.txt", fstream::out);
	if (size > 0)
	{
		Node *temp = last;
		int number = size - 1;
		for (int i = 0; i < size; i++)
		{
			temp = last;
			for (int i = 0; i < number; i++)
			{
				temp = temp->GetNext();
			}
			number--;
			fs << temp->GetData() << endl;
		}
	}
	else
	{
		cout << " СТЕК ПУСТОЙ (информация не записана) " << endl;
	}
	fs.close();
}