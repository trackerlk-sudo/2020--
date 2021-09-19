#include<iostream>
#include<vector>
#include<string>

using namespace std;

//class Solution {
//public:
//	/**
//	* 逆时针旋转矩阵
//	* @param matrix int整型vector<vector<>> 输入矩阵
//	* @return int整型vector<vector<>>
//	*/
//	vector<vector<int> > RotateMatrix(vector<vector<int> >& matrix) {
//		// write code here
//		int len = matrix[0].size();
//		int high = matrix.size();
//
//		for (int i = 1; i <high; i++)
//		{
//			for (int j = 0; j <i; j++)
//			{
//				int tmp = matrix[i][j];
//				matrix[i][j] = matrix[j][i];
//				matrix[j][i] = tmp;
//			}
//		}//对角线翻转
//
//		for (int i = 0; i < high / 2; i++)
//		{
//			for (int j = 0; j < len; j++)
//			{
//				int tmp = matrix[i][j];
//				matrix[i][j]=matrix[high - 1 - i][j];
//				matrix[high - 1 - i][j] = tmp;
//			}
//		}//上下翻转
//
//		return matrix;
//	}
//};
//
//int main()
//{
//	vector<vector<int>> arr = { {0,1,2},{3,4,5},{6,7,8} };
//	Solution p;
//	arr = p.RotateMatrix(arr);
//
//	for (int i = 0; i < arr.size(); i++)
//	{
//		for (int j = 0; j < arr[0].size(); j++)
//		{
//			cout << arr[i][j] << " ";
//		}
//		cout << endl;
//	}
//	system("pause");
//	return 0;
//}


//通过版本
class Solution {
public:
	/**
	* 逆时针旋转矩阵
	* @param matrix int整型vector<vector<>> 输入矩阵
	* @return int整型vector<vector<>>
	*/
	vector<vector<int> > RotateMatrix(vector<vector<int> >& matrix) {
		// write code here
		int len = matrix[0].size();
		int high = matrix.size();

		for (int i = 1; i <high; i++)
		{
			for (int j = 0; j <i; j++)
			{
				int tmp = matrix[i][j];
				matrix[i][j] = matrix[j][i];
				matrix[j][i] = tmp;
			}
		}//对角线翻转

		for (int i = 0; i < high / 2; i++)
		{
			for (int j = 0; j < len; j++)
			{
				int tmp = matrix[i][j];
				matrix[i][j] = matrix[high - 1 - i][j];
				matrix[high - 1 - i][j] = tmp;
			}
		}//上下翻转

		return matrix;
	}
};


//最长公共子串
class Solution {
public:
	/**
	* 找出字符串中最大公共子字符串
	* @param str1 string字符串 输入字符串1
	* @param str2 string字符串 输入字符串2
	* @return string字符串
	*/
	string GetCommon(string str1, string str2) {
		// write code here
		int len1 = str1.size();
		int len2 = str2.size();
		int maxlen = 0;
		int maxend = 0;
		string res;
		vector<vector<int>> dp(len1+1, vector<int>(len2+1, 0));

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
					maxend = i;
				}
			}
		}
		res = str1.substr(maxend - maxlen + 1, maxlen);
		return res;
	}
};

int main()
{
	string str1 = "abccade";
	string str2 = "dgcadde";
	Solution p;
	string res = p.GetCommon(str1, str2);
	cout << res << endl;
	system("pause");
	return 0;
}

//通过版本
class Solution {
public:
	/**
	* 找出字符串中最大公共子字符串
	* @param str1 string字符串 输入字符串1
	* @param str2 string字符串 输入字符串2
	* @return string字符串
	*/
	string GetCommon(string str1, string str2) {
		// write code here
		string res = "";
		int len1 = str1.size();
		if (len1 == 0) return res;
		int len2 = str2.size();
		if (len2 == 0) return res;
		int maxlen = 0;
		int maxend = 0;
		vector<vector<int>> dp(len1, vector<int>(len2, 0));

		for (int i = 0; i <len1; i++)
		{
			for (int j = 0; j <len2; j++)
			{
				if (str1[i] == str2[j])
				{
					if (i == 0 || j == 0)
					{
						dp[i][j] = 1;
					}
					else
					{
						dp[i][j] = dp[i - 1][j - 1] + 1;
					}
				}
				else
				{
					continue;
				}

				if (dp[i][j] > maxlen)
				{
					maxlen = dp[i][j];
					maxend = i;
				}
			}
		}
		res = str1.substr(maxend - maxlen + 1, maxlen);
		return res;
	}
};