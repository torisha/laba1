#include "Queue.h"
#include<iostream>
using namespace std;

Queue::Queue(const Queue & other)
{
	Node* tmp = other.last;
	while (tmp != 0)
	{
		push_front(tmp->GetData());
		tmp = tmp->GetNext();
	}
}
Queue::~Queue()
{
	cout << "\ndestructor QUEUE\n\n";
	while (size)
	{
		pop();
	}
}

void Queue::push(int data)
{
	if (size > 1)
	{
		Node *temp = last;
		last = new Node(data, last);
	}
	else if (size == 1)
	{
		last = new Node(data, first);
	}
	else
	{
		first = last = new Node(data, 0);
		first->SetNext(0);
	}
	size++;
}

void Queue::fill(int n)
{
	for (int i = 0; i < n; i++)
	{
		this->push(rand() % 101);
	}
	cout << endl;
}

int & Queue::operator[](const int index)
{
	if (this->GetSize() == 0)
	{
		cout << "\nосярн\n";
	}
	if (this->GetSize() > 0)
	{
		int counter = 0;
		Node *current = this->first;
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
	
}

void Queue::pop()
{
	if (size == 0)
	{
		cout << ">>> нвепедэ осярю " << endl;
	}
	if (size > 1)
	{
		Node *a = first;
		Node *b = last;
		int counter = size - 1;
		while (counter - 1)
		{
			b = b->GetNext();
			counter--;
		}
		first = b;
		first->SetNext(0);
		delete a;
		this->size--;
	}
}

void Queue::push_front(int data)
{
	if (size > 1)
	{
		Node *temp = first;
		first = new Node(data, 0);
		temp->SetNext(first);
	}
	else if (size == 1)
	{
		Node *temp = first;
		first = new Node(data, 0);
		last->SetNext(first);
	}
	else
	{
		first = last = new Node(data, 0);
		first->SetNext(0);
	}
	size++;
}
