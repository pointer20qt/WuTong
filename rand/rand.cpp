#include<iostream>
#include<time.h>
#include<math.h>

using namespace std;

//怎么通过rand生成[0,a)的数
//怎么通过rand生成[a,b)的数
//怎么生成一个0~1的随机小数double
//怎么生成a~b的随机小数
//传入0到100的整数，概率性判断成功,成功返回true
//传入0到1的double，概率性判断成功，成功返回ture
//rand()从随机数序列中取下一个    
//srand(time(0)) 初始化随机数序列

bool probability(int n)
{
	int p = rand() % 100;
	if (p <n)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool probability(double n)
{
	double p = ((double)rand()) / RAND_MAX;
	if (p <n)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	srand(time(0));
	int t = 0, f = 0;
	for (int i = 0; i < 100; i++)
	{
		if (probability(0.05))
		{
			cout << "暴击" << endl;
			t++;
		}
		else
		{
			f++;
		}
	}
	cout << t << "和" << f << endl;
}
