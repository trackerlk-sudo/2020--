#include<iostream>
#include<vector>
#include<map>

using namespace std;
//输入二维数组，如果某一行的对应列与另一行的对应列的和都相等，则认为是完美对
/*比如： 3 3(行列数)
         1 2 4
	     4 3 1
		 5 2 3
		 */
//int main()
//{
//	int n, m;
//	cin >> n >> m;
//
//	return 0;
//}


//int main()
//{
//	int n, k;
//	cin >> n >> k;
//	int a[15];
//	int ans = 0;
//	map<vector<int>, int> mymap;//key为vector，value是值
//	for (int i = 0; i < n; i++)
//	{//n行
//		vector<int> arr;
//		for (int j = 1; j <= k; j++)
//		{
//			cin >> a[j];//k不超过10,，用15大小的数组依次存放
//		}
//		for (int j = 2; j <= k; j++)
//		{
//			arr.push_back(a[j] - a[j - 1]);//保存差值
//		}
//		ans += mymap[arr];
//		for (int j = 0; j < arr.size(); j++)
//		{
//			arr[j] = -arr[j];//置为负值
//		}
//		mymap[arr]++;
//
//	}
//	cout << ans << endl;
//	system("pause");
//	return 0;
//}

//改进方法，利用map，映射vector容器和值
//如果对应列相加和相等，那么相邻的差互为相反数
int main()
{
	int n, k;
	cin >> n >> k;
	vector<vector<int>> arr(n,vector<int>(k, 0));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < k; j++)
		{
			cin >> arr[i][j];
		}
	}//保存输入

	int count = 0;//完美对数
	map<vector<int>,int> mymap;//映射关系，差值为相反数即可认为是完美对

	for (int i = 0; i < n; i++)
	{
		vector<int> ans;//保存差值
		for (int j = 1; j < n; j++)
		{
			ans.push_back(arr[i][j] - arr[i][j - 1]);
		}
		count+= mymap[ans];
		for (int v = 0; v < ans.size(); v++)
		{//取相反数
			ans[v] = -ans[v];
		}
		mymap[ans]++;//存入map容器
	}
	cout << count << endl;
	system("pause");
	return 0;
}


//暴力法超时
//int main()
//{
//	int n, k;
//	cin >> n >> k;
//	vector<vector<int>> arr(n,vector<int>(k, 0));
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < k; j++)
//		{
//			cin >> arr[i][j];
//		}
//	}
//	int count = 0;
//
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = i + 1; j < n; j++)
//		{
//			int sum = arr[i][0] + arr[j][0];
//			int k;
//			for (k = 1; k < arr[i].size(); k++)
//			{
//				if (arr[i][k] + arr[j][k] != sum)
//				{
//					break;
//				}
//			}
//			if (k == arr[i].size())
//			{
//				count++;
//			}
//				
//		}
//	}
//	cout << count << endl;
//	system("pause");
//	return 0;
//}



