#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;
int getlength(string str, char A, char B)
{
	int len = str.size();
	int i = 0;
	int j = len - 1;
	while (i<len && str[i] != A)
	{
		i++;
	}
	while (j>=0 && str[j] != B)
	{
		j--;
	}
	if (i == len || j == -1)
	{
		return -1;
	}
	return j - i;
}

//int main()
//{
//	string str;
//	char a;
//	char b;
//	cin >> str >> a >> b;
//	//将字符串全部变为大写
//	if (a >= 'a' && a <= 'z') a = a - 32;
//	if (b >= 'a' && b<= 'z') b = b - 32;
//	int len = str.size();
//	for (int i = 0; i < len; i++)
//	{
//		if (str[i] >= 'a' && str[i] <= 'z')
//		{//小写转大写
//			str[i] -= 32;
//		}
//	}
//	int res = max(getlength(str, a, b), getlength(str, b, a));
//
//	cout << res<< endl;
//	system("pause");
//	return 0;
//}

long long int MOD = 1000000007;

int main()
{
	int x, y, z, N;
	cin >> x >> y >> z >> N;
	vector<vector<int>> arr(3, vector<int>(2, 0));
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			cin >> arr[i][j];
		}
	}//保存数据
	vector<int> arrA(N + 1, 0);
	arrA[0] = x;
	vector<int> arrB(N + 1, 0);
	arrB[0] = y;
	vector<int> arrC(N + 1, 0);//分别表示过了i天后的数量
	arrC[0] = z;
	for (int i = 1; i <= N; i++)
	{
		arrA[i]=(arrA[i-1]%MOD)+((arrB[i - 1]%MOD) * (arr[1][0] % MOD) + (arrC[i - 1] % MOD) * (arr[2][0] % MOD));
		arrB[i] = (arrB[i - 1] % MOD) + ((arrA[i - 1] % MOD) * (arr[0][0] % MOD) + (arrC[i - 1] % MOD) * (arr[2][1] % MOD));
		arrC[i] = (arrC[i - 1] % MOD) + ((arrA[i - 1] % MOD) * (arr[0][1] % MOD) + (arrB[i - 1] % MOD) * (arr[1][1] % MOD));
	}
	cout << arrA[N]%MOD << " " << arrB[N] % MOD << " " << arrC[N] % MOD << endl;
	system("pause");
	return 0;
}