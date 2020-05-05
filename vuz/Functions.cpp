#include "Functions.h"

void Compare(List& lst, char* TrainingDirection)
{
	for (int i = 0; i < lst.GetSize(); i++) {
		if (strcmp(lst[i].GetTrainingDirection(), TrainingDirection) == 0) {
			cout << lst[i];
		}
	}
}

void Compare(List& lst, List& newlst, char* TrainingDirection, int GroupNumber)
{
	for (int i = 0; i < lst.GetSize(); i++) 
	{
		if ((strcmp(lst[i].GetTrainingDirection(), TrainingDirection) == 0)&&(lst[i].GetNumberGroup() == GroupNumber)) {
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
	int index;
	for (int i = 1; i < lst.GetSize(); i++) 
	{
		if (lst[i].GGetYear() * 10000 + lst[i].GGetMonth() * 100 + lst[i].GGetDay() < eldest.GGetYear() * 10000 + eldest.GGetMonth() * 100 + eldest.GGetDay())
		{
			eldest = lst[i];
			index = i;
		}
	}
	for (int i = 1; i < lst.GetSize(); i++)
	{
		if ((lst[i].GGetYear() * 10000 + lst[i].GGetMonth() * 100 + lst[i].GGetDay() == eldest.GGetYear() * 10000 + eldest.GGetMonth() * 100 + eldest.GGetDay()) && (index != i))
			eldestlst.push_back(lst[i]);
	}
	eldestlst.push_back(eldest);
}

void Junior(List& lst, List& juniorlst)
{
	Student junior = lst[0];
	int index;
	for (int i = 1; i < lst.GetSize(); i++)
	{
		if (lst[i].GGetYear() * 10000 + lst[i].GGetMonth() * 100 + lst[i].GGetDay() > junior.GGetYear() * 10000 + junior.GGetMonth() * 100 + junior.GGetDay())
		{
			junior = lst[i];
			index = i;
		}
	}
	for (int i = 1; i < lst.GetSize(); i++)
	{
		if ((lst[i].GGetYear() * 10000 + lst[i].GGetMonth() * 100 + lst[i].GGetDay() == junior.GGetYear() * 10000 + junior.GGetMonth() * 100 + junior.GGetDay()) && (index != i))
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
	cout << "Введите путь в конкретную папку и название для файла( %Name%.txt ) или только название для файла( %Name%.txt )(Файл будет сохранен в папке с программой)" << endl;
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
	cout << "Введите путь в конкретную папку и название файла( %Name%.txt ) или только название файла если он лежит в папке с программой)" << endl << endl;
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
		cout << "Введите цифру нужного пункта меню:" << endl << endl;
		cout << "1) Создать новый список студентов" << endl;
		cout << "2) Загрузить список с диска" << endl;
		cout << "3) Выйти из программы" << endl<< endl;

		cin >> MenuBtn;
		switch (MenuBtn)
		{
		case(1): 
		{
			system("cls");
			List lst;
			OptionalInterface(lst);
			break;
		}
		case(2):
		{
			system("cls");
			List lst;
			Read4Disk(lst);
			system("cls");
			OptionalInterface(lst);
			break;
		}
		case(3):
		{
			exit(1);
		}
		default:
			cout << "ERROR404: Цифра не найдена xDD" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
}

void OptionalInterface(List& lst)
{
	system("cls");
	bool sas = true;
	int MenuBtn;
	while (sas)
	{
		cout << "Введите цифру нужного пункта меню:" << endl << endl;
		cout << "1) Добавить нового студента(В начало списка)" << endl;
		cout << "2) Удалить выбранного студента" << endl;
		cout << "3) Отсортировать список по алфавиту(По фамилиям)" << endl;
		cout << "4) Найти младшего или старшего студента" << endl;
		cout << "5) Определить всех студентов заданной группы(Направление + Номер группы)" << endl;
		cout << "6) Определить всех студентов заданного направления" << endl;
		cout << "7) Сохранить файл на диск" << endl;
		cout << "8) Просмотр списка" << endl;
		cout << "9) Очистить список" << endl;
		cout << "10) Вернуться в главное меню" << endl << endl;

		cin >> MenuBtn;
		switch (MenuBtn)
		{
		case(1):
		{	
			system("cls");
			int counter;
			char* Name = new char;
			char* LastName = new char;
			char* TrainingDirection = new char;
			char trash;
			int NumberGroup;
			int day;
			int month;
			int year;
			cout << "Сколько студентов хотите добавить?" << endl << endl; cin >> counter;
			system("cls");
			cout << "Введите данные о студенте в формате:" << endl;
			SetConsoleCP(1251);
			SetConsoleOutputCP(1251);
			for (int i = 0; i < counter; i++)
			{

				cout << "Фамилия: "; cin >> LastName;
				cout << "Имя: "; cin >> Name;
				cout << "Направление подготовки: "; cin >> TrainingDirection;
				cout << "Номер группы: "; cin >> NumberGroup;
				cout << "День рождения в формате: дд.мм.гггг: "; cin >> day >> trash >> month >> trash >> year;
				lst.push_front(Student(Name, LastName, TrainingDirection, NumberGroup, day, month, year, 0));
				system("pause");
				system("cls");
			}
			SetConsoleCP(866);
			SetConsoleOutputCP(866);
			break;
		}
		case(2):
		{
			if (lst.GetSize() != 0) 
			{
				system("cls");
				for (int i = 0; i < lst.GetSize(); i++) {
					cout << "Index: " << i << endl << lst[i];

				}
				int index;
				cout << "Введите номер студента, которого хотите удалить: "; cin >> index;
				lst.removeAt(index);
				system("cls");
				cout << "Выполнено((" << endl;
				system("pause");
				system("cls");
				break;
			}
			else 
			{
				system("cls");
				cout << "Невозможно совершить данную операцию, так как лист пуст" << endl;
				system("pause");
				system("cls");
				break;
			}
		}
		case(3):
		{
			if (lst.GetSize() != 0)
			{
				system("cls");
				SortList(lst);
				cout << "Выполнено!" << endl;
				system("pause");
				system("cls");
				break;
			}
			else
			{
				system("cls");
				cout << "Невозможно совершить данную операцию, так как лист пуст" << endl;
				system("pause");
				system("cls");
				break;
			}
		}
		case(4):
		{
			if (lst.GetSize() != 0)
			{
				system("cls");
				int index;
				bool ex = true;
				List eldlst;
				List junlst;
				while (ex)
				{
					cout << "1) Найти младшего студента\n2) Найти старшего студента" << endl << endl;
					cin >> index;
					system("cls");
					switch (index)
					{
					case(1):
					{
						Junior(lst, junlst);
						cout << "Самый(ые) молодой(ые) студент(ы):" << endl << endl;
						for (int i = 0; i < junlst.GetSize(); i++)
						{
							cout << junlst[i];
						}
						ex = false;
						system("pause");
						system("cls");
						break;
					}
					case(2):
					{
						Eldest(lst, eldlst);
						cout << "Самый(ые) старший(ые) студент(ы)" << endl << endl;
						for (int i = 0; i < eldlst.GetSize(); i++)
						{
							cout << eldlst[i];
						}
						ex = false;
						system("pause");
						system("cls");
						break;
					}
					default:
						cout << "ERROR404: Цифра не найдена xDD" << endl;
						system("pause");
						system("cls");
						break;
					}
				}
				break;
			}
			else
			{
				system("cls");
				cout << "Невозможно совершить данную операцию, так как лист пуст" << endl;
				system("pause");
				system("cls");
				break;
			}
		}
		case(5):
		{
			if (lst.GetSize() != 0)
			{
				system("cls");
				char* TD = new char;
				int NG;
				int index;
				List newlst;
				SetConsoleCP(1251);
				SetConsoleOutputCP(1251);
				cout << "Введите направление и номер группы в формате: РТ 12" << endl; cin >> TD >> NG; cout << endl;
				Compare(lst, newlst, TD, NG);
				SetConsoleCP(866);
				SetConsoleOutputCP(866);
				cout << "Если хотите сохранить список введите 1, для продолжение без сохранения введите любое другое число" << endl;
				cin >> index; cout << endl;
				if (index == 1) {
					Save2Disk(newlst);
					cout << "Файл сохранен!" << endl;
				}
				system("pause");
				system("cls");
				break;
			}
			else
			{
				system("cls");
				cout << "Невозможно совершить данную операцию, так как лист пуст" << endl;
				system("pause");
				system("cls");
				break;
			}
		}
		case(6): 
		{
			if (lst.GetSize() != 0)
			{
				SetConsoleCP(1251);
				SetConsoleOutputCP(1251);
				system("cls");
				char* TD = new char;
				cout << "Введите направление в формате: РТ" << endl; cin >> TD;	cout << endl;
				Compare(lst, TD);
				SetConsoleCP(866);
				SetConsoleOutputCP(866);
				system("pause");
				system("cls");
				break;
			}
			else
			{
				system("cls");
				cout << "Невозможно совершить данную операцию, так как лист пуст" << endl;
				system("pause");
				system("cls");
				break;
			}
		}
		case(7): 
		{
			if (lst.GetSize() != 0)
			{
				system("cls");
				Save2Disk(lst);
				cout << "Выполнено!" << endl;
				system("pause");
				system("cls");
				break;
			}
			else
			{
				system("cls");
				cout << "Невозможно совершить данную операцию, так как лист пуст" << endl;
				system("pause");
				system("cls");
				break;
			}
		}
		case(8): 
		{
			if (lst.GetSize() != 0)
			{
				system("cls");
				for (int i = 0; i < lst.GetSize(); i++) {
					cout << lst[i];
				}
				system("pause");
				system("cls");
				break;
			}
			else
			{
				system("cls");
				cout << "Невозможно совершить данную операцию, так как лист пуст" << endl;
				system("pause");
				system("cls");
				break;
			}
		}
		case(9): 
		{
			if (lst.GetSize() != 0)
			{
				system("cls");
				lst.clear();
				cout << "Выполнено((\n" << endl;
				system("pause");
				system("cls");
				break;
			}
			else
			{
				system("cls");
				cout << "Невозможно совершить данную операцию, так как лист пуст" << endl;
				system("pause");
				system("cls");
				break;
			}
		}
		case(10): 
		{
			system("cls");
			sas = false;
			break;
		}
		default:
			system("cls");
			cout << "ERROR404: Цифра не найдена xDD" << endl;
			system("pause");
			system("cls");
			break;
		}

	}
}
