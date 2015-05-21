#include "globe.h"

class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<int> row1;
        row1.push_back(1);
        vector<vector<int> > res;
        if(numRows==0)
        {
            return res;
        }
        res.push_back(row1);
        for(int i=2;i<=numRows;i++)
        {
            vector<int> thisrow;
            thisrow.push_back(1);
            for(int j=1;j<i-1;j++)
            {
                thisrow.push_back(res[i-2][j-1]+res[i-2][j]);
            }
            thisrow.push_back(1);
            res.push_back(thisrow);
        }
        return res;
        
    }
};

void main()
{
	vector<vector<int> > res;
	Solution sl;
	res=sl.generate(3);
	waitKey();
}