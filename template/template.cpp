#include <iostream>
#include <vector>

using namespace std;


template<class T> T Tmax(T a, T b)
{
	cout << "模板推导函数" << endl;
	return a > b ? a : b;
}

template<class T> void Tswap(T& a, T& b)
{
	int tem = a;
	a = b;
	b = tem;
}

int Tmax(int a, int b)
{
	cout << "指定模板推导" << endl;
	return a > b ? a : b;
}

template<class T> class T_stack
{
	std::vector<T> arr;
public:
	void push(T&& obj)
	{
		arr.push_back(obj);
	}
	void pop()
	{
		arr.pop_back();
	}
	T& top()
	{
		return arr.back();
	}
	size_t size()
	{
		return arr.size();
	}
	bool empty()
	{
		return arr.empty();
	}
};

class A
{
public:
	int value = 0;
	char* p;
	A(int v)
	{
		p = new char[100];
		value = v;
	}
	A(const A& other) :A(other.value)
	{
		cout << "拷贝A" << endl;
	}
	A& operator=(const A& other)
	{
		delete p;
		p = new char[100];
		value = other.value;
		return *this;
	}
	~A()
	{
		delete p;
	}
};

void Tswap(A& a, A& b)
{
	A tem(a);
	a.operator=(b);
	b.operator=(tem);
}
void Tprint()
{
	cout << "递归拆包"<<endl;
}
template<class T, class... args> void Tprint(T f, args... d)
{
	cout << f << endl;
	Tprint(d...);
}

int main()
{
	Tprint(2, 4.5, 2, 6, "2346");
	T_stack<int> t;
	t.push(5);
	t.push(6);
	t.push(1);
	cout << t.top() << endl;
	t.pop();
	cout << t.top() << endl;
	int x1 = 1, x2 = 3;
	double d1 = 2.1, d2 = 4.2;
	A a1(10), a2(3);
	Tswap(a1, a2);
	Tswap(x1, x2);
	cout << x1 <<"和"<< x2 << endl;
	cout << Tmax(x1, x2) << endl;
	cout << Tmax<double>(x1, d2) << endl;
	cout << Tmax<>(x1, x2) << endl;
}