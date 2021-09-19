#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
	bool exist(vector<vector<char>>& board, string word)
	{
		for (int i = 0; i < board.size(); i++)
		{
			for (int j = 0; j < board[0].size(); j++)
			{
				if (DFS(board, word, i, j, 0)) return true;//以ij为起点，向四个方向遍历
			}
		}
		return false;
	}

	bool DFS(vector<vector<char>>& board, string word, int i, int j, int w)
	{//以ij为起点
		if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[w]) 
			return false;
		if (w == word.size() - 1) return true;
		char tmp = board[i][j];
		board[i][j] = '\0';//该位置不能再被计算了
		if (DFS(board, word, i - 1, j, w + 1) || DFS(board, word, i + 1, j, w + 1) || DFS(board, word, i, j - 1, w + 1) || DFS(board, word, i, j + 1, w + 1))
		{
			return true;
		}
		board[i][j] = tmp;
		return false;
	}
};

int main()
{
	vector<vector<char>> arr = { {'A','B','C','E'},{ 'S','F','C','S' },{ 'A','D','E','E' } };
	Solution p;
	string str;
	cin >> str;
	if(p.exist(arr, str)) cout<<"true"<<endl;
	else cout << "false" << endl;
	system("pause");
	return 0;
}