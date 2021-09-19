#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


//剪刀石头布
/*int main()
{
	int T;
	cin >> T;
	vector<vector<char>> arr(T, vector<char>(4, 'q'));
	for (int i = 0; i < T; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < T; i++)
	{//分别计算左右手得分的期望值
		int score = 0;//左手得分值
		char cleft = arr[i][0];//左手
		if (cleft == 'J')
		{
			if (arr[i][2] == 'J')
			{
				score--;
			}
			else if (arr[i][2] == 'S')
			{
				score--;
			}
			else if (arr[i][2] == 'B')
			{
				score++;
			}

			if (arr[i][3] == 'J')
			{
				score--;
			}
			else if (arr[i][3] == 'S')
			{
				score--;
			}
			else if (arr[i][3] == 'B')
			{
				score++;
			}
		}
		else if (cleft == 'S')
		{
			if (arr[i][2] == 'J')
			{
				score++;
			}
			else if (arr[i][2] == 'S')
			{
				score--;
			}
			else if (arr[i][2] == 'B')
			{
				score--;
			}

			if (arr[i][3] == 'J')
			{
				score++;
			}
			else if (arr[i][3] == 'S')
			{
				score--;
			}
			else if (arr[i][3] == 'B')
			{
				score--;
			}
		}
		else if (cleft == 'B')
		{

			if (arr[i][2] == 'J')
			{
				score--;
			}
			else if (arr[i][2] == 'S')
			{
				score++;
			}
			else if (arr[i][2] == 'B')
			{
				score--;
			}

			if (arr[i][3] == 'J')
			{
				score--;
			}
			else if (arr[i][3] == 'S')
			{
				score++;
			}
			else if (arr[i][3] == 'B')
			{
				score--;
			}
		}

		int nscore = 0;
		char rleft = arr[i][1];//右手
		if (rleft == 'J')
		{
			if (arr[i][2] == 'J')
			{
				nscore--;
			}
			else if (arr[i][2] == 'S')
			{
				nscore--;
			}
			else if (arr[i][2] == 'B')
			{
				nscore++;
			}

			if (arr[i][3] == 'J')
			{
				nscore--;
			}
			else if (arr[i][3] == 'S')
			{
				nscore--;
			}
			else if (arr[i][3] == 'B')
			{
				nscore++;
			}
		}
		else if (rleft == 'S')
		{
			if (arr[i][2] == 'J')
			{
				nscore++;
			}
			else if (arr[i][2] == 'S')
			{
				nscore--;
			}
			else if (arr[i][2] == 'B')
			{
				nscore--;
			}

			if (arr[i][3] == 'J')
			{
				nscore++;
			}
			else if (arr[i][3] == 'S')
			{
				nscore--;
			}
			else if (arr[i][3] == 'B')
			{
				nscore--;
			}

		}
		else if (rleft == 'B')
		{
			if (arr[i][2] == 'J')
			{
				nscore--;
			}
			else if (arr[i][2] == 'S')
			{
				nscore++;
			}
			else if (arr[i][2] == 'B')
			{
				nscore--;
			}

			if (arr[i][3] == 'J')
			{
				nscore--;
			}
			else if (arr[i][3] == 'S')
			{
				nscore++;
			}
			else if (arr[i][3] == 'B')
			{
				nscore--;
			}
		}
		cout << score << endl;
		cout << nscore << endl;
		if (score > nscore)
		{
			cout << "left" << endl;
		}
		else if (score == nscore)
		{
			cout << "same" << endl;
		}
		else if (score < nscore)
		{
			cout << "right" << endl;
		}
	}

	system("pause");
	return 0;
}*/


//杀死怪物
int main()
{
	int n;
	cin >> n;
	vector<int> arr1(2 * n, 0);
	vector<int> arr2(2 * n, 0);
	for (int i = 0; i < 2 * n; i++)
	{
		cin >> arr1[i];
	}//保存消耗生命值

	for (int i = 0; i < 2 * n; i++)
	{
		cin >> arr2[i];
	}//保存回复生命值
	//假设刚开始勇者生命值为0;找最优杀怪方案
	vector<int> diff(2 * n, 0);
	for (int i = 0; i < 2 * n; i++)
	{
		diff[i] = arr2[i] - arr1[i];
	}

	int i = n - 1;
	int j = n;
	int res = 0;
	int result = INT_MAX;

	while (i >= 0 && j < 2 * n)
	{
		if (diff[i] > diff[j])
		{
			res -=arr1[i];
			result = min(result, res);
			res += arr2[i];
			i--;
		}
		else
		{
			res += diff[j];
			result = min(result, res);
			res += arr2[j];
			j++;
		}
	}

	if (i==-1)
	{
		for (int k = j; k < 2 * n; k++)
		{
			res -= arr1[k];
			result = min(result, res);
			res += arr2[k];
		}
	}
	if (j == 2 * n)
	{
		for (int k = i; k >=0; k--)
		{
			res -= arr1[k];
			result = min(result, res);
			res += arr2[k];
		}
	 }

	if (result >= 0)
	{
		cout << 1 << endl;
	}
	else
	{
		result = 1-result ;
		cout << result << endl;
	}
	system("pause");
	return 0;
}