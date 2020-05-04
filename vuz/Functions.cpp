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

void SortList(List& lst)
{
	int k = 0;
	for (int i = 0; i < lst.GetSize() - 1; i++)
	{
		for (int j = i; j < lst.GetSize() - 1; j++)
		{
			char* st1 = lst[j].GetLastName();
			char* st2 = lst[j + 1].GetLastName();
			if ((int)st1[0] > (int)st2[0])
			{
				lst.Swap(lst, j, j + 1);
			}
			if ((int)st1[0] == (int)st2[0])
			{
				while ((int)st1[k] == (int)st2[k])
				{
					k++;
				}
				if ((int)st1[k] > (int)st2[k]) {
					lst.Swap(lst, j, j + 1);
				}
			}
			k = 0;
		}
		k = 0;
	}
}
/*
void Save2Disk(List& lst)
{
	string path;
	cin >> path;
	ofstream fout;
	fout.open(path);
	for (int i = 0; i < lst.GetSize(); i++)
	{
		fout.write((char*)&lst[i], sizeof(Student));
	}
	fout.close();
}
*/

void Save2Disk(List& lst)
{
	string path;
	cin >> path;
	ofstream fout;
	fout.open(path);
	int counter;
	for (int i = 0; i < lst.GetSize(); i++)
	{
		counter = 0;
		char* c = lst[i].GetName();
		for (int j = 0; j < sizeof(lst[i].GetName()); j++) {
			if ((c[j] > (char)62 && c[j] < (char)91) || (c[j] > (char)96 && c[j] < (char)123) || (c[j] > (char)191 && c[j] < (char)256))
				counter++;
	}
		fout.write(lst[i].GetName(), counter);
		if (counter < 8) {
			fout << "\t";
		}
		fout << "\t";

		counter = 0;
		c = lst[i].GetLastName();
		for (int j = 0; j < sizeof(lst[i].GetLastName()); j++) {
			if ((c[j] > (char)62 && c[j] < (char)91) || (c[j] > (char)96 && c[j] < (char)123) || (c[j] > (char)191 && c[j] < (char)256))
				counter++;
		}

		fout.write(lst[i].GetLastName(), counter);
		if (counter < 8) {
			fout << "\t";
		}
		fout << "\t";

		counter = 0;
		c = lst[i].GetTrainingDirection();
		for (int j = 0; j < sizeof(lst[i].GetTrainingDirection()); j++) {
			if ((c[j] > (char)62 && c[j] < (char)91) || (c[j] > (char)96 && c[j] < (char)123) || (c[j] > (char)191 && c[j] < (char)256))
				counter++;
		}

		fout.write(lst[i].GetTrainingDirection(), counter);
		if (counter < 8) {
			fout << "\t";
		}
		fout << "\t";

		fout << lst[i].GetNumberGroup() << "\t";
		fout << lst[i].GGetDay() << ".";
		fout << lst[i].GGetMonth() << ".";
		fout << lst[i].GGetYear() << endl;
	}
	fout.close();
	cout << endl;
}

void Read4Disk(List& lst)
{
	string path;
	cin >> path;
	ifstream fin;
	fin.open(path);
	int i = 0;
	char* Ctemp = new char;
	int Itemp;
	while (!fin.eof())
	{
		lst.push_front(Student());
		fin >> Ctemp;
		if(Ctemp[1] != (char)32)
		lst[i].SetName(Ctemp);
		fin >> Ctemp;
		if (Ctemp[1] != (char)32)
		lst[i].SetLastName(Ctemp);
		fin >> Ctemp;
		if (Ctemp[1] != (char)32)
		lst[i].SetTrainingDirection(Ctemp);
		fin >> Itemp;
		lst[i].SetNumderGroup(Itemp);
		fin >> Itemp;
		lst[i].SSetDay(Itemp);
		fin >> Itemp;
		lst[i].SSetMonth(Itemp);
		fin >> Itemp;
		lst[i].SSetYear(Itemp);
		i++;
	}
	delete Ctemp;
	fin.close();
}