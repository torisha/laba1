#pragma once
class Node
{
private:
	int data;
	Node* next;//���������� � �������� next ��� prev � ����������� �� ������
public:
	Node() : data(0), next(nullptr) {}
	Node(int d, Node* n) { data = d; next = n; }
	~Node() {}

	int GetData() { return data; }
	Node* GetNext() { return next; }

	void SetData(int d) { data = d; }
	void SetNext(Node* n) { next = n; }
};
