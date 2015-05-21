#include "globe.h"

class Solution {
public:
    bool visit(vector<vector<char> > &board,vector<vector<bool> > &flag,int i,int j,string &word,int num)
    {
        if(num==word.size() ) return true;
		if(i<0||i>=board.size()||j<0||j>=board[0].size())  return false;
        if(board[i][j]!=word[num]|| flag[i][j] )    return false;
        flag[i][j]=true;
        if( visit(board,flag,i-1,j,word,num+1)  )  
                     return true;
        if( visit(board,flag,i+1,j,word,num+1)  )  
                     return true;
        if( visit(board,flag,i,j-1,word,num+1)  )  
                     return true;
        if( visit(board,flag,i,j+1,word,num+1)  )  
                     return true;
		flag[i][j]=false;  
		return false;
    }
    bool exist(vector<vector<char> > &board, string word) {
       bool ret=false;
       if(board.size()==0) return ret;
       if(word.empty() )  return !ret;
       
	   vector<vector<bool> > flag(board.size() ,vector<bool> (board[0].size(),false));

       for(int i=0;i<board.size();i++)
       {
           for(int j=0;j<board[0].size();j++)
           {
                  if( visit(board,flag,i,j,word,0)  )  
                     return true;   
           }
       }
       return ret;
    }
};

void main()
{

}


/*  right answer  *
class Solution {
public:
static bool dfs(const vector<vector<char> > &board, const string &word,int index, int x, int y, vector<vector<bool> > &visited)
{
  if (index == word.size())
     return true; // 收敛条件
  if (x < 0 || y < 0 || x >= board.size() || y >= board[0].size())
     return false; // 越界，终止条件
  if (visited[x][y]) return false; // 已经访问过，剪枝
  if (board[x][y] != word[index]) return false; // 不相等，剪枝
  visited[x][y] = true;
  bool ret = dfs(board, word, index + 1, x - 1, y, visited) || // 上
             dfs(board, word, index + 1, x + 1, y, visited) || // 下
             dfs(board, word, index + 1, x, y - 1, visited) || // 左
             dfs(board, word, index + 1, x, y + 1, visited); // 右
  visited[x][y] = false;
  return ret;
}
    bool exist(vector<vector<char> > &board, string word) {
       const int m = board.size();
       const int n = board[0].size();
       vector<vector<bool> > visited(m, vector<bool>(n, false));
       for (int i = 0; i < m; ++i)
           for (int j = 0; j < n; ++j)
               if (dfs(board, word, 0, i, j, visited))
                  return true;
        return false;
    }
};

/*  right answer  */