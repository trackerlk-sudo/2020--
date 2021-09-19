//#include<iostream>
//#include<vector>
//#include<string>
//#include<algorithm>
//
//using namespace std;
//
//typedef struct TreeNode {
//	int val;
//	struct TreeNode* left;
//	struct TreeNode* right;
//	struct TreeNode():val(0),left(NULL),right(NULL){}
//	struct TreeNode(int x):val(x),left(NULL),right(NULL){}
//}Tnode;
//
//Tnode* add(Tnode* root, int num)
//{//依次添加节点
//	if (root == NULL)
//	{
//		return new Tnode(num);
//	}
//	if (root->val > num)
//	{
//		root->left = add(root->left,num);
//	}
//	else
//	{
//		root->right = add(root->right, num);
//	}
//	return root;
//}
//
//Tnode* createTree(vector<int>& arr)
//{//递归创建搜索二叉树
//	Tnode* root = NULL;
//	for (int i = 0; i < arr.size(); i++)
//	{
//		root = add(root, arr[i]);
//	}
//	return root;
//}
//
//
//void travel(Tnode* root)
//{
//	if (root)
//	{
//		if (root->left == NULL && root->right == NULL)
//		{
//			cout << root->val<<" ";
//		}
//		travel(root->left);
//		travel(root->right);
//	}
//}
//
//int main()
//{
//	int tmp;
//	vector<int> arr;
//	while (cin>>tmp)
//	{
//		arr.push_back(tmp);
//	}
//	int len = arr.size();
//
//	cout << arr.size() << endl;
//
//	Tnode* root = createTree(arr);
//	travel(root);
//	system("pause");
//	return 0;
//}

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

struct Tnode {
	int val;
	struct Tnode* left;
	struct Tnode* right;
	//Tnode():val(0),left(NULL),right(NULL){};
	Tnode(int x) :val(x), left(NULL), right(NULL) {};
};

Tnode* add(Tnode* root, int num)
{//依次添加节点，返回添加完后的根节点
	if (root == NULL)
	{//为空则直接创建该节点为根节点
		return new Tnode(num);
	}
	if (root->val > num)
	{//值小于根节点，添加到左边
		root->left = add(root->left, num);
	}
	else
	{
		root->right = add(root->right, num);
	}
	return root;
}

Tnode* createTree(vector<int>& arr)
{//创建搜索二叉树
	Tnode* root = NULL;
	for (int i = 0; i < arr.size(); i++)
	{
		root = add(root, arr[i]);
	}
	return root;
}


void travel(Tnode* root)
{//遍历二叉树
	if (root)
	{
		if (root->left == NULL && root->right == NULL)
		{
			cout << root->val << " ";
		}
		travel(root->left);
		travel(root->right);
	}
}

int main()
{
	int tmp;
	vector<int> arr;
	while (cin >> tmp)
	{
		arr.push_back(tmp);
	}
	int len = arr.size();

	//cout << arr.size() << endl;

	Tnode* root = createTree(arr);
	travel(root);
	//system("pause");
	return 0;
}