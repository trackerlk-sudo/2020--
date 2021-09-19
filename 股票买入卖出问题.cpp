#include<iostream>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;


//取得利润最大时的，股票的买入卖出时间

int getnum(vector<int>& arr)
{//求最大利润
	int len = arr.size();
	if (len < 1) return 0;
	int maxres = 0;
	int min = arr[0];
	for (int i = 1; i < len; i++)
	{
		if (arr[i] >min)
		{
			maxres = max(maxres, arr[i] - min);
		}
		else
		{
			min = arr[i];

		}
	}
	return maxres;
}

//求获得最大利润时的具体买入卖出下标
void  getindex(vector<int>& arr)
{//求最大利润
	int len = arr.size();
	vector<int> res;
	if (len < 1) return;
	int maxres = 0;//最大利润
	int min = arr[0];//之前的最低股价
	int minday = 0;//之前最小股价的下标
	pair<int, int> buy_in_out_day(0, 0);
	for (int i = 1; i < len; i++)
	{
		if (arr[i] >min)
		{
			if (arr[i] - min > maxres)
			{
				maxres = arr[i] - min;
				buy_in_out_day.first = minday;
				buy_in_out_day.second = i;	//两个下标同时修改
			}
		}
		else
		{
			min = arr[i];
			minday = i;//保存最小下标
		}
	}
	cout << buy_in_out_day.first << " " << buy_in_out_day.second << endl;	
}

void get_day(vector<int>& price) {
	int min_price(1e9);
	int min_price_day(0);
	//![最大利润]
	int max_profit(0);
	std::pair<int, int> buy_in_out_day(0, 0);

	for (int i(0); i < price.size(); ++i) {
		if (min_price > price[i]) {
			min_price = price[i];
			min_price_day = i;
		}
		if (max_profit < price[i] - min_price) {
			max_profit = price[i] - min_price;
			buy_in_out_day.first = min_price_day + 1;
			buy_in_out_day.second = i + 1;
		}
	}
	cout << max_profit << ": " << buy_in_out_day.first << " " << buy_in_out_day.second << endl;
}


void getrealday(vector<int>& arr)
{
	int len = arr.size();
	if (len == 0) return ;
	int minday = 0;//保存之前最小股价的下标
	int min = arr[0];//保存之前最低股价
	int res = 0;
	int start = 0;
	int end = 0;
	for (int i = 1; i < len; i++)
	{
		if (arr[i] >= min)
		{
			if (arr[i] - min > res)
			{
				res = arr[i] - min;
				start = minday;
				end = i;
			}
		}
		else
		{
			min = arr[i];
			minday = i;
		}
	}
	cout << res<<" "<<start << " " << end << endl;
}

int main()
{
	vector<int> arr = {7,8,11,5,4,9,17,1,15,6 };
	//int res = getnum(arr);
	//cout << res << endl;
	//get_day(arr);
	getrealday(arr);
	system("pause");
	return 0;
}


