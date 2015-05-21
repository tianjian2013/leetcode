#include "globe.h"

class Solution {
public:
   
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *p1=l1;
        ListNode *p2=l2;
        ListNode *res=NULL;
        ListNode *last=NULL;
        bool jinwei=false;
        while(p1||p2)
        {
            int add;
            if(p1==NULL) add=p2->val;
            else if(p2==NULL) add=p1->val;
            else  add=p1->val+p2->val;
            if(jinwei) add++;
            if(add>9) 
            { jinwei=true; add-=10;}
            else jinwei=false;
            
            ListNode *tmp=new ListNode (add);
            if(res==NULL) 
            { 
                res=tmp;
            }
            else
            {
                last->next=tmp;
            }
            last=tmp;
            if(p1) p1=p1->next;
            if(p2) p2=p2->next;
        }
        if(jinwei) 
        {
             ListNode *tmp=new ListNode (1);
             last->next=tmp;
        }
        return res;
    }
};

void main()
{
	ListNode m1(0);
	ListNode n1(7);
	ListNode n2(3);
	n1.next=&n2;
	Solution sl;
	ListNode *res=sl.addTwoNumbers(&m1,&n1);
	waitKey();
}