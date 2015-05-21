#include "globe.h"
struct TreeLinkNode {
   int val;
   TreeLinkNode *left, *right, *next;
   TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
  };
class Solution {
public:

 void nextright(TreeLinkNode *root)
    {
        TreeLinkNode * tmp=root;
        //bool first=true;
        TreeLinkNode * nt=NULL;
        while(tmp)
        {
            if(tmp->left )  
            {
               if(tmp->right)  tmp->left->next=tmp->right;
               else
               {
                TreeLinkNode *tmp1=tmp->next;
                while(tmp1)
                {  
                 if(tmp1->left)  {tmp->left->next=tmp1->left;  break;}
                 if(tmp1->right)  {tmp->left->next=tmp1->right; break;}
                 tmp1=tmp1->next;
                }
               }
                if(nt==NULL)   
                {
                   //first=false;
                   nt=tmp->left;
               }
            }
           if(tmp->right )  
            {
               //if(tmp->right)  root->left->next=root->right;
               TreeLinkNode *tmp1=tmp->next;
               while(tmp1)
               {  
                 if(tmp1->left)  {tmp->right->next=tmp1->left;  break;}
                 if(tmp1->right)  {tmp->right->next=tmp1->right; break;}
                 tmp1=tmp1->next;
               }   
               if(nt==NULL)   
               {
                   //first=false;
                   nt=tmp->right;
                   
               }
            }
            tmp=tmp->next;
        }
        if(nt)
       nextright(nt);
    
        
        
        
    }
    void connect(TreeLinkNode *root) {
        if(root==NULL) return;
        root->next=NULL;
        nextright(root);
    }
};
void main()
{
	TreeLinkNode a0(0);
	TreeLinkNode a1(2);
	TreeLinkNode a2(4);
	TreeLinkNode a3(1);
	TreeLinkNode a4(3);
	TreeLinkNode a5(-1);
	TreeLinkNode a6(5);
	TreeLinkNode a7(1);
	TreeLinkNode a8(6);
	TreeLinkNode a9(8);
	a0.left=&a1;
	a0.right=&a2;
	a1.left=&a3;
	a2.left=&a4;
	a2.right=&a5;
	a3.left=&a6;
	a3.right=&a7;
	a4.right=&a8;
	a5.right=&a9;
	Solution sl;
	sl.connect(&a0);


}