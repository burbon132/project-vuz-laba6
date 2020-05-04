#pragma once
#ifndef _LIST_H_
#define _LIST_H_
#include "Student.h"
class List
{
public:
	List();
	~List();

	//�������� ������� �������� � ������
	void pop_front();

	//���������� �������� � ����� ������
	void push_back(Student student);

	// �������� ������
	void clear();

	// �������� ���������� ��������� � ������
	int GetSize() { return Size; }

	// ������������� �������� [] 
	Student& operator[](const int index);

	//���������� �������� � ������ ������
	void push_front(Student student);

	//�������� �������� � ������ �� ���������� �������
	void removeAt(int index);

	//�������� ���������� �������� � ������
	void pop_back();

	void Swap(List& lst, int index1, int index2);

private:
	class Node
	{
	public:
		Node* pNext;
		Student student;
		Node(Student student = Student(), Node* pNext = nullptr)
		{
			this->student = student;
			this->pNext = pNext;
		}
	};
	friend void SortList(List& lst);
	int Size;
	Node* head;
};
#endif // !_LIST_H_