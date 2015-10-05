#include "help.h"

    string makeRange(int a,int b)
    {
         stringstream ssa,ssb;
         string stra,strb;
         string ret;
         ssa<<a;
         ssa>>stra;
         ret+=stra;
         if(b==a) return ret;
       
         ret+="->";
         ssb<<b;
         ssb>>strb;
         ret+=strb;
         return ret;
         
    }
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ret;
        int n=nums.size();
        if(n==0 )  return ret;
        int pre=0,next=1;
        while(next<n)
        {
            if(  (next-pre) !=  (nums[next]-nums[pre]) )
            {
              ret.push_back(makeRange(nums[pre],nums[next-1]));
              pre=next;
            }
            next++;
        }
        ret.push_back(makeRange(nums[pre],nums[next-1]));
        return ret;
    }


int main()
{

  int a[]={0,1};
  vector<int> input(a,a+2);
  vector <string> ret=summaryRanges(input);
  for(int i=0;i<ret.size();i++)
   cout<<ret[i]<<endl;  
  return 0;
}
