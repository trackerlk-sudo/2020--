#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main()
{
	int n,m;
	cin >> n >> m;
	vector<vector<int>> arr(n,vector<int>(m,0));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
		}
	}//保存输入数据



}

//int main()
//{
//	string str;
//	cin >> str;
//	int len = str.size();
//	if (len == 1)
//	{
//		cout << char(str[0]-32) << endl;
//		system("pause");
//		//return 0;
//	}
//	vector<string> res;
//	string s = "";
//	for (int i = 0; i < str.size();)
//	{
//		if (i == 0 && str[i] == 'n')
//		{
//			s += "N";
//			res.push_back(s);
//			s = "";
//			i++;
//		}
//		if (str[i] != 'n')
//		{
//			s += str[i];
//			i++;
//		}
//		else {
//			res.push_back(s);
//			s = "n";
//			i++;
//		}
//	}
//	res.push_back(s);
//
//	for (int i = 0; i < res.size(); i++)
//	{
//		res[i][0] = char(res[i][0] - 32);
//		cout << res[i] << endl;
//	}
//	system("pause");
//	return 0;
//}