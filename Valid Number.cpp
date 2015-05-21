#include "globe.h"
class Solution {
public:
    bool isNumber(const char *s) {
        if(s=='\0')  return false;
        int num=0;
        while(s!='\0')
        {
            
            if( (*s>='0'&&*s<='9') || (*s>='a'&&*s<='f') || (*s>='A'&&*s<='F') )
            {
                
            }
            else if(*s=='.')
            {
                num++;
                if(num==2)  return false;
            }
            else
            {
                return false;
            }
            s++;
        }
        return true;
    }
};

void main()
{
	char *input="3";
	Solution sl;
	bool ret=sl.isNumber(input);
}