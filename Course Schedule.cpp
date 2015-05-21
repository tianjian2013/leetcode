
#include "globe.h"

class Solution {
public:
    vector <int > ret;
  vector <int > findOrder(int numCourses,vector< pair<int,int> > & prerequisites)
  {
     vector < vector <int>  > mm(numCourses);
     for(int i=0;i<prerequisites.size();i++)
     {
         mm[prerequisites[i].second].push_back(prerequisites[i].first);
     }
     vector <int > status(numCourses,0);

	 for (int i=0;i<numCourses;i++)
	 {
		 if(status[i]==0 )
		 {
			  if (  dfs(mm,0,status)==false  ) 
			  {
				  ret.clear();
                return ret;
			  }
		 }
	 }
     reverse(ret.begin(),ret.end());
     return ret;
    
  } 
  bool dfs(vector < vector <int>  > &mm,int node,vector <int > &status)
  {
     status[node]=1;
     for(int i=0;i<mm[node].size();i++)
     {
         if(  status [  mm[node][i]  ]==1) return false;
         if(  status [ mm[node][i]  ] ==0) 
                 { 
                        if (    dfs(mm,mm[node][i],status) ==false )  return false; 
                 }
     }
     status[node]=2;
     ret.push_back(node);
     return true;
    }
};

int main()
{
  Solution sl;
  vector< pair<int,int> >  prerequisites;
  prerequisites.push_back(make_pair(1,0));
  prerequisites.push_back(make_pair(2,0));
  prerequisites.push_back(make_pair(3,1));
  prerequisites.push_back(make_pair(3,2));
 
  vector <int > ret=sl.findOrder(4,prerequisites);
  return 0;     

}