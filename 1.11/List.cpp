#include "List.h"
#include<iostream>
#include<fstream>
using namespace std;
List::List(const List & other)
{
	Node* tmp = other.head;
	while (tmp != 0)
	{
		push_front(tmp->GetData());
		tmp = tmp->GetNext();
	}
}
List::~List()
{
	cout << "\ndestructor LIST\n\n";
	while (size)
	{
		pop();
	}
}
void List::pop() //front
{
	if (size > 0)
	{
		Node *temp = head;
		head = head->GetNext();
		delete temp;
		size--;
	}
	if (size == 0)
	{
		cout << ">>> —œ»—Œ  œ”—“Œ… " << endl;
	}
}
void List::push_front(int data)
{
	head = new Node(data, head);
	size++;
}
void List::push(int data)//push back
{
	if (size == 0)
	{
		head = new Node(data, nullptr);
	}
	if (size > 0)
	{
		Node *current = this->head;
		while (current->GetNext() != nullptr)
		{
			current = current->GetNext();
		}
		current->SetNext(new Node(data, nullptr));
	}
	size++;
}
void List::pop_back()
{
	if (size == 0)
	{
		cout << ">>> —œ»—Œ  œ”—“Œ… " << endl;
	}
	if (size > 0)
	{
		removeAt(size - 1);
	}
}
void List::clear()
{
	while (this->size)
	{
		this->pop();
	}
	cout << endl;
}
void List::show()
{
	if (size > 0)
	{
		cout << "¬ÓÚ ‚ÂÒ¸ ÒÔËÒÓÍ: ";
		Node *temp = head;
		while (temp != nullptr)
		{
			cout << temp->GetData() << " ";
			temp = temp->GetNext();
		}
	}
	else
	{
		cout << ">>> —œ»—Œ  œ”—“Œ… " << endl;
	}
	cout << endl;
}
void List::write_f()
{
	fstream fl;
	fl.open("List.txt", fstream::out);
	if (size > 0)
	{
		Node *temp = head;
		while (temp != nullptr)
		{
			fl << temp->GetData() << endl;
			temp = temp->GetNext();
		}
	}
	if (size == 0)
	{
		cout << " —œ»—Œ  œ”—“Œ… (ËÌÙÓÏ‡ˆËˇ ÌÂ Á‡ÔËÒ‡Ì‡) " << endl;
	}
	fl.close();
}
int & List::operator[](const int index)
{
	int counter = 0;
	Node *current = this->head;
	while (current != nullptr)
	{
		if (counter == index)
		{
			int ren = current->GetData();
			return ren;
		}
		current = current->GetNext();
		counter++;
	}
}
void List::insert(int data, int index)
{
	if (index > size)
	{
		throw "!!! Õ≈ Œ––≈ “Õ€… »Õƒ≈ — !!!";
		cout << endl;
	}
	else {
		if (index == 0)
		{
			push_front(data);
		}
		else
		{
			Node *previous = this->head;
			for (int i = 0; i < index - 1; i++)
			{
				previous = previous->GetNext();
			}
			Node *newNode = new Node(data, previous->GetNext());
			previous->SetNext(newNode);
			size++;
		}
	}
}
void List::removeAt(int index)
{
	if (index >= size)
	{
		throw "!!! Õ≈ Œ––≈ “Õ€… »Õƒ≈ — !!!";
		cout << endl;
	}
	else
	{
		if (index == 0)
		{
			pop();
		}
		else
		{
			Node *previous = this->head;
			for (int i = 0; i < index - 1; i++)
			{
				previous = previous->GetNext();
			}
			Node *toDelete = previous->GetNext();
			previous->SetNext(toDelete->GetNext());
			delete toDelete;
			size--;
		}
	}
}