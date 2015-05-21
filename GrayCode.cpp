#include "globe.h"


class Solution {
public:
    vector<int> grayCode(int n) {
         int resnum=1<<n;
		 vector<int> res;
        for(int i=0;i<resnum;i++)
        {
            int base=2;
            int sum=0;
            for(int j=0;j<n;j++)
            {
                sum+=   (   (i+(1<<j))/base   )   %2  *   (1<<j);
                base*=2;
            }
            res.push_back(sum);
        }
        return res;
    }
};

void main()
{
	Solution sl;
	vector<int> res=sl.grayCode(4);
	for(int i=0;i<res.size();i++)
	{
		cout<<res[i]<<endl;
	}
	waitKey();
}