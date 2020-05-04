#include "List.h"
#include "Student.h"
#include "Functions.h"
using namespace std;

int main() {
	Student ST1 = Student("Sanya", "Moiseev", "RT", 12, 30, 11, 2003);
	Student ST2 = Student("Rany", "Sosev", "RT", 13, 30, 11, 2003);
	Student ST3 = Student("Abdula", "Abdula", "UTS", 21, 06, 02, 2010);
	List lst, newlst, eldestlst;
	lst.push_front(ST2);
	lst.push_front(ST3);
	lst.push_front(ST1);
	SortList(lst);
	for (int i = 0; i < lst.GetSize(); i++) {
		cout << lst[i];
	}
	system("pause");
	return 0;
}