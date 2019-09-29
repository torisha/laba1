#include "Deque.h"
#include<iostream>
#include<fstream>
using namespace std;
Deque::Deque(const Deque & other)
{
	Node* tmp = other.left;
	while (tmp != nullptr)
	{
		push(tmp->GetData());
		tmp = tmp->GetNext();
	}
}
Deque::~Deque()
{
	while (size)
	{
		pop();//pop back
	}
}
void Deque::pop()//pop front
{
	if (size > 0)
	{
		Node * tmp2 = left;
		left = tmp2->GetNext();
		delete tmp2;
		size--;
	}
	else
	{
		cout << ">>> ДЕК ПУСТОЙ " << endl;
	}
}
void Deque::push(int data)//push back
{
	if (size > 0)
	{
		Node *temp = this->right;
		temp->SetNext(new Node(data, nullptr));
		right = temp->GetNext();
	}
	else //cписок пустой
	{
		left = new Node(data, nullptr);
		right = left;//?????
	}
	size++;
}
void Deque::push_front(int data)
{
	if (size > 0)
	{
		left = new Node(data, left);
		//
	}
	else//empty
	{
		left = new Node(data, nullptr);
		right = left;//????
	}
	size++;
}
void Deque::pop_back()
{
	if (size > 1)
	{
		Node *tmp = left;
		for (int i = 1; i < size - 1; i++)
		{
			tmp = tmp->GetNext();
		}
		Node *toDelete = right;
		//tmp->SetNext(toDelete->GetNext());
		right = tmp;
		right->SetNext(nullptr);
		delete toDelete;
		size--;
	}
	else if (size == 1)
	{
		this->pop();//pop front
	}
	else
	{
		cout << ">>> ДЕК ПУСТОЙ " << endl;
	}
}
void Deque::show()
{
	if (size > 0)
	{
		cout << "Вот весь дек: ";
		Node *temp = left;
		while (temp != nullptr)
		{
			cout << temp->GetData() << " ";
			temp = temp->GetNext();
		}
	}
	else
	{
		cout << ">>> ДЕК ПУСТОЙ " << endl;
	}
	cout << endl;
}
void Deque::clear()
{
	while (this->size)
	{
		this->pop();
	}
	cout << endl;
}
void Deque::write_f()
{
	fstream fd;
	fd.open("Deque.txt", fstream::out);
	if (size > 0)
	{
		//cout << "Вот весь дек: ";
		Node *temp = left;
		while (temp != nullptr)
		{
			fd << temp->GetData() << endl;
			temp = temp->GetNext();
		}
	}
	else
	{
		cout << " ДЕК ПУСТОЙ (информация не записана) " << endl;;
	}
	fd.close();
}