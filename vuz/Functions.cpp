#include "Functions.h"

void Compare(List& lst, char* TrainingDirection)
{
	for (int i = 0; i < lst.GetSize(); i++) {
		if (lst[i].GetTrainingDirection() == TrainingDirection) {
			cout << lst[i];
		}
	}
}

List Compare(List& lst, char* TrainingDirection, int GroupNumber)
{
	List newlst;
	for (int i = 0; i < lst.GetSize(); i++) {
		if ((lst[i].GetTrainingDirection() == TrainingDirection)&&(lst[i].GetNumberGroup() == GroupNumber)) {
			newlst.push_front(lst[i]);
			cout << lst[i];
		}
	}
	return newlst;
}
