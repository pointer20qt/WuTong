#include <iostream>
#include <vector>
#include <initializer_list>
//#define NDEBUG
#include <assert.h>

using namespace std;

class vec
{
	int* obj;
public:
	vec(std::initializer_list<int> arr)
	{
		obj = new int[arr.size()];
		for (int i = 0; i < arr.size(); i++)
		{
			obj[i]=*(arr.begin() + i);
		}
	}
	int& operator [](int index)
	{
		assert(index >= 0);
		return obj[index];
	}

};

int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7 };
	vec v({ 1, 2, 3, 4, 5, 6, 7 });
	cout << v[2] << endl;
	v[2] = 1;
	cout << v[2] << endl;
	cout << v[-2] << endl;
}