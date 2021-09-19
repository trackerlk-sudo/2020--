#include<iostream>
#include<string>

using namespace std;
int mymatch(const char* str1, const char * substr)
{
	int i = 0;
	int j = 0;
	int len1 = strlen(str1);
	int len2 = strlen(substr);
	while (i < len1 && j < len2)
	{
		if (str1[i] == substr[j])
		{
			i++;
			j++;
		}
		else
		{
			i = i - j + 1;//后退到下一个开始位置
			j = 0;
		}
	}
	if (j == len2)
	{
		return i - j;
	}
	return -1;
}

void my_strcopy(char* sources, const char * target)
{
	if (sources == NULL || target == NULL) return;
	while ((*sources++ = *target++)!='\0')
	{
	}
	*sources == '\0';
}
int main()
{
	string str1;
	string str2;
	cin >> str1 >> str2;
	cout << str1.size() << endl;
	cout << str2.size() << endl;
	int len = str1.size();
	char * str3 = (char*)malloc(len + 1);
	my_strcopy(str3, str1.c_str());
	cout << strlen(str3) << endl;
	cout << str3 << endl;
	//int res = mymatch(str1.c_str(), str2.c_str());
	//cout << res << endl;
	system("pause");
	return 0;
}