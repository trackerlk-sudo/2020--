#include<iostream>
#include<vector>
#include<string>


using namespace std;

//struct ListNode {
//	int val;
//	struct ListNode *next;
//	ListNode(){}
// };
//
//
//class Solution {
//public:
//	/**
//	* 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
//	* 输入单链表的头节点和要删除的倒数第N个，返回删除后的头节点
//	* @param head ListNode类 单链表的头节点
//	* @param n int整型
//	* @return ListNode类
//	*/
//	ListNode* removeNthFromEnd(ListNode* head, int n) {
//		// write code here
//		if (head == NULL) return head;
//		ListNode* tmp = head;
//		ListNode* crr = head;
//		int count = 0;
//		while (tmp)
//		{
//			tmp = tmp->next;
//			count++;
//		}
//		if (count == n) return head->next;
//		int k = count - n - 1;
//		while (k-- && crr)
//		{
//			crr = crr->next;
//		}
//		crr->next = crr->next->next;
//		return head;
//	}
//};
//
//class Solution {
//public:
//	/**
//	* 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
//	*
//	* @param nums int整型vector
//	* @return int整型
//	*/
//	int firstMissingPositive(vector<int>& nums) {
//		// write code here
//		int flag;
//		int res = 1;
//		for (int i = 1; i < nums.size(); i++)
//		{
//			flag = 0;
//			for (int j = 0; j < nums.size(); j++)
//			{
//				if (nums[j] == i)
//				{
//					flag = 1;
//					res++;
//					break;
//				}
//			}
//			if (flag == 0)
//				return res;
//		}
//		return res;
//	}
//};


char * mystrcpy(char * src, const char * tar)
{
	if (src == NULL || tar == NULL)
	{
		return NULL;
	}
	char * newstr = src;
	while ((*src++ = *tar++) != '\0');
	*src = '\0';
	return newstr;
}
int main()
{
	string sources;
	string target;
	cin >> sources >> target;
	int lens = sources.size();
	int lent = target.size();
	char *s = NULL;
	char *t = NULL;
	s = (char*)malloc(lens+1);
	t = (char*)malloc(lent+1);

	mystrcpy(s,sources.c_str());
	mystrcpy(t, target.c_str());
	mystrcpy(s, t);

	cout << s << endl;
	system("pause");
	return 0;
}