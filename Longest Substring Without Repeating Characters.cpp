#include "globe.h"

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector <int> pos(256,-1);
        int max=0;
        int start=-1;
        for(int i=0;i<s.size();i++)
        {
            
            if( pos[   (int)(s[i])  ]>start)
            {
                start=pos[(  int)s[i]];
            }
            pos[(unsigned  int) s[i]]=i;
            if(i-start>max)  max=i-start;
           
        }
        return max;
    }
};

void main()
{
	Solution sl;
	int res=sl.lengthOfLongestSubstring("avcvadacbasd");
}