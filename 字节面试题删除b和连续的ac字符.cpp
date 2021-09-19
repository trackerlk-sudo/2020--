#include<iostream>
#include<string>

using namespace std;

string func(string str)
{
	int countA = 0;//a的个数
	string res = "";
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == 'a')
		{
			countA++;
		}
		else if (str[i] == 'b')
		{
			continue;
		}
		else if (str[i] == 'c')
		{
			if (countA == 0)
			{//前面没a
				res += "c";
			}
			else {
				countA--;
			}
		}
		else {//其他字符
			while (countA)
			{//还要多少个a没被处理的，需要加上
				res += 'a';
				countA--;
			}
			res += str[i];
		}
	}
	while (countA)
	{
		res += "a";
		countA--;
	}
	return res;
}


int a = 0;
void func1()
{
	a++;
}

void func2()
{
	a++;
}

int main()
{
	string str;
	getline(cin, str);
	string res = func(str);
	cout << res << endl;


	system("pause");
	return 0;
}