#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

//int main()
//{
//	int N;
//	cin >> N;
//	vector<vector<int>> arr(N, vector<int>(N, 0));
//	for (int i = 0; i < N; i++)
//	{
//		for (int j = 0; j < N; j++)
//		{
//			cin >> arr[i][j];
//		}
//	}
//
//	for (int i = 0; i < N; i++)
//	{
//		for (int j = 0; j < N; j++)
//		{
//			cout << arr[j][i] << " ";
//		}
//		cout << endl;
//	}
//	return 0;
//}

//int main()
//{
//	int x;
//	cin >> x;
//	if (x % 3 != 0)
//	{
//		cout << -1 << endl;
//		return 0;
//	}
//	int count = 0;
//	while (x % 3 == 0)
//	{
//		x = x / 3;
//		count++;
//	}
//	if (x == 1)
//	{
//		cout << count << endl;
//	}
//	else
//	{
//		cout << -1 << endl;
//	}
//	system("pause");
//	return 0;
//}

int main()
{
	int N;
	cin >> N;
	string str;
	cin >> str;
	int i = 0;
	int len = str.size();
	while (i < len)
	{
		while (!(i + 3 < len && str[i] == 'A' && str[i + 1] == 'T' && str[i + 2] == 'G'))
		{
			i++;
		} 
		//循环结束，找到起始位置了

		int j = i + 3;
	
	}
	cout << res << endl;
	system("pause");
	return 0;
}

//磁链判断
//bool islegal(string str1, string str2)
//{
//	int len1 = str1.size();
//	int len2 = str2.size();
//	if (len1 != len2) return false;
//	int flag = 0;
//	for (int i = 0; i < len1; i++)
//	{
//		if (str1[i] == str2[i])
//		{
//			continue;
//		}
//		else
//		{
//			flag++;
//		}
//	}
//	if (flag == 1) return true;
//	else return false;
//}
//int main()
//{
//	int N;
//	cin >> N;
//	vector<string> arr;
//	for (int i = 0; i < N; i++)
//	{
//		string str;
//		cin >> str;
//		arr.push_back(str);
//	}
//	int count = 0;
//	for (int i = 1; i < N; i++)
//	{
//		if (!islegal(arr[i], arr[i - 1]))
//		{
//			count++;
//		}
//	}
//	cout << count << endl;
//	return 0;
//}