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
	Student(char* Name, char* LastName, char* TrainingDirection, int NumberGroup, int day, int month, int year);
	Student(char* Name, char* LastName, char* TrainingDirection, int NumberGroup, int day, int month, int year, int q);

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
	char* Name = new char[15]; // ��� �� 15 ��������
	char* LastName = new char[15]; // ������� �� 15 ��������
	char* TrainingDirection = new char[5]; // ����������� ���������� �� 5 ��������
	int   NumberGroup; // ����� ������

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