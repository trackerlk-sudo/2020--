#include<iostream>
#include<vector>
using namespace std;

//void  getday(vector<int>& arr)
//{
//	int len = arr.size();
//	if (len == 0) return;
//	int start = 0;
//	int minindex = 0;
//	int end = 0;
//	int maxres = 0;
//	int minnum = arr[0];
//	for (int i = 0; i < len; i++)
//	{
//		if (arr[i] < minnum)
//		{
//			minnum = arr[i];
//			minindex = i;
//		}
//		else
//		{
//			if (arr[i] - minnum > maxres)
//			{//起止位置一起变
//				maxres = arr[i] - minnum;
//				start = minindex;
//				end = i;
//			}
//		}
//	}
//	cout << start << " " << end << endl;
//}
//
//int main()
//{
//	vector<int> arr = {5,1,2,6,7,2,6};
//	getday(arr);
//	system("pause");
//	return 0;
//}

int main()
{
	char * a[] = { "work","at","alibaba" };
	char **p = a;
	p++;
	printf("%s\n", *p);
	system("pause");
	return 0;
}