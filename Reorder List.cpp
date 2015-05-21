#include "globe.h"

class Solution {
public:
    ListNode *findmid(ListNode *head)
    {
        ListNode *p=head;
		ListNode *q=head;
		while(p&&p->next)
		{
			p=p->next;
			p=p->next;
			if(p==NULL) break;
			q=q->next;
		}
		ListNode *ret=q->next;
		q->next=NULL;
		return ret;
    }
    ListNode *reverse(ListNode *head)
	{
		if(head==NULL||head->next==NULL) return head;
		ListNode *p=head;
		ListNode *q=head->next;
		while(q)
		{
			ListNode *tmp=q->next;
			q->next=p;
			p=q;
			q=tmp;
		}
		head->next=NULL;
		return p;
	}
    void reorderList(ListNode *head) {
        if(head==NULL||head->next==NULL) return;
        ListNode *half=findmid(head);
		half=reverse(half);
		ListNode *p=head;
		while(p&&half)
		{
			ListNode *p_next=p->next;
			ListNode *half_next=half->next;
			p->next=half;
			half->next=p_next;
			p=p_next;
			half=half_next;
		}
		//return head;
    }
};

void main()
{
	 ListNode a1(1);
	 ListNode a2(2);
	 ListNode a3(3);

	 a1.next=&a2;
	 a2.next=&a3;

	 Solution sl;
	 sl.reorderList(&a1);
}