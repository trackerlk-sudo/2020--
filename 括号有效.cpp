#include<iostream>
#include<vector>
#include<string>
#include<stack>

using namespace std;



bool isValid(string s) {
	int len = s.length();
	stack<char> st;
	if (len == 0) return true;
	for (int i = 0; i<len; i++)
	{
		if (s[i] == '(' || s[i] == '{' || s[i] == '[')
		{
			st.push(s[i]);
		}
		else//遇见右边的括号了
		{
			if (!st.empty() && charof(s[i]) == st.top())
			{
				st.pop();//弹出
			}
			else return false;
		}
	}
	if (!st.empty()) return false;
	return true;
}
char charof(char c)//右括号相应变为左括号
{
	if (c == ')') return '(';
	if (c == '}') return '{';
	return '[';
}

int main() 
{
	string str;
	getline(cin, str);
	if(isValid(str))
	{
		cout << "True" << endl;
	}
	else
	{
		cout << "False" << endl;
	}
	return 0;
}