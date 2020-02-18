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

class node
{
public:
	T::TWeakPtr<node> pre;
	T::TWeakPtr<node> next;
	~node()
	{
		cout << "�ڵ�������" << endl;
	}
};



void run2()
{
	T::TSharedPtr<node> node1 = { new node };
	T::TSharedPtr<node> node2 = { new node };
	node1->next.operator=(node2);
	node2->pre .operator=(node1);
	cout << node1.use_count()<< endl;
}

int main()
{
	run2();
}