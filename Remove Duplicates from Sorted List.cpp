#include "globe.h"

 // Definition for singly-linked list.
 struct ListNode {
      int val;
      ListNode * next;
      ListNode(int x) : val(x), next(NULL) {}
  };

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {

		/**************************************
        vector<int> once;
        ListNode *start=head;
		if(!head)
		{
			 return head;
		}
        while(start->next!=NULL)
        {
			once.push_back(start->val);
            bool remove=false;

            for(size_t i=0;i<once.size();i++)
            {
                if(once[i]==start->next->val)
                {
                    remove=true;
                    break;
                }
            }
            if(remove)
            {
                ListNode * temp=start->next;
                start->next=temp->next;
               // delete temp;
            }
			else
			{
            start=start->next;
			}
			if(start==NULL)
			{
				break;
			}
        }
        return head;
        /**************************************/
		if(head==NULL)
		{
			return head;
		}
		ListNode * start=head;
		ListNode  vitualnode(0);
		vitualnode.next=start;
		ListNode * pre=&vitualnode;

		while(start->next!=NULL)
		{
			if(start->val==start->next->val)
			{
				ListNode *temp=start;
				while(start->val==temp->val)
				{
					start=start->next;
					if(start==NULL)
					{
						break;
					}	
				}
				(*pre).next=start;
			}
			else
			{
				pre=start;
				start=start->next;
			}
			if(pre->next==NULL)
			{
				break;
			}
		}
        return vitualnode.next;
    }
};
void main()
{
	Solution sl;
	ListNode n1(1);
	ListNode n2(1);
	ListNode n3(1);
	ListNode n4(1);
	n1.next=&n2;
	n2.next=&n3;
	ListNode * res=sl.deleteDuplicates(&n1);
	while(res!=NULL)
	{
		cout<<res->val<<endl;
		res=res->next;
	}
	waitKey();
}