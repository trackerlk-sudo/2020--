#include<iostream>

using namespace std;

bool ispre(int m)
{//判断m是否是素数
	for (int i = 2; i*i <= m; i++)
	{
		if (m%i == 0)
		{
			return false;
		}
	}
	return true;
}

int main()
{
	int m;
	cin >> m;
	for (int i = 2; i <= m; i++)
	{
		if (ispre(i))
		{//判断i是否是素数
			cout << i << " ";
		}
	}
	cout << endl;
	system("pause");
	return 0;
}