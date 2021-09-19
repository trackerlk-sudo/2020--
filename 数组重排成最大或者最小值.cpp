#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

//给定一个数组，将数组中的数组进行重排构成最大值或者最小值
//class Solution {
//public:
//	 int  minNumber(vector<int>& nums){
//		vector<string> arr;
//		for (auto num : nums)
//		{
//			arr.push_back(to_string(num));
//		}
//		sort(arr.begin(), arr.end(),compare);
//		string res;
//		for (auto str : arr)
//		{
//			res += str;
//		}
//		return atoi(res.c_str());
//	}
//
//	static bool compare(const string& str1, const string& str2)
//	{
//		return str1 + str2 < str2 + str1;
//	}
//};
bool compare(const string& str1, const string& str2)
{//自定义排序规则
	return str1 + str2 > str2 + str1;
}
int minNumber(vector<int>& nums) {
	vector<string> arr;
	for (auto num : nums)
	{
		arr.push_back(to_string(num));
	}
	sort(arr.begin(), arr.end(), compare);//按照规则排序
	string res;
	for (auto str : arr)
	{
		res += str;
	}
	return atoi(res.c_str());//string先转char* ，再传入atoi函数，字符串转整数
}


int main()
{
	vector<int> arr = { 10,2,51,3 };
	cout<<minNumber(arr)<<endl;
	system("pause");
}