#pragma once
#ifndef _LIST_H_
#define _LIST_H_
#include "Student.h"
class List
{
public:
	List();
	~List();

	//удаление первого элемента в списке
	void pop_front();

	//добавление элемента в конец списка
	void push_back(Student student);

	// очистить список
	void clear();

	// получить количество елементов в списке
	int GetSize() { return Size; }

	// перегруженный оператор [] 
	Student& operator[](const int index);

	//добавление элемента в начало списка
	void push_front(Student student);

	//удаление элемента в списке по указанному индексу
	void removeAt(int index);

	//удаление последнего элемента в списке
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