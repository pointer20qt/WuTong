#include<iostream>
#include<time.h>
#include<math.h>

using namespace std;

//��ôͨ��rand����[0,a)����
//��ôͨ��rand����[a,b)����
//��ô����һ��0~1�����С��double
//��ô����a~b�����С��
//����0��100���������������жϳɹ�,�ɹ�����true
//����0��1��double���������жϳɹ����ɹ�����ture
//rand()�������������ȡ��һ��    
//srand(time(0)) ��ʼ�����������

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
			cout << "����" << endl;
			t++;
		}
		else
		{
			f++;
		}
	}
	cout << t << "��" << f << endl;
}
