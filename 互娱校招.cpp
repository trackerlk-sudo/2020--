#include<iostream>
#include<stdlib.h>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int T;
	cin >> T;
	//char tmp_str[];
	vector<string> arr;//存放输入数据
	for (int i = 0; i < T; i++)
	{
		char tmp_str[21];
		cin.getline(tmp_str,20);
		arr.push_back(tmp_str);
	}
	for (int i = 0; i < T; i++)
	{
		vector<int> arrW(9, 0);//存放W的下标0-8对应1-9
		vector<int> arrB(9, 0);//存放B的数字
		vector<int> arrT(9, 0);//存放T的数字
		int countW = 0;//表示能凑出完整的个数，147 258 369
		int countB = 0;
		int countT = 0;
		int sum_count = 0;
		for (int j = 0; j <= arr[i].size() - 2; j += 3)
		{
			if (arr[i][j + 1] == 'W')
			{
				arrW[arr[i][j] - '0' - 1] = arr[i][j] - '0';

			}
			else if (arr[i][j + 1] == 'B')
			{
				arrB[arr[i][j] - '0' - 1] = arr[i][j] - '0';
			}
			else if (arr[i][j + 1] == 'T')
			{
				arrT[arr[i][j] - '0' - 1] = arr[i][j] - '0';
			}
		}//统计完毕
		for (int m = 0; m <= 7; m++)
		{
			cout << arrB[m] << endl;
		}


		 //分两种情况考虑，count为1或者2
		if ((arrW[0] && arrW[3] && arrW[6]) || (arrW[1] && arrW[4] && arrW[7]) || (arrW[2] && arrW[5] && arrW[8]))
		{//147 258 369
			countW++;
			sum_count++;
		}
		if ((arrB[0] && arrB[3] && arrB[6]) || (arrB[1] && arrB[4] && arrB[7]) || (arrB[2] && arrB[5] && arrB[8]))
		{//147 258 369
			countB++;
			sum_count++;
		}
		if ((arrT[0] && arrT[3] && arrT[6]) || (arrT[1] && arrT[4] && arrT[7]) || (arrT[2] && arrT[5] && arrT[8]))
		{//147 258 369
			countT++;
			sum_count++;
		}
		if (sum_count == 0)
		{//一个都没凑齐
			cout << "NO" << endl;
		}
		else if (sum_count == 2)
		{
			if (countW == 0)
			{//B T凑齐了
				int k;
				for (k = 0; k < arrW.size(); k++)
				{//有一个不为0即可
					if (arrW[k] != 0)
					{
						cout <<"YES" << endl;
					}
				}
				if (k == 9)
				{
					cout << "NO" << endl;
				}

			}
			else if (countB == 0)
			{
				int m;
				for (m = 0; m < arrB.size(); m++)
				{//有一个不为0即可
					if (arrB[m] != 0)
					{
						cout << "YES" << endl;
					}
				}
				if (m == 9)
				{
					cout << "NO" << endl;
				}
			}
			else if (countT == 0)
			{
				int n;
				for (n = 0; n < arrT.size();n++)
				{//有一个不为0即可
					if (arrT[n] != 0)
					{
						cout << "YES" << endl;
					}
				}
				if (n == 9)
				{
					cout << "NO" << endl;
				}
			}
		}
		else if (sum_count == 1)
		{
			if (countW == 1)
			{//B T各两个
				//int resB = 0;
				//sort(arrB.rbegin(), arrB.rend());
				//sort(arrT.rbegin(), arrT.rend());//从大到小排序
				//if (arrB[0] == 9 && find(arrB.begin(),arrB.end(),6)!=arrB.end() || arrB[0] == 9 && find(arrB.begin(), arrB.end(), 3) != arrB.end())
				//{//B中存在两个满足要求
				//	resB++;
				//}
				cout << "NO" << endl;
			}
			else if (countB == 1)
			{//W T各两个
				cout << "NO" << endl;
			}
			else if (countT == 1)
			{//W B各两个
				cout << "NO" << endl;
			}
		}
	}
	//system("pause");
	return 0;
}