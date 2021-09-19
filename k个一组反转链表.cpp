#include<iostream>
#include<vector>
#include<string>

using namespace std;

struct Node {
	int val;
	Node* next;
	Node(int x):val(x),next(NULL){}
};

Node* createList(int N)
{
	Node* head = new Node(-1);
	Node* tmp = head;
	for (int i = 1; i <= N; i++)
	{
		tmp->next = new Node(i);
		tmp = tmp->next;
	}
	return head->next;
}

Node* adjust(Node* a)
{//调整链表
	if (a == NULL || a->next==NULL) return a ;
	Node* head = a;
	a = a->next;
	head->next = NULL;
	Node* tmp = a;
	while (tmp->next!=NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = head;
	return a;
}

void swaptwo(Node* a)
{
	if (a == NULL || a->next == NULL)
	{
		return;
	}

	Node *tmp1 = a;
	Node* tmp2 = NULL;
	while (tmp1 != NULL && tmp1->next!=NULL)
	{
		tmp2 = tmp1->next;
		int crrtmp = tmp1->val;
		tmp1->val = tmp2->val;
		tmp2->val = crrtmp;
		tmp1 = tmp1->next->next;
	}
}

Node* reveseab(Node* a, Node* b)
{
	Node* pre = NULL;
	Node* pnext = NULL;
	while (a != b)
	{
		pnext = a->next;
		a->next = pre;
		pre = a;
		a = pnext;
	}
	return pre;
}

Node* reverseK(Node* head,int k)
{//K个一组反转链表
	if (head == NULL || head->next == NULL) return head;
	Node* tmp = head;
	for (int i = 0; i < k; i++)
	{
		if (tmp == NULL) return head;//不需要反转
		tmp = tmp->next;
	}
	Node* newhead = reveseab(head, tmp);
	Node* node = reverseK(tmp, k);
	head->next = node;
	return newhead;
}

int main()
{
	int n, m;
	cin >> n >> m;
	/*vector<int> arr(m,0);
	for (int i = 0; i < m; i++)
	{
		cin >> arr[i];
	}*/
	Node *head = createList(n);
	Node *newhead = reverseK(head, 3);
	/*for (int i = 0; i < m; i++)
	{
		if (arr[i] == 1)
		{
			head=adjust(head);
		}
		else if (arr[i] == 2)
		{
			swaptwo(head);
		}
	}*/
	while (newhead)
	{
		cout << newhead->val << " ";
		newhead = newhead->next;
	}
	system("pause");
	return 0;
}

//int main()
//{
//	int n;
//	cin >> n;
//	vector<string> arr;
//	for (int i = 0; i < n; i++)
//	{
//		string str;
//		cin >> str;
//		arr.push_back(str);
//	}
//	int count = 0;
//	for (int i = 0; i < arr.size(); i++)
//	{
//		if (arr[i].size() > 10)
//		{
//			continue;
//		}
//		int j;
//		for (j = 0; j < arr[i].size(); j++)
//		{
//			if ((arr[i][j] >= 'a' && arr[i][j] <= 'z') || (arr[i][j] >= 'A' && arr[i][j] <= 'Z'))
//			{
//				continue;
//			}
//			else
//			{
//				break;
//			}
//		}
//		if (j == arr[i].size())
//		{
//			count++;
//		}
//	}
//	cout << count << endl;
//	system("pause");
//	return 0;
//}

//Node* revese(Node* a, Node* b)
//{//a到b反转[a,b)
//	if (a == NULL || a->next == NULL) return a;
//	Node* pre = NULL;
//	Node* pnext = NULL;
//	Node* tmp = a;
//	while (tmp != b)
//	{
//		pnext = tmp->next;
//		tmp->next = pre;
//		pre = tmp;
//		tmp = pnext;
//	}
//	return pre;
//}
//
//Node* revesetwo(Node* a)
//{//两个一组反转链表
//	if (a == NULL || a->next == NULL) return a;
//	Node* crr = a;
//	for (int i = 0; i < 2; i++)
//	{
//		if (a == NULL) return a;
//		a = a->next;
//	}
//	Node* tmp1 = revese(crr, a);
//	Node* tmp2 = revesetwo(a);
//	a->next = tmp1;
//	return tmp2;
//}