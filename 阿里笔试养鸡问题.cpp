#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


/*三、小强有n个养鸡场，第i个养鸡场初始是有a[i]只小鸡，小强的每个养鸡场每天都会增加k只小鸡，另外每天结束的时候，
都会在数量最多的养鸡场里卖掉一半的小鸡，即若当前最多的养鸡场有x只小鸡，经过贩卖后，当前养鸡场会剩下x / 2只，
问你经过m天后，小强的n个养鸡场里一共有多少只小鸡

输入描述：

第一行输入三个正整数n，m和k
第二行输入n个正整数，分别表示n个养鸡场初始鸡的个数
1 <= m <= 100000
1 <= n <= 100000
1 <= k <= 10000
1 <= a[i] <= 100000

输出描述：

输出一个整数表示答案
示例1：

输入

3 3 100
100 200 400

输出

925*/

//int main()
//{
//	int n, m, k;
//	cin >> n >> m >> k;
//	vector<int> arr(n,0);
//	for (int i = 0; i < n; i++)
//	{
//		cin >> arr[i];
//	}
//	//sort(arr.begin(), arr.end());//先排序
//	for (int i = 0; i < m; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			arr[j] += k;//每个先增加k只
//		}
//		sort(arr.rbegin(), arr.rend());//再排序,从大到小排
//		arr[0] /= 2;//最大的减半
//	}
//	int sum = 0;//求和
//	for (int i = 0; i < arr.size(); i++)
//	{
//		sum += arr[i];
//	}
//	cout << sum << endl;
//	system("pause");
//	return 0;
//}

/*二、小强现在有n个节点，他想请你帮他计算出有多少种不同的二叉树满足节点个数为n且树的高度不超过m的方案，
因为答案很大，所以答案需要模上 1e9+7后输出。树的高度定义为所有叶子到根路径上节点个数的最大值。

输入描述：

第一行输入两个正整数n和m
1<=m<=n<=50

输出描述：

输出一个答案表示方案数


示例： 输入 3 3 ， 输出 5*/

const int mod = 1e9 + 7;
int main()
{
	int n, m;
	cin >> n >> m;
	vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
	//dp[i][j]表示i个节点，不超过j层的方案数
	for (int i = 0; i <= m; i++)
	{
		dp[0][i] = 1;//0个节点，构成任何的都是空节点
	}

	for (int i = 1; i <= n; i++)
	{//dp填表
		for (int j = 1; j <= m; j++)
		{
			for (int k = 0; k < i; k++)
			{//k表示k个节点在左边（右边）
				dp[i][j] = (dp[i][j] % mod + dp[k][j - 1] * dp[i - k - 1][j - 1] % mod) % mod;
				//去掉一个根节点，k个节点在左边构成不超过j-1层的方案数dp[k][j-1]*剩下的i-k-1个节点在右边构成不超过j-1层方案数dp[i-k-1][j-1]
				//k依次从0到i-1增加，累加所有方案
			}
		}
	}
	cout << dp[n][m] << endl;
	system("pause");

	return 0;
}


//const int mod = 1e9 + 7;
//vector<vector<long long int>> dp(55, vector<long long int>(55, 0));
//int main()
//{
//	int n, m;
//	cin >> n >> m;
//	for (int i = 1; i <= n; i++)
//	{
//		dp[0][i - 1] = 1;
//		for (int j = 1; j <= n; j++)
//		{
//			for (int k = 0; k < j; k++)
//			{
//				dp[j][i] = (dp[j][i] % mod + dp[k][i - 1] * dp[j - k - 1][i - 1] % mod) % mod;
//			}
//		}
//	}
//	cout << dp[n][m] << endl;
//	system("pause");
//
//	return 0;
//}
