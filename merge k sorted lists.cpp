#include "globe.h"

class cmp
{
public:
	bool operator () (ListNode *p1,ListNode*p2)
	{
		return  p1->val<p2->val; 
	}
};

class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
       if(lists.empty() ) return NULL;
       
       priority_queue< ListNode *,vector< ListNode*>,cmp> pq;
       ListNode res(0);
       for(int i=0;i<lists.size();i++)
       {
           if(lists[i])  pq.push(lists[i]);
       }
       if(pq.empty() ) return NULL;
       
       ListNode *dfs=pq.top();
       res.next=dfs;
       pq.pop();
       if(dfs->next)  pq.push(dfs->next);
       
       while(!pq.empty())
       {
            ListNode *tmp=pq.top();
            dfs->next=tmp;
            pq.pop();
			dfs=tmp;
            if(tmp->next)  pq.push(tmp->next);
       }
       return res.next;
       
       
        
    }
};

void main()
{
	ListNode *a1=new ListNode(1);
	ListNode *a2=new ListNode(2);
	ListNode *a3=new ListNode(3);
	a1->next=a2;
	a2->next=a3;
	vector<ListNode *> lists;
	lists.push_back(a1);
	Solution sl;
	ListNode *res=sl.mergeKLists(lists);
}