
#include "globe.h"
class Solution {
public:
    void rotate(int nums[], int n, int k) {
        if(k==0||n<2) return ;
        k=k%n;
        if(k==0) return;
        if(n%k==0&&k>1)
        {
            for(int i=0;i<k;i++)
            {
                int val=nums[n-1-i];
                int dis=i;
                while(dis+k<n)
                {
                    nums[n-1-dis]=nums[n-1-dis-k];
                    dis+=k;
                    //k+=k;
                }
                nums[n-1-dis]=val;
            }
        }
        else
        {
          int flag=n-1;
          int flagval=nums[flag];
          int dis=0;
          do
          {
            int newdis=(dis+k)%n;
            if(newdis==0) nums[n-1-dis]=flagval;
            else nums[n-1-dis]=nums[n-1-newdis];
            dis=newdis;
          }while(dis);
        }
    }
};

void main()
{
    Solution sl;
	int input[]={1,2};
	sl.rotate(input,2,1);
}