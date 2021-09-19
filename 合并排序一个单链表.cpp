#include<iostream>
#include<vector>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x):val(x),next(NULL){}
};

ListNode* createList(vector<int>& arr)
{
	ListNode* head = new ListNode(-1);
	ListNode* tmp = head;
	for (int i = 0; i < arr.size(); i++)
	{
		ListNode* crr = new ListNode(arr[i]);
		tmp->next = crr;
		tmp = tmp->next;
	}
	return head->next;
}

void travel(ListNode* head)
{
	if (head == NULL) return;
	ListNode* tmp = head;
	while (tmp)
	{
		cout << tmp->val <<" ";
		tmp = tmp->next;
	}
	cout << endl;
}

ListNode* getmid(ListNode* head)
{//找一个链表的中点
	if (head == NULL || head->next == NULL) return head;
	ListNode* slow = head;
	ListNode* fast = head;
	while (fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	if (fast == NULL)
	{
		return slow;
	}
	else
	{
		return slow->next;
	}
}

ListNode* mergeList(ListNode* ha, ListNode* hb)
{
	if (ha == NULL) return hb;
	if (hb == NULL) return ha;
	if (ha->val < hb->val)
	{
		ha->next = mergeList(ha->next, hb);
		return ha;
	}
	else
	{
		hb->next = mergeList(ha, hb->next);
		return hb;
	}
}

ListNode* firsthalf(ListNode* head,ListNode* mid)
{
	if (head == NULL) return head;
	if (head == mid) return head;
	if (head->next == NULL)
	{
		return head;
	}
	ListNode* pre = head;
	ListNode* crr = head->next;
	while (crr!=mid)
	{
		pre = crr;
		crr = crr->next;
	}
	pre->next = NULL;
	return head;
}

int main()
{
	vector<int> arr = {1,3,5,6,7,8,9,10,12,14};
	ListNode* head = createList(arr);
	ListNode* mid = getmid(head);
	ListNode* firs_thalf=firsthalf(head, mid);
	travel(firs_thalf);
	travel(mid);
	ListNode* newList = mergeList(firs_thalf, mid);
	travel(newList);
	system("pause");
	return 0;
}