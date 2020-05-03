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
		if (lst[i].GGetYear() * 10000 + lst[i].GGetMonth() * 100 + lst[i].GGetDay() < eldest.GGetYear() * 10000 + eldest.GGetMonth() * 100 + eldest.GGetDay())
			eldest = lst[i];
	}
	for (int i = 1; i < lst.GetSize(); i++)
	{
		if (lst[i].GGetYear() * 10000 + lst[i].GGetMonth() * 100 + lst[i].GGetDay() == eldest.GGetYear() * 10000 + eldest.GGetMonth() * 100 + eldest.GGetDay())
			eldestlst.push_back(lst[i]);
	}
	eldestlst.push_back(eldest);
}

void Junior(List& lst, List& juniorlst)
{
	Student junior = lst[0];
	for (int i = 1; i < lst.GetSize(); i++)
	{
		if (lst[i].GGetYear() * 10000 + lst[i].GGetMonth() * 100 + lst[i].GGetDay() < junior.GGetYear() * 10000 + junior.GGetMonth() * 100 + junior.GGetDay())
			junior = lst[i];
	}
	for (int i = 1; i < lst.GetSize(); i++)
	{
		if (lst[i].GGetYear() * 10000 + lst[i].GGetMonth() * 100 + lst[i].GGetDay() == junior.GGetYear() * 10000 + junior.GGetMonth() * 100 + junior.GGetDay())
			juniorlst.push_back(lst[i]);
	}
	juniorlst.push_back(junior);
}