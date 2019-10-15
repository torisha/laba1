#pragma once
#include"Node.h"
#include<iostream>
using namespace std;
//базовый абстрактный!
class Queue
{
private:
	int size;
	Node* first;
	Node* last;
protected:
	int GetSize() { return size; }
	Node* GetFirst() { return first; }
	Node* GetLast() { return last; }
	void SetFirst(Node* p) { first = p; }
	void SetLast(Node* w) { last = w; }
public:
	Queue() : size(0), first(nullptr), last(nullptr) { cout << "\nQUEUE\n\n"; }
	Queue(const Queue &other);
	virtual ~Queue();
	
	virtual void push(int data);//push back
	virtual void fill(int n);
	int& operator[](const int index);

	virtual void pop() ;//pop front
	virtual void show()=0;	
	virtual void clear()=0;
	virtual void push_front(int data);
	virtual void pop_back() = 0;
	virtual void write_f() = 0;

	virtual void insert(int data, int index) = 0;
	virtual void removeAt(int index) =0;


};