#include "globe.h"

class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
       if(!head) return NULL;
        ListNode *res=head->next;
        if(!res) return head;
        ListNode *go=res;
        ListNode *last=head;
        while(go)
        {
            ListNode *tmp=go->next;
            go->next=last;
            if(!tmp) 
            {  
                last->next=NULL;
                break;
            }
            if(!tmp->next) 
            {
             last->next=tmp;
             break;
            }
            last->next=tmp->next;
            last=tmp;
            go=tmp->next;
        }
        return res;
        
    }
};

void main()
{
	ListNode l1(1);
	ListNode l2(2);
	l1.next=&l2;
	Solution sl;
	ListNode *res=sl.swapPairs(&l1);
    waitKey();
}