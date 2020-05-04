#include "List.h"
#include "Student.h"
#include "Functions.h"
#include <locale.h>
using namespace std;

int main() {
	setlocale(LC_ALL, "RUS");
	Student ST1 = Student("Саня", "Моисеев", "РТ", 12, 30, 11, 2003);
	Student ST2 = Student("Rany", "Sosev", "РТ", 13, 30, 11, 2003);
	Student ST3 = Student("Abdula", "Abdula", "УТС", 21, 06, 02, 2010);
	List lst;
	//lst.push_front(ST2);
	//lst.push_front(ST3);
	//lst.push_front(ST1);
	Read4Disk(lst);
	for (int i = 0; i < lst.GetSize(); i++) {
		cout << lst[i];
	}
	system("pause");
	return 0;
}