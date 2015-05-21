#include "globe.h"

class Solution {
public:
    int lengthOfLastWord(const char *s) {
        int res=0,res1=0;
        string str(s);
        //char * go=s;
        int i=0;
        while(i!=str.size())
        {
            if(   (  (str[i])>='a' && (str[i])<='z' )  || (  (str[i])>='A' && (str[i])<='Z' ))
            {
                res++;
            }
            else
            {
                //res1=res;
				if(res) res1=res;
                res=0;
            }
            i++;
        }
        
        if(res)  return res;
        else return res1;
    }
};

void main()
{
	char  s[]="b   a    ";
	Solution sl;
	int res=sl.lengthOfLastWord(s);
	cout<<res;
	waitKey();
}
