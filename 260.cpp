#include "help.h"

vector<int> singleNumber(vector<int>& nums) {
        vector<int> ret;
        if(nums.size()<2)
        {
            return ret;
        }
        int xors=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            xors^=nums[i];
        }
        int base=1;
        while( (base&xors)==0)
        {
            base<<=1;
        }
        int a,b;
        bool ainit=false;
        bool binit=false;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]&base)
            {
                if(ainit)
                {
                    a^=nums[i];
                }
                else
                {
                    ainit=true;
                    a=nums[i];
                }
            }
            else
            {
                if(binit)
                {
                    b^=nums[i];
                }
                else
                {
                    binit=true;
                    b=nums[i];
                }
            }
        }
        if(ainit&&binit)
        {
            ret.push_back(a);
            ret.push_back(b);
        }
        return ret;
        
    }


int main()
{
 int a[]={1,2,1,3,2,5};
 vector<int> input(a,a+6);
 vector<int> ret=singleNumber(input);
 showvector(ret);
}
