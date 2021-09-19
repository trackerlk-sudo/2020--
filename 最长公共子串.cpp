#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;
//找出两个字符串的最长公共子串

class Solution {
public:
	string getLongestComStr(string str1, string str2)
	{
		string res="";
		int len1 = str1.size();
		if (len1 == 0) return res;
		int len2 = str2.size();
		if (len2 == 0) return res;
		int maxlen = -1;
		int end = 0;
		vector <vector<int>> dp(len1+1, vector<int>(len2+1, 0));
		//dp[i][j] 表示str1[0...i] 和str2[0...j]的最长公共子串长度
		for (int i = 1; i < len1; i++)
		{
			for (int j = 1; j < len2; j++)
			{
				if (str1[i] == str2[j])
				{
					dp[i][j] = dp[i - 1][j - 1] + 1;
				}
				else
				{
					continue;
				}

				if (dp[i][j] > maxlen)
				{
					maxlen = dp[i][j];
					end = i;
				}
			}
		}
		res = str1.substr(end-maxlen+1,maxlen);
		return res;
	}
};

int main()
{
	string str1 = "abcdfesa";
	string str2 = "cbcd1fesafesnvs";

	Solution p;
	cout << p.getLongestComStr(str1, str2)<<endl;
	system("pause");
	return 0;
}