#include "globe.h"

/****************Subsets*******/
class Solution {
public:
	vector<vector<int> > res;
	void dfs(int start,int n, vector <int > &base,vector<int> &S)
	{
		for(int i=start;i<n;i++)
		{
			//vector <int > temp=base;
			base.push_back(S[i]);
			res.push_back(base);
			dfs(i+1,n,base,S);
			base.pop_back();
		}
	}
     vector<vector<int> > subsets(vector<int> &S)  {
		sort(S.begin(), S.end());
		int n=S.size();
		vector <int > base;
		for(int i=0;i<n;i++)
		{
		  vector <int > temp=base;
		  temp.push_back( S[i] );
		  res.push_back(temp);
          dfs(i+1,n,temp,S);
		}
		return res;
    }
};

void main()
{  Solution sl;
  // vector<vector<int> > res=sl.subsets(3,2);
   vector<int> input;
   input.push_back(4);
   input.push_back(1);
   input.push_back(7);
   vector<vector<int> > res=sl.subsets(input);
   for(int i=0;i<res.size();i++)
   {
	   showvector(res[i]);
   }
   waitKey();
}