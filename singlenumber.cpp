#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    int singleNumber(int A[], int n) {
        int x[32];
         memset(x, 0, sizeof(x)); 
        for(int i=0;i<32;i++)
        {
            for(int j=0;j<n;j++)
            {
                x[i]+=  (A[j]>>i)&(1);
            }
            x[i]%=3;
        }
        
        int res=0;
        for(int i=0;i<32;i++)
        {
            res+= (x[i]<<i);
        }
        return res;
        
    }
};

void main()
{
	int a[]={1};
	Solution sl;
	sl.singleNumber(a,1);
}