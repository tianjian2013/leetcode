#include "globe.h"
int res=0;
void scan(TreeNode *root,int dep)
{
    if(root==NULL)
    {
        if(dep-1>res)
        {
            res=dep-1;
        }
		return;
    }

    scan(root->left,dep+1);
    scan(root->right,dep+1);
    
}

void main()
{
	TreeNode n1(1);
	TreeNode n2(2);
	TreeNode n3(3);
	TreeNode n4(4);
	TreeNode n5(5);
    TreeNode n6(6);
	TreeNode n7(7);

	n1.left=&n2;
	n1.right=&n3;
	n2.left=&n4;
	n2.right=&n5;
	n3.left=&n6;
	n5.left=&n7;
	scan(&n1,1);

	waitKey();


}