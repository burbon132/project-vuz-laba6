#include "Student.h"

Student::Student()
{
	this->Name = "Unknown";
	this->LastName = "Unknown";
	this->TrainingDirection = "Unknown";
	this->NumberGroup = 0;
	Student::DataBir::DataBir();
}

Student::Student(char* Name, char* LastName, char* TrainingDirection, int NumderGroup, int day, int month, int year)
{
	this->Name = Name;
	this->LastName = LastName;
	this->TrainingDirection = TrainingDirection;
	this->NumberGroup = NumderGroup;
	BD.SetDay(day);
	BD.SetMonth(month);
	BD.SetYear(year);
}

Student::Student(char* Name, char* LastName, char* TrainingDirection, int NumderGroup, int day, int month, int year, int q)
{
	char* arrN = new char[strlen(Name) + 1];
	for (int i = 0; i < strlen(Name) + 1; i++)	{	arrN[i] = Name[i];	}
	char* arrLN = new char[strlen(LastName) + 1];
	for (int i = 0; i < strlen(LastName) + 1; i++)	{	arrLN[i] = LastName[i];	}
	char* arrTD = new char[strlen(TrainingDirection) + 1];
	for (int i = 0; i < strlen(TrainingDirection) + 1; i++) {	arrTD[i] = TrainingDirection[i];	}
	this->Name = arrN;
	this->LastName = arrLN;
	this->TrainingDirection = arrTD;
	this->NumberGroup = NumderGroup;
	BD.SetDay(day);
	BD.SetMonth(month);
	BD.SetYear(year);
}

Student::DataBir::DataBir()
{
	this->day = 1;
	this->month = 1;
	this->year = 1970;
}

Student::DataBir::DataBir(int day, int month, int year)
{
	this->day = day;
	this->month = month;
	this->year = year;
}

//////////////////////////////////////////////////////////////SETTERS/////////////////////////////////////////////////////////////////

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

void Student::SSetDay(int day)
{
	this->BD.SetDay(day);
}

void Student::SSetMonth(int month)
{
	this->BD.SetDay(month);
}

void Student::SSetYear(int year)
{
	this->BD.SetDay(year);
}

void Student::DataBir::SetDay(int day)
{
	this->day = day;
}

void Student::DataBir::SetMonth(int month)
{
	this->month = month;
}

void Student::DataBir::SetYear(int year)
{
	this->year = year;
}

//////////////////////////////////////////////////////////////GETTERS/////////////////////////////////////////////////////////////////

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

int Student::GGetDay()
{
	return BD.GetDay();
}

int Student::GGetMonth()
{
	return BD.GetMonth();
}

int Student::GGetYear()
{
	return BD.GetYear();
}

int Student::DataBir::GetDay()
{
	return this->day;
}

int Student::DataBir::GetMonth()
{
	return this->month;
}

int Student::DataBir::GetYear()
{
	return this->year;
}

/////////////////////////////////////////////////////////////OPERATORS/////////////////////////////////////////////////////////////////

ostream& operator<<(ostream& out,Student &student)
{
	out << "Студент:" << endl << student.GetLastName() << endl << student.GetName() << endl << student.GetTrainingDirection() << endl << student.GetNumberGroup() << endl << student.BD.GetDay() << "." << student.BD.GetMonth() << "." << student.BD.GetYear() << endl << endl;
	return out;
}