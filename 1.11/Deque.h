#pragma once
#include"Queue.h"
class Deque :
	public Queue//базовыый
{
private:
	Node* left;// всеё через next
	Node* right;
	int size;
public:
	Deque() : left(nullptr), right(0), size(0) {}
	Deque(const Deque& other);
	~Deque();
	void pop() override;//pop front через next
	void push(int data) override;//push back
	void push_front(int data) override;
	void pop_back() override;
	void show() override;
	void clear() override;
	void write_f() override;
};
