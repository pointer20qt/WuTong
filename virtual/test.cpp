#include "deep_copy.h"
#include <iostream>
#include<string>
#include <vector>

using namespace std;

class Natatorium
{
public:

	virtual void wash() = 0;
};


class principal:public Natatorium
{
	string name;
public:
	principal(string sname)
	{
		this->name = sname;
	}
	~principal()
	{

	}

	 void wash()
	{
		cout  << "Ӿ��" << endl;
	}
};


class school 
{
	std::string schoolName;
	std::string schoolType;
	std::string address;
	principal *master;

public:
	std::string getschoolName()
	{
		return schoolName;
	}

	virtual ~school()
	{
		cout << this->schoolName<<"��У��" << endl;
		/*delete master;*/
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

	virtual void schoolOpens()
	{
		cout << this->schoolName << "��ѧ��" << endl;
	}

	virtual void schoolOpens(int i)
	{
		cout << this->schoolName << "��ѧ��" << endl;
	}

};

class University: public school
{
public:
	principal* Vice;
	University() :school("����ָ��","��ѵ����","����")
	{
		cout << "��ѧ�Ĺ��캯��" << endl;
		Vice = new principal("��У��");
	}
	virtual void schoolOpens()
	{
		cout << getschoolName() << "��ѧ����" << endl;
	}
	~University()
	{
		cout << "��ѧ����������" << endl;
		delete Vice;
	}
};


void printSchool(school* school)
{
	school->schoolOpens();
	delete school;
}

int main()
{
	principal*p=new principal("��Ӿ��");
	p->wash();
	school* ps = new school("���ﻨ���׶�԰", "�׶�԰", "����");
	University* u=new University();
	printSchool(ps);
	printSchool(u);
	
}

