#include<iostream>
#include<vector>
#include<string>
#include<stack>

using namespace std;
//求正整数n的阶乘的末尾有多少个0
int sum(int n)
{
	if (n < 0) return 0;
	if (n < 5) return 0;
	int count = 0;
	for (int i = 5; i <= n; i++)
	{
		int flag = i;
		while (flag % 5 == 0)
		{
			count++;
			flag /= 5;
		}
	}
	return count;
}
int main()
{
	int n;
	cin >> n;
	int count = sum(n);
	cout << count << endl;
	system("pause");
	return 0;
}