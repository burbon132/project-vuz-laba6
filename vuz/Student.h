#pragma once
#ifndef _STUDENT_H_
#define _STUDENT_H_
#include <fstream>
#include <iostream>
using namespace std;
struct Student
{
public:
	Student();
	Student(char* Name, char* LastName, char* TrainingDirection, int NumderGroup);

	void SetName(char* Name);
	void SetLastName(char* LastName);
	void SetTrainingDirection(char* TrainingDirection);
	void SetNumderGroup(int NumderGroup);
	
	char* GetName();
	char* GetLastName();
	char* GetTrainingDirection();
	int	  GetNumberGroup();

	friend ostream& operator<<(ostream& out, Student& student);

private:
	char* Name = new char[10]; // ��� �� 10 ��������
	char* LastName = new char[15]; // ������� �� 15 ��������
	char* TrainingDirection = new char[5]; // ����������� ���������� �� 5 ��������
	int   NumberGroup; // ����� ������
	
	class DataBir
	{
	public:
		int day;
		int month;
		int year;
	};

};
#endif  // !_STUDENT_H_