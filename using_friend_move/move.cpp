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
		cout << "杨老师下班了" << endl;
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
		cout << "析构函数" << endl;
		delete master;
	}
	school(std::string schoolName, std::string schoolType, std::string address)
	{
		cout << "普通构造函数" << endl;
		this->schoolName = schoolName;
		this->schoolType = schoolType;
		this->address = address;
		master = new principal("杨老师");
	}

	school(const school& p)
	{
		cout << "拷贝构造函数" << endl;
		master = new principal(*p.master);
	}

	school(school&& other) :schoolName(other.schoolName), schoolType(other.schoolType), address(other.address)
	{
		cout << "移动构造" << endl;
		master = other.master;
		other.master = NULL;
	}

	void schoolOpens()
	{
		cout << this->schoolName << "开学了" << endl;
	}

};

class A
{
public:
	void run(school s)
	{
		cout << "友元函数" << endl;
		s.schoolName;
	}
};



school getschool()
{
	school s2("大庆指针", "就业培训机构", "大庆");
	return s2;
}

int main()
{
	A a;
	school s1(std::move(getschool()));
	a.run(s1);
	cout << "下一句代码" << endl;
}

