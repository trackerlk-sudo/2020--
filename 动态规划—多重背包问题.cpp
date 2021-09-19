#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int N,V;
	cin >> N >> V;
	vector<vector<int>> arr(N, vector<int>(3, 0));
	for (int i = 0; i < N; i++)
	{
		cin >>arr[i][0]>>arr[i][1]>>arr[i][2];
	}//每个物品数量有限制了

	vector<vector<int> > dp(N + 1, vector<int>(V + 1, 0));
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= V; j++)
		{
			for (int k = 0; k<=arr[i-1][2] && j>=k*arr[i - 1][0]; k++)
			{
				dp[i][j] = max(dp[i][j], dp[i - 1][j - k*arr[i - 1][0]] + k*arr[i - 1][1]);
			}
		}
	}
	cout << dp[N][V] << endl;
	system("pause");
	return 0;
}