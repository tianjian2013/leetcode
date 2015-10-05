//#include "help.h"  

#include <iostream>
using namespace std;
struct TreeNode {
     int val;
     TreeNode *left;
      TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

void cvt(TreeNode* root)
    {
        if(root==NULL) return;
        swap(root->left,root->right);
        cvt(root->left);
        cvt(root->right);
    }
    TreeNode* invertTree(TreeNode* root) {
       cvt(root);
       return root;
    }

int main()
{
  TreeNode n0(0);
  TreeNode* ret=invertTree(&n0);
  return 0;
}
