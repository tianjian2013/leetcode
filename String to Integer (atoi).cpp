#include "globe.h"

class Solution {
public:
    int atoi(const char *str) {
        int ret=0;
        bool neg=false;
        while(*str==' ')
        {
            str++;
        }
        if(*str=='-')
        {
            neg=true;
            str++;
            if(*str<'0'||*str>'9') return 0;
        }
        if(*str=='+')
        {
            str++;
            if(*str<'0'||*str>'9') return 0;
        }
        while(*str!='\0')
        {
            if(ret<0) break;
            if(*str>='0'&&*str<='9')
            {
              int k=(int)(*str-'0');
              ret*=10;
              ret+=k;
            }
            else
              break;
            str++;
        }
        if(ret<0) return neg?INT_MIN:INT_MAX ;
        else return neg?-ret:ret;
    }
};

void main()
{
	char input[]="  -0012a42";
	Solution sl;
	int res=sl.atoi(input);
	
}