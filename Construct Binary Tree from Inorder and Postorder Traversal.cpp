#include "globe.h"


/**中序和后序**
class Solution {
public:
    void build (TreeNode * root,int starti,int endi,int startp,int endp,vector<int> &inorder, vector<int> &postorder)
    {
        if(endp<startp) return;
        else if(endp==startp) 
        {
            root=new TreeNode(inorder[startp]);
            return;
        }
        else
        {
            int i,j;
            for( i=starti;i<=endi;i++)
            {
                if(inorder[i]==postorder[endp])
                break;
            }
            for( j=endp-1;j>=startp;j--)
            {
                int k;
                for( k=starti;k<i;k++)
                {
                    if(postorder[j]==inorder[k])
                    {
                        
                        break;
                    }
                }
                if(k<i)  break;
            }
            root=new TreeNode(inorder[i]);
            
            build(root->left,starti,i-1,startp,j,inorder,postorder);
            build(root->right,i+1,endi,j+1,endp-1,inorder,postorder);
        }
    }
    
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        TreeNode * res= NULL;
        build(res,0,inorder.size()-1,0,inorder.size()-1,inorder,postorder);
        return res;
    }
};

**中序和后序**/

/**中序和先序**/
class Solution {
public:
    void build(TreeNode *& root,vector<int> &preorder, vector<int> &inorder,int ps,int pe,int is,int ie)
    {
        if(ps>pe)  return ;
        else if(ps==pe)
        {
            root =new TreeNode(preorder[ps]);
            return;
        }
        else
        {
           root =new TreeNode(preorder[ps]);
           int i;
           for( i=is;i<=ie;i++)
           {
               if(inorder[i]==preorder[ps])
               break;
           }
           build(root->left,preorder,inorder,ps+1,ps+i-is,is,i-1);
           build(root->right,preorder,inorder,ps+i-is+1,pe,i+1,ie);
        }
    } 
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        TreeNode * res=NULL;
        build(res,preorder,inorder,0,inorder.size()-1,0,inorder.size()-1);
        return res;
    }
};
/**中序和先序**/

void main()
{
	Solution sl;
	vector<int> m1;
	m1.push_back(1);
	//m1.push_back(2);
	//m1.push_back(2);
	vector<int> m2;
	m2.push_back(2);
	//m2.push_back(1);
	TreeNode * res=sl.buildTree(m1,m2);
	waitKey();
}