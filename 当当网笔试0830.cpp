#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
//
//bool ispattern(string str1, string str2)
//{
//	int len1 = str1.size();
//	int len2 = str2.size();
//	if (len1 != len2)
//	{//长度不相等直接返回false
//		return false;
//	}
//	if (len1 == 0) return true;
//	int i = 0;
//	while (i < len1)
//	{
//		if (str1.find(str1[i]) != str2.find(str2[i]))
//		{
//			return false;
//		}
//		i++;
//	}
//	return true;
//}
//
//int main()
//{
//	//模式匹配：首先长度相同，其次字母的个数和出现的次数对应相同
//	vector<string> arr;
//	string str;
//	while (cin >> str)
//	{
//		arr.push_back(str);
//	}
//	int len = arr.size();
//	string  pattern = arr[len - 1];
//
//	vector<string> res;//存放结果
//
//	for (int i = 0; i < len - 1; i++)
//	{
//		if (ispattern(arr[i], pattern))
//		{
//			res.push_back(arr[i]);
//		}
//	}
//	if (res.size() != 0)
//	{
//		for (int i = 0; i < res.size(); i++)
//		{
//			cout << res[i] << " ";
//		}
//	}
//	else
//	{
//		cout << "null" << endl;
//	}
//	system("pause");
//	return 0;
//}


//原木切割问题
//int main()
//{
//	int tmp;
//	vector<int> arr;//保存输入
//	int sum = 0;
//	while (cin >> tmp)
//	{
//		arr.push_back(tmp);
//		sum += tmp;
//		if (getchar() == '\n')
//		{
//			break;
//		}
//	}
//	int k;
//	cin >> k;
//	sort(arr.begin(), arr.end());
//	int len = arr.size();
//	for (int i = arr[len - 1]; i > 0; i--)
//	{//有可能直接舍弃短的，从最长的开始
//		int res = 0;
//		for (int j = len - 1; j >= 0; j--)
//		{
//			res += arr[j] / i;
//			if (res >= k)
//			{
//				cout << i << endl;
//				return 0;
//			}
//		}
//	}
//
//	cout << 0 << endl;
//	return 0;
//}

bool flag = false;
void DFS(vector<int>& arr, int start, int len,int gap,int i)
{
	
	if (start == arr[len - 1])
	{//能达到
		return ;
	}
	if (start!= arr[i])
	{
		return;
	}
	//可以跳三次
	for (int i = -1; i <=1; i++)
	{
		start += gap + i;
		gap = gap+i;
		DFS(arr, start, len, gap,i+1);
		if (flag == true) break;
		gap = gap - i;
		start -= gap + i;
	}
	
}
int main()
{
	vector<int> arr;
	int tmp;
	while (cin >> tmp)
	{
		arr.push_back(tmp);
	}
	int len = arr.size();
	if (arr[1] != 1)
	{
		cout << "false" << endl;
		return 0;
	}
	DFS(arr, 0, len, 1, 0);
	if (flag == true)
	{
		cout << "true" << endl;
	}
	else
	{
		cout << "false" << endl;
	}
	return 0;
}

int main()
{
	vector<int> arr;
	int tmp;
	while (cin >> tmp)
	{
		arr.push_back(tmp);
	}

	cout << "false" << endl;
	return 0;
}