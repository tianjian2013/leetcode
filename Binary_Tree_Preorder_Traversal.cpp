#include <vector>
#include <stack>
#include <iostream>
#include <opencv2\opencv.hpp>
using namespace std;
using namespace cv;
struct TreeNode {
      int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
//÷––Ú
class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector <int > res;
        stack <TreeNode > stk;
        if(root==NULL) return res;
        stk.push(*root);
        TreeNode temp(0);
        while(stk.size())
        {
            TreeNode top=stk.top();
            if(top.left&&top.left!=root)
            {
				stk.pop();
				temp=top;
                top.left=NULL;
				stk.push(top);
                stk.push(*temp.left);
                continue;
            }
			if(top.left!=root)
			{
            res.push_back(top.val);
			top.left=root;
			stk.pop();
			stk.push(top);
			}
            if(top.right)
            {
				
				stk.pop();
				temp=top;
                top.right=NULL;
				stk.push(top);
                stk.push(*temp.right);
                continue;
            }
			
				  
			
            stk.pop(); 
        }
		return res;
    }
	
};
//œ»–Ú
/*
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
		vector<int> res;
		if(root==NULL)
        {
            return res;
        }
		stack<TreeNode *> stk;
		TreeNode *p=root;
		stk.push(p);
		int t=p->val;
		res.push_back(t);

		while(stk.size())
		{
		  p=stk.top();
		  if(p->left!=NULL)
		  {
			  TreeNode* temp=p->left;
			  p->left=NULL;
			  p=temp;
			  stk.push(p);
			  res.push_back(p->val);
			  continue;
		  }
		  if(p->right!=NULL)
		  {
			  TreeNode* temp1=p->right;
			  p->right=NULL;
			  p=temp1;
			  stk.push(p);
			  res.push_back(p->val);
			  continue;
		  }
		  stk.pop();
		 
		}   
		return res;
    }
};
*/
void main()
{
	TreeNode a(1);
	TreeNode b(2);
	TreeNode c(3);
    TreeNode d(4);
	TreeNode e(5);
	TreeNode f(6);
	TreeNode g(7);

	a.left=&b;
	b.left=&c;
	b.right=&d;
	//d.left=&e;
	//d.right=&f;
	//e.right=&g;

	Solution s;
	vector<int> res=s.inorderTraversal(&a);

	for(int i=0;i<res.size();i++)
	{
	 cout<<res[i]<<endl;
	}
	waitKey();
}