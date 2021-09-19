#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	string str1;
	cin >> str1;
	int flag = 0;//¶ººÅ·Ö¸ô
	for (int i = 0; i < str1.size(); i++)
	{
		if (str1[i] == '£¬')
		{
			flag = i;
			break;
		}
	}
	string v1 = "";
	string v2 = "";
	for (int i = 0; i < flag; i++)
	{
		v1 += str1[i];
	}
	for (int i = flag + 1; i < str1.size(); i++)
	{
		v2 += str1[i];
	}
	int m = 0;
	int n = 0;
	while (m < v1.size() || n < v2.size())
	{
		if (v1[m] == '.')
		{
			m++;
		}
		if (v2[n] == '.')
		{
			n++;
		}
		if (m < v1.size() && n < v2.size() &&v1[m] - '0' > v2[n] - '0')
		{
			cout << 1 << endl;
			return 0;
		}
		else if(m < v1.size() && n < v2.size() && v1[m] - '0' < v2[n] - '0')
		{
			cout << -1 << endl;
			return 0;
		}
		else
		{
			cout << 0 << endl;
			return 0;
		}
	}
	//cout << len << endl;
	//system("pause");
	return 0;
}