#pragma once
#ifndef _LIST_H_
#define _LIST_H_
template<typename T>
class List
{
public:
	List();
	~List();

	T& operator[](const int index);

	void push_front(T student);

	char* GetStudentName() { return Student.Name; }
	char* GetStudentLastName() { return Student.LastName; }
	char* GetStudentTrainingDirection() { return Student.TrainingDirection; }
	int GetStudentNumberGroup() { return Student.NumberGroup; }

private:
	struct Student
	{
		Student* pNext;
		char* Name = new char[10]; // ��� �� 10 ��������
		char* LastName = new char[15]; // ������� �� 15 ��������
		char* TrainingDirection = new char[5]; // ����������� ���������� �� 5 ��������
		int NumberGroup; // ����� ������
		Student(char* Name, char* LastName, char* TrainingDirection, int NumberGroup, Student* pNext);
		//class DataBir; ����� �������� ���������� ��������� ���� ��������
	};
	int Size;
	Student* head;
};
#endif // !_LIST_H_