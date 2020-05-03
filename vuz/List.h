#pragma once
#ifndef _LIST_H_
#define _LIST_H_

class List
{
private:
	struct Student
	{
		Student* pNext;
		char* Name = new char[10]; // Имя из 10 символов
		char* LastName = new char[15]; // Фамилия из 15 символов
		char* TrainingDirection = new char[5]; // Направление подготовки из 5 символов
		int NumberGroup; // номер группы
		Student(char* Name, char* LastName, char* TrainingDirection, int NumberGroup, Student* pNext);
		Student(Student* student, Student *head);
		char* GetStudentName() { return Name; }
		char* GetStudentLastName() { return LastName; }
		char* GetStudentTrainingDirection() { return TrainingDirection; }
		int GetStudentNumberGroup() { return NumberGroup; }
		
		//class DataBir; НУЖНО ДОБАВИТЬ ФУНКЦИОНАЛ СРАВНЕНИЯ ДАТЫ РОЖДЕНИЯ
	};
	int Size;
	Student* head;
public:
	List();
	~List();
	void SetStudent(char* Name, char* LastName, char* TrainingDirection, int NumberGroup);
	Student& operator[](const int index);
	void push_front(List::Student* student);	
};
#endif // !_LIST_H_