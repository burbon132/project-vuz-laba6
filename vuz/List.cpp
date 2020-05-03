#include "List.h"
template<typename T>
List<T>::List()
{
	Size = 0;
	head = nullptr;
}
template<typename T>
List<T>::~List()
{

}
template<typename T>
T& List<T>::operator[](const int index)
{
		int counter = 0;

		Student* current = this->head;

		while (current != nullptr)
		{
			if (counter == index)
			{
				return current->Student;
			}
			current = current->pNext;
			counter++;
		}
}

template<typename T>
void List<T>::push_front(T student)
{
	head = new Student<T>(student, head);
	Size++;
}


template<typename T>
List<T>::Student::Student(char* Name = "Unknown", char* LastName = "Unknown", char* TrainingDirection = "Unknown", int NumberGroup = 0, Student* pNext = nullptr)
{
	this->Name = Name;
	this->LastName = LastName;
	this->TrainingDirection = TrainingDirection;
	this->NumberGroup = NumberGroup;
	this->pNext = pNext;
}
