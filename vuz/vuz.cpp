#include "List.h"
#include "Student.h"
#include "Functions.h"
using namespace std;

int main() {
	Student ST1 = Student("Sanya", "Moiseev", "RT", 12, 30, 11, 2003);
	Student ST2 = Student("Rany", "Sosev", "RT", 13, 30, 11, 1969);
	List lst, newlst, eldestlst;
	lst.push_front(ST1);
	lst.push_front(ST2);
	//Compare(lst, "RT");
	Compare(lst, newlst, "RT", 12);
	Eldest(lst, eldestlst);
	cout << eldestlst[0] << endl;
	system("pause");
	return 0;
}