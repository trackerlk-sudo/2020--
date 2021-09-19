#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

//int main()
//{
//	int N;
//	string str;
//	cin >> N;
//	cin >> str;
//	int len = str.size();
//	if (len <= 1) cout << 0 << endl;
//	vector<vector<int>> dp(len, vector<int>(len, 0));
//	//dp[i][j]表示str[i...j]变成回文串所需替换的最小字符个数
//	for (int i = len - 2; i >= 0; i--)
//	{
//		for (int j = i + 1; j < len; j++)
//		{
//			if (str[i] == str[j])
//			{
//				dp[i][j] = dp[i + 1][j - 1];
//			}
//			else
//			{
//				dp[i][j] = min(dp[i + 1][j - 1],min(dp[i][j-1],dp[i+1][j]))+1;
//			}
//		}
//	}
//	cout << dp[0][len - 1] << endl;
//	//system("pause");
//	return 0;
//}


int main()
{
	int N;
	cin >> N;
	vector<int> arr;//保存起来
	int tmpcrr;
	for (int i = 0; i < N; i++)
	{
		cin >> tmpcrr;
		arr.push_back(tmpcrr);
	}
	int max_res = -1;
	int min_len = 1000000000;
	for (int i = 0; i < N; i++)
	{
		for (int j = i + 1; j < N; j++)
		{
			int tmp = 0;
			for (int k = i; k <= j; k++)
			{
				tmp = tmp | arr[k];
			}
			if (tmp > max_res)
			{
				max_res = tmp;
				min_len = min(min_len, j - i );
			}
		}
	}
	//vector<vector<int>> dp(N,vector<int>(N, 0));
	////dp[i][j]表示[i..j]或起来的最大的数
	//for (int i = 0; i < N; i++)
	//{
	//	dp[i][i] = arr[i];
	//}
	//int max_res = -1;
	//
	//for (int i = N - 2; i >= 0; i--)
	//{
	//	for (int j = i + 1; j < N; j++)
	//	{
	//		int tmp = 0;
	//		for (int k = i; k <= j; k++)
	//		{
	//			tmp = tmp | arr[k];
	//		}
	//		dp[i][j] = max(tmp, max(dp[i][j-1], dp[i + 1][j]));
	//		max_res = max(max_res, dp[i][j]);
	//	}
	//}
	//int min_len = INT_MAX;
	//for (int i = N - 2; i >= 0; i--)
	//{
	//	for (int j = i + 1; j < N; j++)
	//	{
	//		if (dp[i][j] == max_res)
	//		{
	//			min_len = min(min_len, j - i + 1);
	//		}
	//	}
	//}
	cout << min_len << endl;
	system("pause");
	//system("pause");
	return 0;
}