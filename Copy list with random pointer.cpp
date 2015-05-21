#include "globe.h"
 
 struct RandomListNode {
     int label;
     RandomListNode *next, *random;
      RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 };

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(head==NULL) return NULL;
        RandomListNode *res=NULL;
        RandomListNode *p=head;
        while(p)
        {
            RandomListNode *tmp =p->next;
            RandomListNode *newnode =new RandomListNode (p->label);
            newnode->next=tmp;
            p->next=newnode;
            p=tmp;
        }
        p=head;
        while(p)
        {
            if(p->random==NULL) p->next->random=NULL;
            else 
            {
                p->next->random=p->random->next;
            }
            p=p->next->next;
        }
        p=head;
        res=p->next;
        RandomListNode *q=res;
        RandomListNode *tmp=NULL;
        while(q->next)
        {
            tmp=q->next;
            p->next=q->next;
            q->next=tmp->next;
            p=tmp;
            q=tmp->next;
        }
		p->next=NULL;
        return res;
        
    }
};


void main()
{
	RandomListNode a(-1);
	Solution sl;
	sl.copyRandomList(&a);
}