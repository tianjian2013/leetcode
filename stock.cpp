#include "globe.h"
class jizhidian
{
    public :
    int val,flags;
    jizhidian(int x,int y)
    {
        val=x;
        flags=y;
    }
};

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        
        int res=0;
        
        if(prices.size()<=1)
        {
            return 0;
        }
        if(prices.size()==2)
        {
             return (prices[1]-prices[0])>0?prices[1]-prices[0]:0;
        }
        
        int min=0,max=prices.size()-1;
        res=prices[max]-prices[min]>=0?prices[max]-prices[min]:0;

		int newmin=min;
		while(newmin<max)
        {

		}

        
        while(min<max)
        {
           int newmin=min+1;
           while(newmin<max)
           {
              if(prices[newmin]<=prices[newmin-1]&&prices[newmin]<=prices[newmin+1])
              {
                  min=newmin;
				  break;
              }
              newmin++;
           }
           if(newmin==max)
           {
               break;
           }
           int newmax=max-1;
           while(newmax>0)
           {
              if(prices[newmax]>=prices[newmax-1]&&prices[newmax]>=prices[newmax+1])
              {
                  max=newmax;
				  break;
              }
              newmax--;
           }
           
           if(newmin==max)
           {
               break;
           }
           if(prices[max]-prices[min]>res)
           {
               res=prices[max]-prices[min];
           }
          
        }
       
        return res;
        
        
    }
};

void main()
{
	vector<int> test;
	test.push_back(1);
    test.push_back(4);
    test.push_back(2);
	//test.push_back(6);
	//test.push_back(4);
	Solution sl;
	int res=sl.maxProfit(test);

	cout<<res<<endl;
}