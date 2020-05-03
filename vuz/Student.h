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
	char* Name = new char[10]; // Имя из 10 символов
	char* LastName = new char[15]; // Фамилия из 15 символов
	char* TrainingDirection = new char[5]; // Направление подготовки из 5 символов
	int   NumberGroup; // номер группы
	
	class DataBir
	{
	public:
		int day;
		int month;
		int year;
	};

};
#endif  // !_STUDENT_H_