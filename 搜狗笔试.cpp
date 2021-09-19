#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
	/**
	* 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
	* 返回能交换奖品的最大数量
	* @param a int整型
	* @param b int整型
	* @param c int整型
	* @return int整型
	*/
	int numberofprize(int a, int b, int c) {
		// write code here
		vector<int> arr;
		arr.push_back(a);
		arr.push_back(b);
		arr.push_back(c);

		sort(arr.begin(), arr.end());
		long long int res = 0;
		res += arr[0];
		long long int tmp = arr[0];
		for (int i = 0; i < 3; i++)
		{
			arr[i] = arr[i] - tmp;
		}
		if (arr[1] + arr[2] < 4) return res;

		while (arr[1] > 0)
		{
			arr[1] -= 2;
			arr[2] -= 2;
			res++;
		}
		if (arr[1] == -1)
		{//最后一次不能计入
			arr[1] += 2;
			arr[2] += 2;
			res--;

			if (arr[2] >= 3)
			{
				res++;
				arr[2] -= 3;
			}
			res += (arr[2] / 5);
			return res;
		}
		else if (arr[1] == 0)
		{
			res += (arr[2] / 5);
			return res;
		}
	}
};

int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	Solution p;
	cout << p.numberofprize(a, b, c) << endl;
	system("pause");
	return 0;
}

//class Solution {
//public:
//	/**
//	* 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
//	* 返回能创建的房屋数
//	* @param t int整型 要建的房屋面宽
//	* @param xa int整型一维数组 已有房屋的值，其中 x0 a0 x1 a1 x2 a2 ... xi ai 就是所有房屋的坐标和房屋面宽。 其中坐标是有序的（由小到大）
//	* @param xaLen int xa数组长度
//	* @return int整型
//	*/
//	int getHouses(int t, int* xa, int xaLen) {
//		// write code here
//		int res = 0;
//		for (int i = 0; i <= xaLen - 4; i += 2)
//		{
//			double pre = xa[i] + xa[i + 1] / 2.0;//当前起点
//			if (xa[i + 2] > pre + t)
//			{
//				res += 2;
//			}
//			else if (xa[i + 2] == pre + t)
//			{
//				res += 1;
//			}
//		}
//		res += 2;
//		return res;
//	}
//};
//
//int main()
//{
//	Solution p;
//	int a[4] = { -1,4,5,2 };
//	cout << p.getHouses(2, a, 4) << endl;
//	system("pause");
//	return 0;
//}