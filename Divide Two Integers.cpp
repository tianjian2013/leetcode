#include "globe.h"

class Solution {
public:
    int divide(int dividend, int divisor) {
        //if(divisor==INT_MIN) return 0;
		long long ddddd= dividend;
        long long ooooo= divisor;

        bool neg=false;
        if(dividend<0)
        {
             ddddd=-ddddd;
            neg=!neg;
        }
        if(divisor<0)
        {
            ooooo=0-ooooo;
            neg=!neg;
        }
        if(ddddd==0) return  0;
		if(ooooo==1) return  neg?-ddddd:ddddd;
		
        if(ddddd<ooooo) return 0;
        
       long long ret=0;
       long long sum=ooooo;
       long long k=1;
       long long error=ddddd-sum;
       
       while(error>ooooo)
       {
           sum+=sum;
           k+=k;
            error= dividend-sum;
           if(error<0)
           {
               k>>=1;
               sum>>=1;
               ddddd-=sum;
               ret+=k;
               
               k=1;
               sum=ooooo;
              // dividend-=sum;
               error=ddddd-ooooo;
           }
       }
       ret+=k;
       return neg?-ret:ret;
        
    }
};

void main()
{
	int min=INT_MIN;
	int max=INT_MAX;
	Solution sl;
	int ret=sl.divide(1026117192, -874002063);
}