#include "globe.h"

class Solution {
public:
    string getPermutation(int n, int k) {
      vector <int> ref;
       string ret;
       int chu=1;
       for(int i=0;i<n;i++)  
       { 
           ref.push_back(i+1);
           if(i) chu*=i;
       }
       for(int i=n-1;i>=0;i--)
       {
           int m=k/chu;
           if(m&&k%chu==0) m--;
           ret.push_back('0'+ref[m]);
           for(int j=m;j<i;j++)
           {
               ref[j]=ref[j+1];
           }
           k%=chu;
           if(i) chu/=i;
       }
       return ret;
    }
};

void main()
{
	Solution sl;
	cout<<sl.getPermutation(3,2)<<endl;
}