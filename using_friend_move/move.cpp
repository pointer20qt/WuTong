#include "deep_copy.h"
#include <iostream>
#include<string>

using namespace std;


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
	friend class A;
	std::string schoolName;
	std::string schoolType;
	std::string address;
	principal *master;

public:

	~school()
	{
		cout << "��������" << endl;
		delete master;
	}
	school(std::string schoolName, std::string schoolType, std::string address)
	{
		cout << "��ͨ���캯��" << endl;
		this->schoolName = schoolName;
		this->schoolType = schoolType;
		this->address = address;
		master = new principal("����ʦ");
	}

	school(const school& p)
	{
		cout << "�������캯��" << endl;
		master = new principal(*p.master);
	}

	school(school&& other) :schoolName(other.schoolName), schoolType(other.schoolType), address(other.address)
	{
		cout << "�ƶ�����" << endl;
		master = other.master;
		other.master = NULL;
	}

	void schoolOpens()
	{
		cout << this->schoolName << "��ѧ��" << endl;
	}

};

class A
{
public:
	void run(school s)
	{
		cout << "��Ԫ����" << endl;
		s.schoolName;
	}
};



school getschool()
{
	school s2("����ָ��", "��ҵ��ѵ����", "����");
	return s2;
}

int main()
{
	A a;
	school s1(std::move(getschool()));
	a.run(s1);
	cout << "��һ�����" << endl;
}

