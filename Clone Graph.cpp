#include "globe.h"



  //Definition for undirected graph.
  struct UndirectedGraphNode {
      int label;
      vector<UndirectedGraphNode *> neighbors;
      UndirectedGraphNode(int x) : label(x) {};
  };

class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(node==NULL) return NULL;
        map <int, UndirectedGraphNode *> flag;
        queue <UndirectedGraphNode *> src;
        flag[node->label]=NULL;
        src.push(node);
        while( src.size() )
        {
            UndirectedGraphNode * t=src.front();
            flag[t->label]=new UndirectedGraphNode(t->label);
            src.pop();
            for(int i=0;i<t->neighbors.size();i++)
            {
                
                if(  flag.count(t->neighbors[i]->label)==0 )
                {
                
                    src.push(t->neighbors[i]);
                }
                
            }
           
        }
        map <int, int> flag1;
        src.push(node);
        while( src.size() )
        {
            UndirectedGraphNode * t=src.front();
            flag1[t->label]=0;
            src.pop();
            for(int i=0;i<t->neighbors.size();i++)
            {
                if(  flag1.count (  t->neighbors[i]->label )==0 )
                {
                    src.push(t->neighbors[i]);
                }
                flag[t->label]->neighbors.push_back(flag[t->neighbors[i]->label]);
                
            }
           
        }
        return flag[node->label];
        
    }
};


void main()
{
	UndirectedGraphNode *n0= new UndirectedGraphNode(-1);
	UndirectedGraphNode *n1= new UndirectedGraphNode(1);
	n0->neighbors.push_back(n1);
	Solution sl;
	UndirectedGraphNode *res=sl.cloneGraph(n0);
}