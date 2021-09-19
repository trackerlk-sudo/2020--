//最长会问字串
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	string str;
	cin >> str;
	int len = str.size();

	vector<vector<int>> dp(len, vector<int>(len, 0));
	//dp[i][j]表示str[i]到str[j]是否是回文子串
	for (int i = 0; i < len; i++)
	{
		dp[i][i] = 1;
	}

	int max_len = 1;//最长的长度
	for (int i = len - 2; i >= 0; i--)
	{
		for (int j = i + 1; j < len; j++)
		{
			if (str[i] == str[j])
			{//相等，看中间的
				if (j - i < 3)
				{
					dp[i][j] = 1;
				}
				else
				{
					dp[i][j] = dp[i + 1][j - 1];
				}
			}
			else
			{//不相等
				continue;
			}

			max_len = max(max_len, j - i + 1);
		}
	}

	cout << max_len << endl;
	//system("pause");
	return 0;
}




//最长会问字串
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	string str;
	cin >> str;
	int len = str.size();

	vector<vector<int>> dp(len, vector<int>(len, 0));
	//dp[i][j]表示str[i]到str[j]是否是回文子串
	for (int i = 0; i < len; i++)
	{
		dp[i][i] = 1;
	}

	int max_len = 1;//最长的长度
	for (int i = len - 2; i >= 0; i--)
	{
		for (int j = i + 1; j < len; j++)
		{
			if (str[i] == str[j])
			{//相等，看中间的
				if (j - i < 3)
				{
					dp[i][j] = 1;
				}
				else
				{
					dp[i][j] = dp[i + 1][j - 1];
				}
			}
			else
			{//不相等
				continue;
			}
			//max_len = max(max_len, j - i + 1);
		}
	}

	for (int i = 0; i < len; i++)
	{
		for (int j = i; j < len; j++)
		{
			if (dp[i][j] == 1)
			{
				if (j - i + 1 > max_len)
				{
					max_len = j - i + 1;
				}
			}
		}
	}
	cout << max_len << endl;
	//system("pause");
}