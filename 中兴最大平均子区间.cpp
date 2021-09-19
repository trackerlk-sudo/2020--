#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//int main()
//{
//	int n;
//	cin >> n;
//	vector<int> arr(n,0);
//	int maxcin = -1;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> arr[i];
//		maxcin = max(maxcin, arr[i]);
//	}//保存数组
//	vector<vector<int>> dp(n, vector<int>(n, 0));
//	//dp[i][j]表示下标i到j的和
//	for (int i = 0; i < n; i++)
//	{
//		dp[i][i] = arr[i];
//	}
//	int max_res = maxcin;
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = i + 1; j < n; j++)
//		{
//			dp[i][j] = dp[i][j - 1] + arr[j];
//			max_res = max(max_res, dp[i][j]/(j - i + 1));
//		}
//	}
//	cout << max_res << endl;
//	system("pause");
//	return 0;
//}

int main()
{
	int n;
	cin >> n;
	vector<int> arr(n, 0);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}//保存数组
	vector<int> dp(n+1,0);
	//dp[i]表示前i项的和
	for (int i = 1; i <= n; i++)
	{
		dp[i] = dp[i - 1] + arr[i-1];
	}
	int max_res = -1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = i - 1; j >= 0; j--)
		{
			max_res = max(max_res, ((dp[i] - dp[j])/(i - j)));
		}
	}
	
	cout << max_res << endl;
	system("pause");
	return 0;
}

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << 1 << endl;
	}
	return 0;
}