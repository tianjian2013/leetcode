#include "globe.h"

class Solution {
public:
    bool wordBreak(string s, set<string> &dict) {
        int n=s.size();
        if(n==0) return false;
        vector<bool> ref(n+1,false);
        ref[0]=true;
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<i;j++)
            {
                string str=s.substr(j+1,i-j);
                if(ref[j]&&dict.count(str))
                {
                    ref[i]=true;
                    break;
                }
            }
        }
        return ref[n];
    }
};

void main()
{
	Solution sl;
	set<string>  sss;
	sss.insert("a");
	

	bool ret=sl.wordBreak("a",sss);
	cout<<ret;

}	
