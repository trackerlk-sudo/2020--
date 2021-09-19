#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<string>

using namespace std;

//struct listNode {
//	int val;
//	listNode* next;
//	listNode(int x):val(x),next(NULL){}
//};
//
//listNode* createList(vector<int>& arr)
//{
//	int len = arr.size();
//	if (len < 1) return NULL;
//	listNode* head = new listNode(-1);
//	listNode* tmp = head;
//	for (int i = 0; i < len; i++)
//	{
//		listNode* crr = new listNode(arr[i]);
//		tmp->next = crr;
//		tmp = tmp->next;
//	}
//	return head->next;
//}
//
//void travel(listNode* head)
//{
//	listNode* tmp = head;
//	while (tmp)
//	{
//		cout << tmp->val << " ";
//		tmp = tmp->next;
//	}
//	cout << endl;
//}
//
//void getcommon(listNode* headA, listNode* headB)
//{
//	listNode* tmp1 = headA;
//	listNode* tmp2 = headB;
//	while (tmp1 && tmp2)
//	{
//		if (tmp1->val == tmp2->val)
//		{
//			cout << tmp1->val << " ";
//			tmp1 = tmp1->next;
//			tmp2 = tmp2->next;
//		}
//		else if (tmp1->val < tmp2->val)
//		{
//			tmp2 = tmp2->next;
//		}
//		else if (tmp1->val > tmp2->val)
//		{
//			tmp1 = tmp1->next;
//		}
//	}
//}
//
//int main()
//{
//	int len1;
//	cin >> len1;
//	vector<int> arr1(len1, 0);
//	for (int i = 0; i < len1; i++)
//	{
//		cin >> arr1[i];
//	}
//	int len2;
//	cin >> len2;
//	vector<int> arr2(len2, 0);
//	for (int i = 0; i < len2; i++)
//	{
//		cin >> arr2[i];
//	}
//	listNode* headA = createList(arr1);
//	listNode* headB = createList(arr2);
//	getcommon(headA, headB);
//	system("pause");
//
//	return 0;
//}

//int main()
//{
//	int n, m;
//	cin >> n >> m;
//	vector<vector<int>> arr;
//	for (int i = 0; i < m; i++)
//	{
//		int num;
//		cin >> num;
//		vector<int> tmp;
//		for (int j = 0; j < num; j++)
//		{
//			cin >> tmp[j];
//		}
//		arr.push_back(tmp);
//	}//保存数据
//	int k = -1;
//	for (int i = 0; i < m; i++)
//	{
//		for (int j = 0; j < arr[i].size(); j++)
//		{
//			if (arr[i][j] == 0)
//			{
//				k = i;
//				break;
//			}
//		}
//	}
//
//
//}
int mindiff = INT_MAX;


int getmindff(vector<int> & arr, vector<int>& visit)
{//排好序的数组
	int len = arr.size() - 1;
	DFS(arr, 0, 0, visit);
	return mindiff;
}

void DFS(vector<int> & arr, int start, int crrsum,vector<int>& visit)
{
	if (crrsum < mindiff)
	{
		mindiff = crrsum;
	}
	if (start == arr.size())
	{
		return;
	}

	for (int i = 0; i < arr.size() - 1; i++)
	{
		if (visit[i] == 0)
		{
			visit[i] = 1;
			crrsum += arr[i];
			DFS(arr, start + 1, crrsum, visit);
			crrsum -= arr[i];
			visit[i] = 0;
		}
	}
}

int main()
{
	int n;
	cin >> n;
	vector<int> arr(n,0);
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		sum += arr[i];
	}
	int m;
	cin >> m;
	if (sum <= m)
	{
		cout << sum << endl;
		return 0;
	}
	sort(arr.begin(), arr.end());
	//求差值最小的组合
	vector<int> visit(arr.size() - 1, 0);
	getmindff(arr,visit)

	cout << res << endl;
	system("pause");
	return 0;
}


//typedef pair<string, int> PAIR;
//
//int cmp(PAIR& x, PAIR& y)
//{
//	if (x.second == y.second)
//	{
//		return x.first > y.first;
//	}
//	return x.second < y.second;
//}
//
//int cmp1(PAIR& x, PAIR& y)
//{
//	if (x.second == y.second)
//	{
//		return x.first < y.first;
//	}
//	return x.second < y.second;
//}
//
//
//int main()
//{
//	int N, K;
//	map<string, int> mymap;
//	cin >> N >> K;
//	for (int i = 0; i < N; i++)
//	{
//		string str;
//		cin >> str;
//		mymap[str]++;
//	}
//	vector<PAIR> arr;
//	for (auto p : mymap)
//	{
//		arr.push_back(p);
//	}
//	sort(arr.begin(), arr.end(), cmp);
//
//	int i = arr.size()-1;
//	int k = 0;
//	for (;k<K;i--,k++)
//	{
//		cout << arr[i].first << " " << arr[i].second << endl;
//	}
//
//	sort(arr.begin(), arr.end(), cmp1);
//	for (int j = 0; j < K; j++)
//	{
//		cout << arr[j].first << " " << arr[j].second << endl;
//	}
//	system("pause");
//	return 0;
//}