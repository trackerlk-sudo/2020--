#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<algorithm>

using namespace std;

//void DFS(int N, int k,vector<int> &arr, string str, vector<int>& visit);
//
//map<int, int> mymap;
//int cnt = 0;
//void getsum(int N,vector<int> &arr)
//{
//	vector<int> visit(arr.size(), 0);
//	DFS(N, 0, arr, "", visit);
//	if (cnt == 0)
//	{
//		cout << 0 << endl;
//		return;
//	}
//	else
//	{
//		cout << cnt << endl;
//		for (auto it : mymap)
//		{
//			cout << it.first << " " << it.second;
//		}
//	}
//}
//
//void DFS(int N, int k,vector<int> &arr,string str,vector<int>& visit)
//{
//	if (k == 3)
//	{
//		string str2 = "";
//		str2 += str[0];
//		str2 += str[2];
//		str2 += str[2];
//		int a = atoi(str.c_str());
//		int b = atoi(str2.c_str());
//		if ((a+b)== N)
//		{
//			mymap.insert(pair<int, int>(a, b));
//			cnt++;
//		}
//		return;
//	}
//	if (k > 3) return;
//	for (int i = 0; i < arr.size(); i++)
//	{
//		if (visit[i] == 0)
//		{//还没被访问过
//			visit[i] = 1;
//			str += to_string(arr[i]);
//			DFS(N, k + 1,arr, str, visit);
//			str = str.substr(0, str.size() - 1);
//			visit[i] = 0;
//		}
//	}
//}
//
//int main()
//{
//	int N;
//	cin >> N;
//	vector<int> arr = { 0,1,2,3,4,5,6,7,8,9 };
//	getsum(N, arr);
//	system("pause");
//	return 0;
//}

int main()
{
	int N;
	cin >> N;
	if (N < 1) return 0;
	if (N == 1)
	{
		cout << 1 << endl;
		return 0;
	}
	int len = N*N;
	vector<int> arr(len, 0);
	arr[0] = 1;
	arr[1] = 1;
	for (int i = 2; i < len; i++)
	{
		arr[i] = arr[i - 1] + arr[i - 2];
	}//记录所需要的斐波拉契数列，保存在arr中
	reverse(arr.begin(), arr.end());

	vector<vector<int>> res(N, vector<int>(N, 0));
	//设置4个边界
	int up = 0;
	int down = N - 1;
	int left = 0;
	int right = N - 1;
	int k = 0;//指向一维数组
	while (up <= down && left <= right)
	{
		for (int i = left; i <= right; i++)
		{
			res[up][i] = arr[k++];
		}
		if (++up > down) break;
		for (int i = up; i <= down; i++)
		{
			res[i][right] = arr[k++];
		}
		if (--right < left) break;

		for (int i = right; i >= left; i--)
		{
			res[down][i] = arr[k++];
		}
		if (--down < up) break;
		for (int i = down; i >=up; i--)
		{
			res[i][left] = arr[k++];
		}
		if (++left > right) break;
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << res[i][j] << " ";
		}
		cout << endl;
	}
	system("pause");
	return 0;
}