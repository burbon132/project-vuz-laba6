#include "List.h"

List::List()
{
	Size = 0;
	head = nullptr;
}

List::~List()
{

}

void List::SetStudent(char* Name, char* LastName, char* TrainingDirection, int NumberGroup)
{
	this->head->Name = Name;
	this->head->LastName = LastName;
	this->head->TrainingDirection = TrainingDirection;
	this->head->NumberGroup = NumberGroup;
}



List::Student::Student(Student* student, Student *head)
{
	this->Name = student->Name;
	this->LastName = student->LastName;
	this->TrainingDirection = student->TrainingDirection;
	this->NumberGroup = student->NumberGroup;
	this->pNext = head->pNext;
}

void List::push_front(List::Student *student)
{
	head = new Student(student, head);
	Size++;
}


List::Student& List::operator[](const int index)
{
	int counter = 0;

	Student* current = this->head;
	while (current != nullptr)
	{
		if (counter == index)
		{
			return *current;
		}
		current = current->pNext;
		counter++;
	}
}


List::Student::Student(char* Name = "Unknown", char* LastName = "Unknown", char* TrainingDirection = "Unknown", int NumberGroup = 0, Student* pNext = nullptr)
{
	this->Name = Name;
	this->LastName = LastName;
	this->TrainingDirection = TrainingDirection;
	this->NumberGroup = NumberGroup;
	this->pNext = pNext;
}
