#include<iostream>
#include<vector>
#include<set>
#include<algorithm>

using namespace std;

//int main()
//{
//	int n, m;
//	cin >> n >> m;
//	vector<int> arr(m, 0);
//	set<int> myset;
//	for (int i = 0; i < m; i++)
//	{
//		cin >> arr[i];
//	}
//
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 0; j<arr.size(); j++)
//		{
//			if (i%arr[j] == 0)
//			{
//				myset.insert(i);
//			}
//		}
//	}
//	cout << myset.size() << endl;
//	system("pause");
//	return 0;
//}

//int main()
//{//背包问题
//	int N, M;
//	cin >> N >> M;
//	vector<vector<int>> arr(N, vector<int>(2, 0));
//	for (int i = 0; i < N; i++)
//	{
//		for (int j = 0; j < 2; j++)
//		{
//			cin >> arr[i][j];
//		}
//	}//保存输入
//
//	//01背包
//	vector<vector<int>> dp(N + 1, vector<int>(M+1, 0));
//	//dp[i][j]表示考虑前i件放入j容量的背包中能获得的最大收益
//	for (int i = 1; i <= N; i++)
//	{
//		for (int j = 1; j <= M; j++)
//		{//当前选或者不选
//			if (j < arr[i - 1][0])
//			{
//				dp[i][j] = dp[i - 1][j];
//			}
//			else
//			{
//				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - arr[i - 1][0]] + arr[i - 1][1]);
//			}
//		}
//	}
//	cout << dp[N][M] << endl;
//	system("pause");
//	return 0;
//}

int main()
{
	int N;
	cin >> N;
	vector<vector<int>> arr(N, vector<int>(N, 0));
	//本质是：填充四个矩阵
	if (N % 2 == 0)
	{
		int mid = N / 2;
		for (int i = 0; i < mid; i++)
		{
			for (int j = i + 1; j < mid; j++)
			{
				arr[i][j] = 2;
			}
		}

		for (int i = 0; i < mid; i++)
		{
			for (int j = i - 1; j >= 0; j--)
			{
				arr[i][j] = 3;
			}
		}

		for (int i = N - 2; i >= mid; i--)
		{
			for (int j = 0; j < N - i - 1; j++)
			{
				arr[i][j]=4;
			}
		}

		for (int i = mid + 1; i < N; i++)
		{
			for (int j = i + 1; j < mid; j++)
			{
				arr[i][j] = 5;
			}
		}

		for (int i = mid; i < N; i++)
		{
			for (int j = i - 1; j >= mid; j--)
			{
				arr[i][j] = 6;
			}
		}

		for (int i = mid + 1; i < N; i++)
		{
			for (int j = i + 1; j < N; j++)
			{
				arr[i][j] = 7;
			}
		}

		for (int i = mid-1; i>=0; i--)
		{
			for (int j = 0; j < mid+i; j++)
			{
				arr[i][j] = 1;
			}
		}

		for (int i = mid - 1; i >= 0; i--)
		{
			for (int j = N - 1; j > i; j--)
			{
				arr[i][j] = 8;
			}
		}
	}

	for (int i = 0; i < arr.size(); i++)
	{
		for (int j = 0; j < arr[i].size(); j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	system("pause");
	return 0;
}