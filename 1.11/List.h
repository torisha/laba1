#pragma once
#include"Queue.h"
class List :
	public Queue
{
private:
	int size;
	Node* head;
public:
	List() : head(nullptr), size(0) {/* cout << "\nLIST\n\n";*/ }
	List(const List& other);
	~List();
	void pop() override;
	void push_front(int data) override;
	void push(int data) override;
	void pop_back() override;
	void clear() override;
	void show() override;
	void write_f() override;
	int GetSize() { return size; }

	// перегруженный оператор []
	int& operator[](const int index);

	//добавление элемента в список по указанному индексу
	void insert(int data, int index) override;

	//удаление элемента в списке по указанному индексу
	void removeAt(int index) override;
};