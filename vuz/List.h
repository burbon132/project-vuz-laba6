#pragma once
#ifndef _LIST_H_
#define _LIST_H_

class List
{
private:
	struct Student
	{
		Student* pNext;
		char* Name = new char[10]; // ��� �� 10 ��������
		char* LastName = new char[15]; // ������� �� 15 ��������
		char* TrainingDirection = new char[5]; // ����������� ���������� �� 5 ��������
		int NumberGroup; // ����� ������
		Student(char* Name, char* LastName, char* TrainingDirection, int NumberGroup, Student* pNext);
		Student(Student* student, Student *head);
		char* GetStudentName() { return Name; }
		char* GetStudentLastName() { return LastName; }
		char* GetStudentTrainingDirection() { return TrainingDirection; }
		int GetStudentNumberGroup() { return NumberGroup; }
		
		//class DataBir; ����� �������� ���������� ��������� ���� ��������
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