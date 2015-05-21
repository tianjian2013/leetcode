#include "globe.h"

class Solution {
public:
	int calcnum(int i,int j)
    {
        if(i>j)
            return 0;
         if(i==j)
         {
                return 1;
         }
            int res=0;
            for(int k=i+1;k<=j-1;k++)
            {
                res+=calcnum(i,k-1)*calcnum(k+1,j);
            }
            res+=calcnum(i+1,j);
            res+=calcnum(i,j-1);
            return res;
        }
    }
    int numTrees(int n) {
         return calcnum(1,n);
    }
};

void main()
{
	Solution sl;
	int res=sl.numTrees(2);
	cout<<res<<endl;
	waitKey();
}