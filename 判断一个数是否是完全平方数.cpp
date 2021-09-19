#include<iostream>
#include<algorithm>
using namespace std;

bool issqrt(int n)
{
	double m = sqrt(n);//int直接向下取整
	if (m == int(m))
	{
		return true;
	}
	return false;
}

int main()
{
	int a;
	cin >> a;
	cout << int (3.897) << endl;
	if (issqrt(a))
	{
		cout << a << "是完全平方数!" << endl;
	}
	else
	{
		cout << a << "不是完全平方数!" << endl;
	}
	system("pause");
	return 0;
}