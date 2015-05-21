#include "globe.h"

class Solution {
public:
    int reverse(int x) {
        int input=x;
        int bitnum=0;
        if(x<0)
        {input=-input;}
        vector<int > num;
        int res=0;
        while(input!=0)
        {
            bitnum++;
            num.push_back(input%10);
            input/=10;
        }
        if(bitnum==0)
        {
            return 0;
        }
        for(int i=0;i<bitnum;i++)
        {
            for(int j=0;j<bitnum-i-1;j++)
            {
                num[i]=num[i]*10;
            }
            res+=num[i];
        }
        if(x<0)
        {res=-res;}
        return res;
    }
};

void main()
{
	Solution sl;
	int res=sl.reverse(123);
	cout<<res<<endl;
	waitKey();

}