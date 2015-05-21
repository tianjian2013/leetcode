#include "globe.h"

class Solution {
public:
    int maxProfit(vector<int> &prices) {
       
       if(prices.size()<2)
       {
           return 0;
       }
       //int * a=new int[prices.size()];
	   vector<int> a(prices.size(),0);
       a[0]=0;
       int min=prices[0];
       for(int i=1;i<prices.size();i++)
       {
           if(prices[i]-min>a[i-1])
           {
               a[i]=prices[i]-min;
           }
           else
           {
               a[i]=a[i-1];
           }
           if(prices[i]<min)
           {
               min=prices[i];
           }
       }
	   int res=a[prices.size()-1];
       //int * b=new int[prices.size()];
	   vector<int> b(prices.size(),0);
	   b[prices.size()-1]=0;
	   int max=prices[prices.size()-1];
	   for(int k=prices.size()-2;k>=0;k--)
	   {
		   if(max-prices[k]>b[k+1])
           {
               b[k]=max-prices[k];
           }
           else
           {
               a[k]=b[k+1];
           }
           if(prices[k]>max)
           {
               max=prices[k];
           }
		   if(b[k]+a[k]>res)
		   {
			   res=b[k]+a[k];
		   }
	   }
	  // res=res>b[0]?res:b[0];
	   return res;
    }
};

void main()
{
	Solution  sl;
	vector<int> prices;
	prices.push_back(6);
	prices.push_back(1);
	prices.push_back(3);
	prices.push_back(2);
    prices.push_back(4);
	prices.push_back(7);

	int res=sl.maxProfit(prices);
	cout<<res<<endl;
	waitKey();
}