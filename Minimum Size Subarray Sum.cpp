#include "globe.h"
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        
        int p=0;
        int q=0;
        int ret=0;
        int sum=0;
        
        while(q<nums.size() &&sum<s)
        {
			sum+=nums[q];
			q++;    
        }
        if(q==nums.size()&&sum<s ) return ret;
        else ret=q-p;
        
        while(p<nums.size() )
        {
            sum-=nums[p];
            p++;
             while(q<nums.size() &&sum<s)
             {
			    sum+=nums[q];
			    q++;    
            }
            if(q==nums.size()&&sum<s ) return ret;
            else ret=min(ret,q-p);
        }    
        return ret;
    }
};

void main()
{
	int a[]={1,2,3,4,5};
	Solution sl;
	vector <int> b(a,a+5);
	cout<<sl.minSubArrayLen(11,b);
}