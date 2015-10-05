#include "help.h"

int find(vector<int>& nums, int k,int start,int end)
{
  int val=nums[start];
   int p=start+1;
        for(int i=start+1;i<=end;i++){
           if(nums[i]>val){
               p++;
               swap(nums[p-1],nums[i]);
           }
        }
        swap(nums[p-1],nums[start]);
        if(p-1==k) return val;
        else if(p-1>k)
          return find(nums,k,start,p-2);
        else
          return find(nums,k,p,end);

  
}
int findKthLargest(vector<int>& nums, int k) {
        int n=nums.size();
        if(k>n) return 0;
        return find(nums,k-1,0,n-1);       
}

int main()
{
  //int a[]={1,7,3,4,9,6,2,8};
  //vector <int> input(a,a+8);
vector <int> input(1,1);
  cout<<findKthLargest(input,1);
   return 0;
}
