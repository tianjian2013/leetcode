#include "globe.h"

class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        
        int n=strlen(haystack);
        int m=strlen(needle);
        if(m==0&&n==0)  return haystack;
        if(m==0)  return haystack;
        
        vector<int > pi(strlen(needle)+1,0);
        int k=0;
        for(int q=2;q<=strlen(needle);q++)
        {
            while(k>0&& (*(needle+k)!=*(needle+q-1)))
            {
                k=pi[k];
            }
            if(   *(needle+k)==*(needle+q-1)       )  k++;
            pi[q]=k;
        }
        
        int q=0;
        for(int i=1;i<=n;i++)
        {
            while(q>0&& (*(needle+q)!=*(needle+i-1)))
            {
                q=pi[q];
            }
            if(  *(needle+q)==*(haystack+i-1) )  
			{
				q++;
			}

            if(q==m)  return haystack+i-m;
           // q=pi[q];
        }
        
        return NULL;
    }
};

void main()
{
	char src[]="mississippi";
	char tem[]="a";
	Solution sl;
	char* res=sl.strStr(src,tem);
}