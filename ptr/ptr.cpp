#include <iostream>
#include "ptr.h"

using namespace std;

class tool
{
public:
	int value = 0;
	tool()
	{
		cout << "tool������" << endl;
	}
	~tool()
	{
		cout << "tool������" << endl;
	}

};

void run()
{
	T::TSharedPtr<tool>ptr1{ new tool };
	cout << "��ǰ���ü���" << ptr1.use_count() << endl;
	T::TSharedPtr<tool> ptr2(ptr1);
	T::TSharedPtr<tool> ptr3;
	ptr3 = ptr2;
	cout << "��ǰ���ü���" <<ptr1.use_count()<< endl;
	cout << "��ǰ���ü���" << ptr2.use_count() << endl;
	cout << "��ǰ���ü���" << ptr3.use_count() << endl;
	(*ptr2).value;
	ptr2->value;
	ptr2.reset();
	cout << "��ǰ���ü���" << ptr3.use_count() << endl;
}

int main()
{
	run();
}