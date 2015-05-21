#include "globe.h"
#include <limits>

class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
      int gap=INT_MAX;
	  int res;
     sort(num.begin(), num.end());
     for(int i=0;i<num.size()-2;i++)
     {
         int start=i+1;
         int end=num.size()-1;
         
         int sum3tmp=num[i]+num[start]+num[end];
         int cha=sum3tmp-target;
         
         if(cha>0)
         {
            
             if(abs(cha)<gap) 
			 {gap=abs(cha);res=num[i]+num[start]+num[end];}
             end--;
             while(cha>0&&end>start)
             {
                 //sum3tmp=num[i]+num[start]+num[end];
                 cha=cha-num[end+1]+num[end];
                 end--;
             }
             if(end<=start)
             {
                 end++;
                 cha=num[i]+num[start]+num[end]-target;
                 if(abs(cha)<gap) 
				 {gap=abs(cha);res=num[i]+num[start]+num[end];}
             }
             else
             {
				 end++;
               if(abs(cha)<gap) {gap=abs(cha);res=num[i]+num[start]+num[end];}
               cha=cha-num[end]+num[end-1];
               if(abs(cha)<gap) {gap=abs(cha);res=num[i]+num[start]+num[end];}
             }
         }
         else if(cha<0)
         {
           
             if(abs(cha)<gap) {gap=abs(cha);res=num[i]+num[start]+num[end];}
             start++;
             while(cha<0&&end>start)
             {
                 //sum3tmp=num[i]+num[start]+num[end];
                 cha=cha-num[start-1]+num[start];
                 start++;
             }
             if(end<=start)
             {
                 start--;
                  cha=num[i]+num[start]+num[end]-target;
                  if(abs(cha)<gap) {gap=abs(cha);res=num[i]+num[start]+num[end];}
             }
             else
             {
				 start--;
             if(abs(cha)<gap) {gap=abs(cha);res=num[i]+num[start]+num[end];}
             cha=cha-num[start]+num[start+1];
             if(abs(cha)<gap) {gap=abs(cha);res=num[i]+num[start]+num[end];}
            }
         }
         else
         {
             return target;
         }
		
	 }
	  return res;
    }
};

void main()
{
	vector<int> m1;
	m1.push_back(1);
	m1.push_back(2);
	m1.push_back(4);
	m1.push_back(8);
	m1.push_back(16);
	m1.push_back(32);
	m1.push_back(64);
	m1.push_back(128);
	Solution sl;
	int res=sl.threeSumClosest(m1,82);
	waitKey();
}