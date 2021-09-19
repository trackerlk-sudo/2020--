#include<iostream>
#include<string>

using namespace std;

int getnum(int n, int m)
{//求最大公约数
	int m_max;
	int m_min;
	if (n > m)
	{
		m_max = n;
		m_min = m;
	}
	else {
		m_max = m;
		m_min = n;
	}
	int y=-1;
	while (m_max%m_min!=0)
	{
		m_max = m_min;
		m_min = m_max / m_min;	
	}
	return m_min;
}


int main()
{
	string str;
	getline(cin, str);
	int a = atoi(str.substr(0,1).c_str());
	int b= atoi(str.substr(2, 1).c_str());
	int c= atoi(str.substr(6, 1).c_str());
	int d= atoi(str.substr(8, 1).c_str());
	
	if (str[4] == '+')
	{
		int down = b*d;
		int up = a*d + c*b;
		int a = getnum(down, up);//获取最小公倍数

		down = down / a;
		up = up / a;
		string str = "";
		str += to_string(up);
		str += "/";
		str += to_string(down);
		cout << str << endl;
	}
	else if (str[4] == '-')
	{
		int down = b*d;
		int up = a*d - c*b;
		int flag = 0;
		int a;
		if (up < 0)
		{
			flag = 1;
			a=getnum(down, -up);//获取最小公倍数
		}
		else {
			a=getnum(down, up);//获取最小公倍数
		}

		down = down / a;
		up = up / a;
		string str = "";
		/*if (flag == 1)
		{
			str += "-";
		}*/
		str += to_string(up);
		str += "/";
		str += to_string(down);
		cout << str << endl;
	}
	else if (str[4] == '*')
	{
		int down = b*d;
		int up = a*c;
		int a = getnum(down, up);//获取最小公倍数

		down = down / a;
		up = up / a;
		string str = "";
		str += to_string(up);
		str += "/";
		str += to_string(down);
		cout << str << endl;
	}
	else if (str[4] == '/')
	{
		int down = b*c;
		int up = a*d;
		int a = getnum(down, up);//获取最小公倍数


		down = down / a;
		up = up / a;
		string str = "";
		str += to_string(up);
		str += "/";
		str += to_string(down);
		cout << str << endl;
	}
	system("pause");
	return 0;
}