#include<iostream>
#include<string>
#include<vector>
#include<map>

using namespace std;

bool isSameStr(string str1, string str2)
{//判断子串串是否是同一类，字符串中的字符及其个数一样，返回true
	int len1 = str1.size();
	int len2 = str2.size();
	if (len1 != len2) return false;
	map<char, int> mymap1;
	map<char, int> mymap2;
	for (int i = 0; i < len1; i++)
	{
		mymap1[str1[i]]++;
		mymap2[str2[i]]++;
	}

	return mymap1 == mymap2 ? true: false;
}

//int main()
//{
//	int N;
//	cin >> N;
//	vector<string> arr;
//	for (int i = 0; i < N; i++)
//	{
//		string tmp;
//		cin >> tmp;
//		arr.push_back(tmp);
//	}
//	if (N == 1) cout << "1" << endl;
//	vector<string> diffarr;//存放不同类别的字符串
//	diffarr.push_back(arr[0]);//先放入第一个
//	int j;
//	for (int i = 1; i < N; i++)
//	{
//		int length = diffarr.size();
//		for (j = 0; j < length; j++)
//		{
//			if (arr[i].size()==diffarr[j].size() && isSameStr(arr[i], diffarr[j]))
//			{//是同一类
//				break;
//			}
//		}
//		if (j == length)
//		{//遍历完都不是同一类，新类别产生
//			diffarr.push_back(arr[i]);
//		}
//	}
//	cout << diffarr.size() << endl;
//	system("pause");
//	return 0;
//}

int main()
{
	string str1;
	string str2;
	cin >> str1;
	cin >> str2;
	int len1 = str1.size();
	int len2 = str2.size();
	string::iterator it = find(str2.begin(), str2.end(), '*');
	if (it == str2.end())
	{//没有*，那么长度如果不一致，则肯定不匹配
		if (len1 != len2)
		{
			cout << "NO" << endl;
			return 0;
		}
	}
	if (len2 == 2 && str2[0] == '.' && str2[1] == '*')
	{
		cout << "YES" << endl;
	}
	system("pause");
	return 0;
}