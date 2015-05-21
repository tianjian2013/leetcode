#include "globe.h"

class Solution {
public:
    vector<vector<int> > res;
    void dfs(vector<int> &S,int start, vector<int> &base)
    {
        for(int i=start;i<S.size();i++)
        {
            if(i==start||S[i]>S[i-1])
            {
                base.push_back(S[i]);
                res.push_back(base);
                dfs(S,i+1,base);
                base.pop_back();
            }
        }
    }
    
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        sort(S.begin(),S.end());
        vector<int> base;
        res.push_back(base);
        dfs(S,0,base);
        return res;
    }
};


void main()
{
	vector<int> m1;
	m1.push_back(1);
	m1.push_back(2);
	m1.push_back(2);
	
	Solution sl;
	vector<vector<int> > res=sl.subsetsWithDup(m1);

	waitKey();
}