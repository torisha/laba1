#pragma once
#include"Queue.h"
#include<iostream>
using namespace std;
class Stack :
	public Queue
{
private:
	int size;
	Node *last;//last через прев
protected:
	void push_front(int data) override { cout << "\n\n!!! В стеке нет такой функции !!!\n\n"; };
	void pop_back() override { cout << "\n\n!!! В стеке нет такой функции !!!\n\n"; };
	void SetLast(Node* n) { last = n; }
	Node* GetLast() { return last; }
public:
	Stack() : size(0), last(nullptr) { /*cout << "\nSTACK\n\n";*/ }
	Stack(const Stack &other);
	~Stack();
	void pop() override;//pop back
	void push(int n) override;//push back
	//void show_last() { cout << this->last->GetData(); }
	void show() override;
	void clear() override;
	void write_f() override;

	void insert(int data, int index) override { cout << "\n\n!!! В стеке нет такой функции !!!\n\n"; }
	void removeAt(int index) override { cout << "\n\n!!! В стеке нет такой функции !!!\n\n"; }
};