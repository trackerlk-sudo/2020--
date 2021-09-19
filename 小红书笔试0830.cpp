#include <iostream>
#include <vector>
#include<string>
#include <numeric>
#include <limits>

using namespace std;


/*请完成下面这个函数，实现题目要求的功能
当然，你也可以不按照下面这个模板来作答，完全按照自己的想法来 ^-^
******************************开始写代码******************************/
vector < string > splitMsg() {
	string str = "";
	string tmp;
	vector < string > res;
	cin >> tmp;
	int len = tmp.size();
	int k = 1;
	for (int i = 0; i < len; i++)
	{
		if (tmp[i] != '.'  && tmp[i] != ';' && tmp[i] != '!')
		{
			str += tmp[i];
		}
		else
		{
			string crr = "msg";
			crr += char(k);
			crr += ":";
			str = crr + str;
			res.push_back(str);
			k++;
		}
	}
	return res;
}
/******************************结束写代码******************************/


int main() {
	vector < string > res;


	res = splitMsg();
	for (int res_i = 0; res_i < res.size(); res_i++) {
		cout << res[res_i] << endl;;
	}

	return 0;

}