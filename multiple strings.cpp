#include "globe.h"

class Solution {
public:
    string multiply(string num1, string num2) {
        vector<string > tmp;
        string ret;
        int retsize=0;
        for(int i=0;i<num2.size();i++)
        {
            int x=num2[num2.size()-1-i]-'0';
            string s;
            int jinwei=0;
            for(int j=0;j<num1.size();j++)
            {
                int t=num1[num1.size()-1-j]-'0';
                int res=t*x;
                char c='0'+res%10;
                jinwei=res/10;
                s.push_back(c);
            }
            if(jinwei) s.push_back('0'+jinwei);
            reverse(s.begin(),s.end());
            if(i+1+s.size()>retsize) retsize=i+1+s.size();
            tmp.push_back(s);
        }
        //vector<int  >  retn(retsize,0);
        for(int i=0;i<retsize;i++)
        {
            int k=0;
            int jinwei=0;
            for(int j=0;j<min(i+1,(int)tmp.size() ) ;j++)
            {
                if(tmp[j].size()-1-i+j>=0)
                {
                  k+=tmp[j][tmp[j].size()-1-i+j];
                }
            }
            jinwei=k/10;
            ret.push_back('0'+k%10);
        }
        return ret;
        
        
    }
};