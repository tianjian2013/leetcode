#include "globe.h"


class Solution {
public:
	int step(int pre)
	{
		int res=0;
		if(pre>0)
		{
		//int sum = 0;
		//for(int i=0;)
		//vector <int > add1=pre;
		//add1.push_back(1);
		res+=step(pre-1);
		//add1.pop_back();
		//add1.push_back(2);
		res+=step(pre-2);
		}
		
		
		else if(pre==0)
		{
			res+=1;
		}
		else
		{
		
		}
		return res;
	}
    int climbStairs(int n) {
      if( n==1)  return 1;
      if( n==2)  return 2;
      int res=0;
      vector<int > num;
      num.push_back(1);
      num.push_back(2);
      int index=2;
      while(index!=n)
      {
          res=num[index-1]+num[index-2];
          num.push_back(res);
          index++;
      }
      return res;
    }
};


void main()
{
	Solution sl;
	int res=sl.climbStairs(4);
    cout<<res<<endl;
	waitKey();
}