#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main()
{
	string str;
	int n;
	cin >> str;
	cin >> n;

	vector<vector<int>> arr(n, vector<int>(2, 0));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			cin >> arr[i][j];
		}
	}//±£´æÊý¾Ý

	for (int i = 0; i < str.size(); i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (str[i] - '0' == arr[j][0])
			{
				str[i] =(char) arr[j][1];
			}
		}
	}
	cout << str << endl;
	system("pause");
	return 0;
}