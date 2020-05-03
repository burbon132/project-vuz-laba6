#pragma once
#ifndef _LIST_H_
#define _LIST_H_
class List
{
public:
	List();
	~List();
private:
	struct Student
	{
		Student* pNext;
		char* Name = new char[10]; // Имя из 10 символов
		char* LastName = new char[15]; // Фамилия из 15 символов
		char* TrainingDirection = new char[5]; // Направление подготовки из 5 символов
		int NumberGroup; // номер группы
		Student(char* Name, char* LastName, char* TrainingDirection, int NumberGroup, Student* pNext);
		//class DataBir; НУЖНО ДОБАВИТЬ ФУНКЦИОНАЛ СРАВНЕНИЯ ДАТЫ РОЖДЕНИЯ
	};
	int Size;
	Student* head;
};
#endif // !_LIST_H_