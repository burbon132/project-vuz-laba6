#include "List.h"

List::List()
{
	Size = 0;
	head = nullptr;
}

List::~List()
{

}

List::Student::Student(char* Name = "Unknown", char* LastName = "Unknown", char* TrainingDirection = "Unknown", int NumberGroup = 0, Student* pNext = nullptr)
{
	this->Name = Name;
	this->LastName = LastName;
	this->TrainingDirection = TrainingDirection;
	this->NumberGroup = NumberGroup;
	this->pNext = pNext;
}
