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
	char* Name = new char[10]; // Èìÿ èç 10 ñèìâîëîâ
	char* LastName = new char[15]; // Ôàìèëèÿ èç 15 ñèìâîëîâ
	char* TrainingDirection = new char[5]; // Íàïðàâëåíèå ïîäãîòîâêè èç 5 ñèìâîëîâ
	int   NumberGroup; // íîìåð ãðóïïû
	
	/*
	class DataBir; ÍÓÆÍÎ ÄÎÁÀÂÈÒÜ ÔÓÍÊÖÈÎÍÀË ÑÐÀÂÍÅÍÈß ÄÀÒÛ ÐÎÆÄÅÍÈß
	*/

};
#endif  // !_STUDENT_H_