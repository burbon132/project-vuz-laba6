#include "Functions.h"

void Compare(List& lst, char* TrainingDirection)
{
	for (int i = 0; i < lst.GetSize(); i++) {
		if (lst[i].GetTrainingDirection() == TrainingDirection) {
			cout << lst[i];
		}
	}
}

void Compare(List& lst, List& newlst, char* TrainingDirection, int GroupNumber)
{
	for (int i = 0; i < lst.GetSize(); i++) 
	{
		if ((lst[i].GetTrainingDirection() == TrainingDirection)&&(lst[i].GetNumberGroup() == GroupNumber)) {
			newlst.push_front(lst[i]);
		}
	}
	for (int i = 0; i < newlst.GetSize(); i++) {
		cout << newlst[i];
	}
}

void Eldest(List& lst, List& eldestlst) 
{
	Student eldest = lst[0];
	for (int i = 1; i < lst.GetSize(); i++) 
	{
		if (lst[i].GGetYear() < eldest.GGetYear())
			eldest = lst[i];
		else if (lst[i].GGetYear() == eldest.GGetYear())
			if (lst[i].GGetMonth() < eldest.GGetMonth())
				eldest = lst[i];
			else if (lst[i].GGetMonth() == eldest.GGetMonth())
				if (lst[i].GGetDay() < eldest.GGetDay())
					eldest = lst[i];
				else if (lst[i].GGetDay() == eldest.GGetDay())
				{
					eldestlst.push_front(lst[i]);
				}
	}
	eldestlst.push_front(eldest);
}