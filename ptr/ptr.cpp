#include <iostream>
#include "ptr.h"

using namespace std;

class tool
{
public:
	int value = 0;
	tool()
	{
		cout << "tool构造了" << endl;
	}
	~tool()
	{
		cout << "tool析构了" << endl;
	}

};

void run()
{
	T::TSharedPtr<tool>ptr1{ new tool };
	cout << "当前引用计数" << ptr1.use_count() << endl;
	T::TSharedPtr<tool> ptr2(ptr1);
	T::TSharedPtr<tool> ptr3;
	ptr3 = ptr2;
	cout << "当前引用计数" <<ptr1.use_count()<< endl;
	cout << "当前引用计数" << ptr2.use_count() << endl;
	cout << "当前引用计数" << ptr3.use_count() << endl;
	(*ptr2).value;
	ptr2->value;
	ptr2.reset();
	cout << "当前引用计数" << ptr3.use_count() << endl;
}

int main()
{
	run();
}