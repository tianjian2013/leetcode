#include "globe.h"

class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
       ListNode *p=head;
        ListNode *start=NULL;
        for(int i=0;i<m-1;i++) 
        {
            start=p;
            p=p->next;
        }
        
        ListNode *up=NULL;
        ListNode *first=p;
        ListNode *down=p->next;
        for(int i=0;i<n-m;i++)
        {
            if(p->next )  up=p->next->next;
            down->next=p;
            p=down;
            down=up;
        }
        first->next=down;
        if(start)
        {
            start->next=p;
            return head;
        }
        else
        {
            return p;
        }
        
    }
};

void main()
{
	ListNode *a1=new ListNode(1);
	ListNode *a2=new ListNode(2);
	ListNode *a3=new ListNode(3);
	a1->next=a2;
	a2->next=a3;
	Solution sl; 
	ListNode *res=sl.reverseBetween(a1,1,3);
	waitKey();

}