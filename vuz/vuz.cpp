#include "List.h"
#include "Student.h"
#include "Functions.h"
using namespace std;

int main() {

	Student ST1 = Student("Sanya", "Moiseev", "RT", 12);
	Student ST2 = Student("Rany", "Sosev", "RT", 13);
	List lst, newlst;
	lst.push_front(ST1);
	lst.push_front(ST2);
	for (int i = 0; i < lst.GetSize(); i++)
	{
		cout << lst[i];
	}
	Compare(lst, "RT");
	Compare(lst, newlst, "RT", 12);
	system("pause");
	return 0;
}