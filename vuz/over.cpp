#include "List.h"
 List& operator[](const int index)
{
	int counter = 0;

	List* current = this->head;

	while (current != nullptr)
	{
		if (counter == index)
		{
			return current->data;
		}
		current = current->pNext;
		counter++;
	}
}