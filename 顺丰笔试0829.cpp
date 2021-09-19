#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	long long int n, m;
	cin >> n >> m;
	vector<long long int> arr(m, 0);
	for (int i = 0; i < m; i++)
	{
		cin >> arr[i];
	}//保存输入
	long long int tmp = -1;
	double k = 0;
	for (int i = 0; i < m; i++)
	{

		n += arr[i];//中午灌水
		n -= ceil(n*1.0/2.0);//下午放水
	}
	cout << n << endl;
	//system("pause");
	return 0;
}