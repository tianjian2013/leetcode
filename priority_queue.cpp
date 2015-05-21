#include "globe.h"

class cmp
{
public:
	bool operator () (ListNode *p1,ListNode*p2)
	{
		return  p1->val<p2->val; 
	}
};

void main()
{
	priority_queue< ListNode *,vector< ListNode*>,cmp> pq;
	
	ListNode *a1= new ListNode(1);
	ListNode *a2= new ListNode(5);
	ListNode *a3= new ListNode(3);
	ListNode *a4= new ListNode(2);

	pq.push(a1);
	pq.push(a2);
    pq.push(a3);
	pq.push(a4);


	while(!pq.empty() )
	{
		cout<< pq.top()->val<<" ";
		pq.pop();
	}
	cout<<endl;

}