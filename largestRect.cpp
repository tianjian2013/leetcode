#include "help.h"

 
int largestRectangleArea(vector<int>& height) {
 int ret=0;
       height.push_back(0);
       stack<int> ref;
       int i=0;
       while(i<height.size() )
       {
           if(ref.empty()|| height[i]>height[ref.top()])
               ref.push(i++);
           else
           {
               int k=ref.top();
               ref.pop();
               int newret=height[k]*(ref.empty()?i:i-k);
               ret=max(ret,newret);
           }
       }
       return ret; 

}

int main()
{
  int a[]={2,4};
  vector<int> input(a,a+2);
  cout<<largestRectangleArea(input);
}
