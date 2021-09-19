#include<iostream>
#include<vector>

using namespace std;

//int main()
//{
//	int T;
//	cin >> T;//测试数据组数
//	for (int i = 0; i < T; i++)
//	{
//		int L, n;
//		cin >> L >> n;//长度和测试数据组数
//		vector<int> res(L+1, 0);
//		vector< vector<int>> arr(n, vector<int>(2, 0));
//		for (int j = 0; j < n; j++)
//		{
//			cin >> arr[j][0] >> arr[j][1];
//		}
//
//		for (int k = 0; k <n; k++)
//		{
//			for (int m = arr[k][0]; m <= arr[k][1]; m++)
//			{
//				res[m]++;
//			}
//		}
//
//		for (int r = 1; r <= L; r++)
//		{
//			cout << res[r] <<" ";
//		}
//		cout << endl;
//	}
//	system("pause");
//	return 0;
//}

int main()
{
	int n, m;
	cin >> n >> m;
	//变态跳台阶问题，每次迭代用两个数记录上次跳的台阶数
	vector<int> dp(n + 1, 0);
	//dp[i]表示跳上i阶台阶的方案数
	dp[0] = 1;
	dp[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (i >= j)
			{
				dp[i] += dp[i - j];
			}
		}
	}
	cout << dp[n] << endl;
	system("pause");
	return 0;
}