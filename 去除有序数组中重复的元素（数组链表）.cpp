#include<iostream>
#include<vector>

using namespace std;
struct Node {
	int val;
	Node* next;
	Node(int x):val(x),next(NULL){}
};

int ditinctarr(vector<int>& arr)
{//给定一个排序数组，去除重复数字，返回去重后的长度
	int len = arr.size();
	if (len == 1) return arr[0];
	int slow = 0;
	int fast = 1;
	while (fast < len)
	{
		if (arr[fast] != arr[slow])
		{
			slow++;
			arr[slow] = arr[fast];
		}
		fast++;
	}
	return slow + 1;
}

Node* createList(vector<int>& arr)
{
	Node* head = new Node(-1);
	Node* tmp = head;
	for (int i = 0; i <arr.size(); i++)
	{
		tmp->next = new Node(arr[i]);
		tmp = tmp->next;
	}
	return head->next;
}

Node* distinctlist(Node* head)
{//去除有序链表中的重复的
	if (head == NULL || head->next == NULL) return head;
	Node* slow = head;
	Node* fast = head->next;
	while (fast != NULL)
	{
		if (fast->val != slow->val)
		{
			/*slow = slow->next;
			slow->val = fast->val;*/
			slow->next = fast;
			slow = slow->next;
		}
		fast = fast->next;
	}
	slow->next = NULL;
	return head;
}

int main()
{
	vector<int> arr = { 0,1,1,2,8,8,9,10,10 };
	/*int len = ditinctarr(arr);

	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << " ";
	}*/

	Node* head = createList(arr);
	head = distinctlist(head);
	while (head)
	{
		cout << head->val <<" ";
		head = head->next;
	}
	system("pause");
	return 0;
}