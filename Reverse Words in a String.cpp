#include "globe.h"

class Solution {
public:
    string ret;
    bool init;
    void reverse(string &s,int start,int end)
    {
        /*while(start<end)
        {
            swap(s[start],s[end]);
            start++;
            end--;
        }*/
        if(init==false) init=true;
        else
        {
            ret+=" ";
        }
        if(start==end)  
        {
          ret.push_back(s[start]);
          return;
        }
        for(int i=end;i>=start;i--)
        {
            ret.push_back(s[i]);
        }
    }
    void reverseWords(string &s) {
        int index=-1;
        int i=0;
        init =false;
        while(i<s.size() )
        {
            if(s[i]==' ')
            {
                if(index!=-1)  
                {
                    reverse(s,index,i-1);
                    //string tmp=s.substr(index,i-index);
                    //ret+=tmp;
                    //ret+=" ";
                    index=-1;
                }
                
            }
            else
            {
                if(index==-1)
                {
                    index=i;
                }
            }
            i++;
        }
        if(index!=-1)  reverse(s,index,i-1);
        //string tmp=s.substr(index,i-index);
        //ret+=tmp;
        //ret+=" ";
        
        s=ret;
        
    }
};

void main()
{
	Solution sl;
	string input="the sky ";
	sl.reverseWords(input);
}