#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main()
{
	string str1;
	cin >> str1;
	int i = 0;
	int len = str1.size();
	vector<string> res;
	while (i < len)
	{
		string crr = "";
		while (i<len && str1[i]!='.')
		{
			crr += str1[i];
			i++;
		}
		res.push_back(crr);
		crr = "";
		i++;
	}
	string nstr = "";
	for (int i = res.size() - 1; i >= 0; i--)
	{
		nstr += res[i];
		nstr += ".";
	}
	nstr = nstr.substr(0, nstr.size() - 1);
	cout << nstr << endl;
	system("pause");
	return 0;
}