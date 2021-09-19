#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<algorithm>

using namespace std;
//int getnum(int a, int b, int& x, int &y)
//{
//	if (b == 0)
//	{
//		x = 1;
//		y = 0;
//		return a;
//	}
//	else
//	{
//		int r = getnum(b, a%b, x, y);
//		int t = x - a / b*y;
//		x = y;
//		y = t;
//		return r;		
//	}
//}
//
//int main()
//{
//	int a, b,x,y;
//	cin >> a >> b;
//	getnum(a, b, x, y);
//	while (x < 0) x += b;
//	cout << x << endl;
//	system("pause");
//	return 0;
//}

struct Point {
	int x;
	int y;
	bool operator <(const Point a)const
	{
		return this->x < a.x;
	}
}p[100001];

int main()
{
	int n, k;
	cin >> n >> k;
	int a, b;
	for (int i = 0; i < n; i++)
	{
		cin >> p[i].x >> p[i].y;
	}
	sort(p + 1, p + n + 1);
	
	//set<double> myset;
	//for (int i = 0; i < n; i++)
	//{
	//	for (int j = i + 1; j < n; j++)
	//	{
	//		if (arr[j][0] == arr[i][0])
	//		{
	//			continue;//Ð±ÂÊ²»´æÔÚ
	//		}
	//		else {
	//			double tmp = (arr[j][1] - arr[i][1])/((arr[j][0]-arr[i][0])*1.0);
	//			myset.insert(tmp);
	//		}
	//	}
	//}
	int len = myset.size();
	auto it = myset.begin();
	for (int i = 0; i < len - k; it++, i++)
	{
		continue;
	}
	cout << floor(*it) << endl;
	system("pause");
	return 0;
}
