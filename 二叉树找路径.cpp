#include <iostream>
#include<vector>
#include<queue>

//编码题：给一个二叉树，每个节点值都有唯一不同的字符，写代码实现传入一个字符值x, 返回对应的节点，找不到返回null。
//进阶：打印出从头节点到目标节点x的路径
using namespace std;
struct TreeNode {
	char c;
	TreeNode* left;
	TreeNode* right;
	TreeNode(char ch) :c(ch), left(NULL), right(NULL) {}
};

void DFS(TreeNode* root, char ch, vector<char>& crr);
TreeNode* find(TreeNode* root, char ch);
vector<char> findpath(TreeNode* root, char ch);

TreeNode* find(TreeNode* root, char ch)
{//找树中是否存在该节点，不存在返回NULL，存在返回该节点
	TreeNode* node1;
	TreeNode* node2;
	if (root == NULL) return NULL;
	if (root)
	{
		if (root->c == ch)
		{
			return root;
		}
		node1 = find(root->left, ch);
		if (node1) return node1;
		node2 = find(root->right, ch);
		if (node2) return node2;
	}
	return NULL;
}

void DFS(TreeNode* root, char ch, vector<char>& crr)
{//
	crr.push_back(root->c);//当前先压入
	if (root->c == ch)
	{//走到目标节点了，返回即可
		return ;
	}
	TreeNode* left = find(root->left, ch);//判断其在左子树还是右子树
	if (left) DFS(root->left, ch, crr);
	else DFS(root->right, ch, crr);
}

vector<char> findpath(TreeNode* root, char ch)
{
	vector<char> crr;
	TreeNode* node = find(root, ch);
	if (node == NULL)  return crr;
	DFS(root, ch, crr);
	return crr;
}



TreeNode* ctreateTree(vector<char>& arr)
{//根据arr创建一颗二叉树
	int len = arr.size();
	if (len < 1) return NULL;
	TreeNode* root = new TreeNode(arr[0]);
	TreeNode* crr = root;
	queue<TreeNode*> q;
	q.push(crr);
	int k = 1;
	while (!q.empty() && k<len)
	{
		int length = q.size();
		for (int i = 0; i < length; i++)
		{
			TreeNode* tmp = q.front();
			q.pop();
			tmp->left = new TreeNode(arr[k++]);
			q.push(tmp->left);
			if (k >= len) break;
			tmp->right = new TreeNode(arr[k++]);
			q.push(tmp->right);
			if (k >= len) break;
		}
	}
	return root;
}

void travel(TreeNode* root)
{
	if (root)
	{
		cout << root->c << " ";
		travel(root->left);
		travel(root->right);
	}
}

int main()
{
	vector<char> arr = { 'a','b','c','d','e','f','g','h' };
	TreeNode* root = ctreateTree(arr);
	//TreeNode* node = find(root, 'l');
	vector<char> res = findpath(root, 'h');
	cout << res.size()<< endl;
	
	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}