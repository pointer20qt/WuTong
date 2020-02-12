#include "deep_copy.h"
#include <iostream>

using namespace std;

struct node
{
	int value;
	struct node* pre;
	struct node* next;
};

class principal
{
	string name;
public:
	principal(string sname)
	{
		this->name = sname;
	}

	~principal()
	{
		cout << "����ʦ�°���" << endl;
	}
};

class school
{
public:
	std::string schoolName;
	std::string schoolType;
	std::string address;
	principal *master;

	~school()
	{
		delete master;
	}
	school(std::string schoolName, std::string schoolType, std::string address)
	{
		this->schoolName = schoolName;
		this->schoolType = schoolType;
		this->address = address;
		master = new principal("����ʦ");
	}

	school(const school& p)
	{
		master = new principal(*p.master);
	}
	
	
};
void run()
{
	school s("����ָ��", "��ҵ��ѵ����", "����");
	school s2("����ʯ�ʹ�ѧ", "��ѧ", "����");
}


int main()
{
	run();
	cout << "��һ�����" << endl;
}

