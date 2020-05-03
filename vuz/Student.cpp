#include "Student.h"


Student::Student()
{
	this->Name = "Unknown";
	this->LastName = "Unknown";
	this->TrainingDirection = "Unknown";
	this->NumberGroup = 0;
}

Student::Student(char* Name, char* LastName, char* TrainingDirection, int NumderGroup)
{
	this->Name = Name;
	this->LastName = LastName;
	this->TrainingDirection = TrainingDirection;
	this->NumberGroup = NumderGroup;
}

void Student::SetName(char* Name)
{
	this->Name = Name;
}

void Student::SetLastName(char* LastName)
{
	this->LastName = LastName;
}

void Student::SetTrainingDirection(char* TrainingDirection)
{
	this->TrainingDirection = TrainingDirection;
}

void Student::SetNumderGroup(int NumderGroup)
{
	this->NumberGroup = NumberGroup;
}

char* Student::GetName()
{
	return this->Name;
}

char* Student::GetLastName()
{
	return this->LastName;
}

char* Student::GetTrainingDirection()
{
	return this->TrainingDirection;
}

int Student::GetNumberGroup()
{
	return this->NumberGroup;
}

ostream& operator<<(ostream& out,Student &student)
{
	out << "Student:" << endl << student.GetLastName() << endl << student.GetName() << endl << student.GetTrainingDirection() << endl << student.GetNumberGroup() << endl << endl;
	return out;
}


