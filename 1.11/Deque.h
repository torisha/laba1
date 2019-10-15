#pragma once
#include"Queue.h"
class Deque :
	public Queue//��������
{
private:
	Node* left;// ��� ����� next
	Node* right;
	int size;
public:
	Deque() : left(nullptr), right(0), size(0) { /*cout << "\nDEQUE\n\n";*/ }
	Deque(const Deque& other);
	~Deque();
	void pop() override;//pop front ����� next
	void push(int data) override;//push back
	void push_front(int data) override;
	void pop_back() override;
	void show() override;
	void clear() override;
	void write_f() override;

	void insert(int data, int index) override { cout << "\n\n!!! � ���� ��� ����� ������� !!!\n\n"; }
	void removeAt(int index) override{ cout << "\n\n!!! � ���� ��� ����� ������� !!!\n\n"; }
};
