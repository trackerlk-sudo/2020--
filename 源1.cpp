#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

string to_binary(int N)
{//转二进制
	int tmp = N;
	int i;
	string res = "";
	while (tmp)
	{
		i = tmp %2;
		res += to_string(i);
		tmp /= 2;
	}
	reverse(res.begin(),res.end());
	return res;
}

//整数转2进制
int main()
{
	int N;
	cin >> N;
	//cout << to_binary(N) << endl;
	cout << to_ibinary(N) << endl;
	system("pause");
	return 0;
}



