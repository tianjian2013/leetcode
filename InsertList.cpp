#include "help.h"

ListNode* insertionSortList(ListNode* head) 
{
	if (head == NULL || head->next == NULL) return head;
        ListNode pre(0);
        pre.next = head;
        ListNode* p = head;
        while(p->next)
        {
            ListNode *toInsert = p->next;
            ListNode *next = p->next->next;
            p->next = NULL;
            ListNode *h = &pre;
            while(h->next && h->next->val <= toInsert->val)
            {
                h = h->next;
            }
            if (h->next ==NULL)
            {
                p = p->next;
            }
            else
            {
                ListNode *tmp = h->next;
                h->next = toInsert;
                toInsert->next = tmp;
                p->next = next;
            }
        }
        return pre.next;
}

int main()
{
	ListNode n0(1);
	ListNode n1(1);
	n0.next = &n1;
	ListNode *ret = insertionSortList(&n0);
}
