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
	T_autoPtr<tool>ptr1{ new tool };
	T_autoPtr<tool> ptr2(ptr1);
	T_autoPtr<tool> ptr3;
	ptr3 = ptr2;
	(*ptr2).value;
	ptr2->value;
}

int main()
{
	run();
}