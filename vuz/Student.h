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
	Student(char* Name, char* LastName, char* TrainingDirection, int NumderGroup, int day, int month, int year);

	void SetName(char* Name);
	void SetLastName(char* LastName);
	void SetTrainingDirection(char* TrainingDirection);
	void SetNumderGroup(int NumderGroup);
	void SSetDay(int day);
	void SSetMonth(int month);
	void SSetYear(int year);
	
	char* GetName();
	char* GetLastName();
	char* GetTrainingDirection();
	int	  GetNumberGroup();
	int	  GGetDay();
	int	  GGetMonth();
	int	  GGetYear();

	friend ostream& operator<<(ostream& out, Student& student);
	
protected:
	char* Name = new char[10]; // Имя из 10 символов
	char* LastName = new char[15]; // Фамилия из 15 символов
	char* TrainingDirection = new char[4]; // Направление подготовки из 5 символов
	int   NumberGroup; // номер группы

	class DataBir
	{
	public:
		int	 GetDay();
		int	 GetMonth();
		int	 GetYear();

		void SetDay(int day);
		void SetMonth(int month);
		void SetYear(int year);

		DataBir();
		DataBir(int day, int month, int year);
	private:
		int day;
		int month;
		int year;
	};
	DataBir BD;
};
#endif  // !_STUDENT_H_