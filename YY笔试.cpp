#include<iostream>
#include<string>
#include<vector>
#include<set>

using namespace std;

//class Solution {
//public:
//	/**
//	* 将字符串转换为整数输出
//	* @param str string字符串 输入字符串
//	* @return int整型
//	*/
//	int str2Int(string str) {
//		// write code here
//		int i = 0;
//		int flag = 1;
//		long res = 0;
//		if (str[i] == '-')
//		{
//			flag = -1;
//			i++;
//		}
//		for (; i<str.size(); i++)
//		{
//			res = res * 10 + (str[i] - '0');
//			if (res >= INT_MAX && flag == 1) return INT_MAX;
//			if (res <= INT_MIN && flag == -1) return INT_MIN;
//		}
//		return flag*res;
//	}
//};





//class Solution {
//public:
//	bool issqr(int n)
//	{
//		int a = (int)(sqrt(n) + 0.5);
//		return a*a == n;
//	}
//
//	int question(int a, int b) {
//		// write code here
//		for (int i = 1; i < 500; i++)
//		{
//			if (issqr(i + a) && issqr(i + b))
//			{
//				return i;
//			}
//		}
//	}
//};

class Solution {
public:
	/**
	* 翻译组合数
	* @param num int整型 数字加密报文
	* @return int整型
	*/
	int translateNum(int num) {
		// write code here
		string str = to_string(num);
		return getans(str, 0);
	}

	int getans(string str, int start)
	{
		if (start == str.length())
		{
			return 1;
		}
		int ans1 = getans(str, start + 1);
		int ans2 = 0;
		if (start < str.length() - 1)
		{
			int a = (str[start] - '0') * 10;
			int b = str[start + 1] - '0';
			if (a + b <26 && a + b >= 10)
			{
				ans2 = getans(str, start + 2);
			}
		}
		return ans1 + ans2;
	}
};


//int main()
//{
//		Solution p;
//
//		int res = p.question(100, 200);
//		cout << res << endl;
//		system("pause");
//		return 0;
//}

class Solution {
public:
	/**
	*
	* @param values string字符串二维数组
	* @param valuesRowLen int values数组行数
	* @param valuesColLen int* values数组列数
	* @return string字符串vector
	*/
	vector<string> findCommonString(vector<vector<string>>& arr) {
		// write code here
		int high = arr.size();
		if (high <= 1) return arr[0];
		set<string> myset;
		vector<string> res;
		set<string> mysetres;
		for (int i = 0; i < arr[0].size(); i++)
		{
			myset.insert(arr[0][i]);
		}
		for (int i = 0; i < arr[1].size(); i++)
		{
			if (myset.find(arr[1][i]) != myset.end())
			{
				mysetres.insert(arr[1][i]);
			}
		}//先找出前两行的公共的字符串

		for (auto it : mysetres)
		{
			int i;
			int count = 0;
			for (i = 2; i < high; i++)
			{
				int count = 0;
				for (int j = 0; j < arr[i].size(); i++)
				{
					if (arr[i][j] != it)
					{
						count++;

					}
				}
				if (count == arr[i].size())
				{
					mysetres.erase(it);
				}
			}
		}

		for (auto it : mysetres)
		{
			res.push_back(it);
		}
		return res;
	}
};