#include "Functions.h"
#include <stdlib.h>
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

void Save2Disk(List& lst)
{
	string path;
	cout << "������� ���� � ���������� ����� � �������� ��� �����( %Name%.txt ) ��� ������ �������� ��� �����( %Name%.txt )(���� ����� �������� � ����� � ����������)";
	cin >> path;
	ofstream fout;
	fout.open(path);
	for (int i = 0; i < lst.GetSize(); i++)
	{
		fout.write(lst[i].GetName(), strlen(lst[i].GetName()));
		if (strlen(lst[i].GetName()) < 8) {
			fout << "\t";
		}
		fout << "\t";
		
		fout.write(lst[i].GetLastName(), strlen(lst[i].GetLastName()));
		if (strlen(lst[i].GetLastName()) < 8) {
			fout << "\t";
		}
		fout << "\t";

		fout.write(lst[i].GetTrainingDirection(), strlen(lst[i].GetTrainingDirection()));
		if (strlen(lst[i].GetTrainingDirection()) < 8) {
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
	int i = 0, j = 0;;
	char* Name = new char;
	char* LastName = new char;
	char* TrainingDirection = new char;
	char tresh;
	int NumberGroup;
	int day;
	int month;
	int year;
	while (!fin.eof())
	{
		fin >> Name >> LastName >> TrainingDirection >> NumberGroup >> day >> tresh >> month >> tresh >> year;
		if (strcmp(Name, "") == 0)
			break;
		lst.push_front(Student(Name, LastName, TrainingDirection, NumberGroup, day, month, year, 0));
	}
	fin.close();
	cout << endl;
}

void MainInterface()
{
	int MenuBtn;
	while (true)
	{	
		cout << "������� ����� ������� ������ ����:" << endl << endl;
		cout << "1) ������� ����� ������ ���������" << endl;
		cout << "2) ��������� ������ � �����" << endl;
		cout << "3) ����� �� ���������" << endl;

		cin >> MenuBtn;
		switch (MenuBtn)
		{
		case(1): 
		{
			List lst;
			OptionalInterface(lst);
			break;
		}
		case(2):
		{
			List lst;
			Read4Disk(lst);
			OptionalInterface(lst);
			break;
		}
		case(3):
		{
			exit(1);
		}
		default:
			cout << "ERROR404: ����� �� ������� xDD" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
}

void OptionalInterface(List& lst)
{	
	bool sas = true;
	int MenuBtn;
	while (sas)
	{
		cout << "������� ����� ������� ������ ����:" << endl << endl;
		cout << "1) �������� ������ ��������(� ������ ������)" << endl;
		cout << "2) ������� ���������� ��������" << endl;
		cout << "3) ������������� ������ �� ��������(�� ��������)" << endl;
		cout << "4) ����� �������� ��� �������� ��������" << endl;
		cout << "5) ���������� ���� ��������� �������� ������(����������� + ����� ������)" << endl;
		cout << "6) ���������� ���� ��������� ��������� �����������" << endl;
		cout << "7) ��������� ���� �� ����" << endl;
		cout << "8) �������� ������" << endl;
		cout << "9) �������� ������" << endl;
		cout << "10) ��������� � ������� ����" << endl;

		cin >> MenuBtn;
		switch (MenuBtn)
		{
		case(1):
		{
			int counter;
			char* Name = new char;
			char* LastName = new char;
			char* TrainingDirection = new char;
			char trash;
			int NumberGroup;
			int day;
			int month;
			int year;
			cout << "������� ��������� ������ ��������?" << endl << endl; cin >> counter;
			cout << "������� ������ � �������� � �������:" << endl;
			for (int i = 0; i < counter; i++)
			{
				cout << "�������: "; cin >> LastName;
				cout << endl << "���: "; cin >> Name;
				cout << endl << "����������� ����������: "; cin >> TrainingDirection;
				cout << endl << "����� ������: "; cin >> NumberGroup;
				cout << endl << "���� �������� � �������: ��.��.����: "; cin >> day >> trash >> month >> trash >> year;
				lst.push_front(Student(Name, LastName, TrainingDirection, NumberGroup, day, month, year, 0));
				system("pause");
				system("cls");
			}
			break;
		}
		case(2):
		{
			int index;
			cout << "������� ����� ��������, �������� ������ �������: "; cin >> index;
			lst.removeAt(index);
			cout << "���������((" << endl;
			system("pause");
			system("cls");
			break;
		}
		case(3):
		{
			SortList(lst);
			break;
		}
		case(4):
		{
			int index;
			bool ex = true;
			List newlst;
			while (ex)
			{
				cout << "1) ����� �������� ��������\n2) ����� �������� ��������" << endl;
				cin >> index;
				switch (index)
				{
				case(1):
				{
					Junior(lst, newlst);
					cout << "�����(��) �������(��) �������(�):" << endl << endl;
					for (int i = 0; i < newlst.GetSize(); i++)
					{
						cout << newlst[i] << endl;
					}
					ex = false;
					system("pause");
					system("cls");
					break;
				}
				case(2):
				{
					Eldest(lst, newlst);
					cout << "�����(��) �������(��) �������(�):" << endl << endl;
					for (int i = 0; i < newlst.GetSize(); i++)
					{
						cout << newlst[i] << endl;
					}
					ex = false;
					system("pause");
					system("cls");
					break;
				}
				default:
					cout << "ERROR404: ����� �� ������� xDD" << endl;
					system("pause");
					system("cls");
					break;
				}
			}
			break;
		}
		case(5):
		{
			char* TD = new char;
			int NG;
			int index;
			List newlst;
			cout << "������� ����������� � ����� ������ � �������: '�� 12'" << endl; cin >> TD >> NG;
			Compare(lst, newlst, TD, NG);
			cout << "���� ������ ��������� ������ ������� 1, ��� ����������� ��� ���������� ������� ����� ������ �����" << endl;
			cin >> index;
			if (index == 1) {
				Save2Disk(newlst);
			}
			cout << "���� ��������";
			system("pause");
			system("cls");
			break;
		}
		case(6): 
		{
			char* TD = new char;
			cout << "������� ����������� � �������: '��'" << endl; cin >> TD;
			Compare(lst, TD);
			system("pause");
			system("cls");
			break;
		}
		case(7): 
		{
			Save2Disk(lst);
			cout << "���������!" << endl;
			system("pause");
			system("cls");
			break;
		}
		case(8): 
		{
			for (int i = 0; i < lst.GetSize(); i++) {		
				cout << lst[i];
			}
			system("pause");
			system("cls");
			break;
		}
		case(9): 
		{
			lst.clear();
			cout << "���������((" << endl;
			system("pause");
			system("cls");
			break;
		}
		case(10): 
		{
			sas = false;
			break;
		}
		default:
			cout << "ERROR404: ����� �� ������� xDD" << endl;
			system("pause");
			system("cls");
			break;
		}

	}
}
