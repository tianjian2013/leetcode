#include "globe.h"

class Solution {
public:
    ListNode *findmiddle(ListNode *head)
    {
        ListNode *p=head;
        ListNode *q=head;
         while(p!=NULL&&p->next!=NULL)
        {
            p=p->next;
            p=p->next;
            if(p==NULL) break;
            q=q->next;
        }
        ListNode *t=q->next;
        q->next=NULL;
        return t;
    }
    ListNode * merge(ListNode *p1,ListNode *p2)
    {
        ListNode tmp(0);
        ListNode *dfs=&tmp;
        while(p1&&p2)
        {
            if(p1->val<p2->val)
            {
                dfs->next=p1;
				dfs=p1;
                p1=p1->next;
				
            }
            else
            {
                dfs->next=p2;
				dfs=p2;
                p2=p2->next;
			
            }
        }
        if(p1) dfs->next=p1;
        if(p2)  dfs->next=p2;
        return tmp.next;
    }
    ListNode *sortList(ListNode *head) 
    {
        if(head==NULL||head->next==NULL) return head;
        ListNode *tmp=findmiddle(head);
        return merge( sortList(head),sortList(tmp) );
    }
};

void main()
{
	ListNode *a0=new ListNode (2);
	ListNode *a1=new ListNode (1);
	a0->next=a1;
	Solution sl;
	ListNode *res=sl.sortList(a0);
}