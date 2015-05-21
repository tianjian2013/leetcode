#include "globe.h"
#include <map>

class Solution {
public:
  
    vector<string> anagrams(vector<string> &strs) {
        map <string,int>  mp;
		vector<string> res;
        for(int i=0;i<strs.size();i++)
        {
            string str=strs[i];
            sort(str.begin(),str.end() );
            map <string,int> ::iterator it;
			it=mp.find(str);
			if(it==mp.end() )
			{
				mp[str]=i;
			}
			else
			{
				if(mp[str]==-1)
				{
					res.push_back(strs[i]);
				}
				else
				{
					res.push_back(strs[mp[str]]);
					mp[str]=-1;
					res.push_back(strs[i]);
				}
			}
            
        }
    }
};



