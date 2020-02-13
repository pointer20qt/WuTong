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
		cout  << "泳池" << endl;
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
		cout << this->schoolName<<"闭校了" << endl;
		/*delete master;*/
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

	virtual void schoolOpens()
	{
		cout << this->schoolName << "开学了" << endl;
	}

	virtual void schoolOpens(int i)
	{
		cout << this->schoolName << "开学了" << endl;
	}

};

class University: public school
{
public:
	principal* Vice;
	University() :school("大庆指针","培训机构","大庆")
	{
		cout << "大学的构造函数" << endl;
		Vice = new principal("副校长");
	}
	virtual void schoolOpens()
	{
		cout << getschoolName() << "开学典礼" << endl;
	}
	~University()
	{
		cout << "大学的析构函数" << endl;
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
	principal*p=new principal("游泳馆");
	p->wash();
	school* ps = new school("春田花花幼儿园", "幼儿园", "春田");
	University* u=new University();
	printSchool(ps);
	printSchool(u);
	
}

