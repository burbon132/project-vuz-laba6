#include "List.h"
#include "Student.h"
#include "Functions.h"
#include <locale.h>
using namespace std;

int main() {
	setlocale(LC_ALL, "RUS");
	Student ST1 = Student("Саня", "Моисеев", "РТ", 12, 30, 11, 2003);
	Student ST2 = Student("Aня", "Сосев", "УТС", 13, 7, 1, 2003);
	Student ST3 = Student("Вадула", "Романов", "БТС", 21, 6, 2, 2010);
	List lst;
	//lst.push_front(ST1);
	//lst.push_front(ST3);
	//lst.push_front(ST2);
	//Save2Disk(lst);
	Read4Disk(lst);
	for (int i = 0; i < lst.GetSize(); i++) {
		cout << lst[i];
	}
	system("pause");
	return 0;
}