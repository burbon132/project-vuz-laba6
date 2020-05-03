#pragma once
#ifndef _STUDENT_H_
#define _STUDENT_H_
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

	Student& Student::operator<<(const int index);

private:
	char* Name = new char[10]; // ��� �� 10 ��������
	char* LastName = new char[15]; // ������� �� 15 ��������
	char* TrainingDirection = new char[5]; // ����������� ���������� �� 5 ��������
	int   NumberGroup; // ����� ������
	
	/*
	class DataBir; ����� �������� ���������� ��������� ���� ��������
	*/

};
#endif  // !_STUDENT_H_