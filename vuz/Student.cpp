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
	this->BD = 
		//Student::DataBir::DataBir(day, month, year);
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
	out << "Student:" << endl << student.GetLastName() << endl << student.GetName() << endl << student.GetTrainingDirection() << endl << student.GetNumberGroup() << endl <<  << endl;
	return out;
}


