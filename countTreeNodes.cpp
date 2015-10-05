#include "help.h"

bool check(TreeNode * root ,int num,int h)
    {
        unsigned int n=1<<(h-1);
        while(n&&root)
        {
            if(n&num)
                root=root->right;
            else
                root=root->left;
            n>>=1;
        }
        return root!=NULL;
    }
   
    int countNodes(TreeNode* root) {
       if(root==NULL) return 0;
       int h=0;
       TreeNode *mp=root;
       while(mp->left)
       {
           mp=mp->left;
           h++;
       }

       if(h==0) return 1;
       int p=0,q=pow(2,h)-1;
       if(check (root,q,h)  )   return pow(2,h+1)-1; 

       while(p<=q)
       {
         int mid=(p+q)>>1;
         if(check (root,mid,h)  )
         {
             p=mid+1;
         }
         else 
         {
             if ( check(root,mid-1,h) )
             {
                return pow(2,h)-1+mid; 
             }
             else
               q=mid-1;
         }
       }
       return 1;
       
    }
int main()
{
  TreeNode a0(0);

  TreeNode a1(1);
TreeNode a2(2);
  a0.left=&a1;
  //a0.right=&a2;
  cout << countNodes(&a0);
  return 0;
}
