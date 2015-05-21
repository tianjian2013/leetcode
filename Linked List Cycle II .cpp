#include "globe.h"
class Solution {
public:
     
    ListNode *detectCycle(ListNode *head) {
        
        if(head==NULL||head->next==NULL)
        {
            return NULL;
        }
        ListNode *fast=head->next;
        ListNode *start=head;
        while(fast->next!=NULL)
        {
            if(fast->next==head->next)
            {
                //return true;
                break;
            }
            fast=fast->next;
            head=head->next;
            if(fast->next==NULL)
            {
                return NULL;
            }
            else
            {
             fast=fast->next;
            }
        }
        if(fast->next==head->next)
        {
            while(start->next!=NULL)
            {   
                fast=fast->next;
				 while(fast->next!=head->next)
                {
                    if(start->next==fast->next)
                    {
                        break;
                    }
                    fast=fast->next;
                }
                if(fast->next==start->next)
                break;
                start=start->next;
            }
            return start->next;
        }
        else
        {
            return NULL;
        }
      
        
    }
};

void main()
{

	Solution sl;
	ListNode a0(0);
	//ListNode a1(1);
	a0.next=&a0;
	//a1.next=&a0;
	ListNode *res=sl.detectCycle(&a0);
	waitKey();
}