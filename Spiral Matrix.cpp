#include "globe.h"

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> res;
        int m=matrix.size();
        if(m==0) return res;
        int n=matrix[0].size();
        if(n==0)  return res;
        int startx=0,endx=n-1,starty=0,endy=m-1;
        
        while(res.size()!=m*n)
        {
            for(int i=startx;i<=endx;i++)
               res.push_back(matrix[starty][i]);
			if(res.size()==m*n) break;
            starty++;
            
            for(int i=starty;i<=endy;i++)
               res.push_back(matrix[i][endx]);
			if(res.size()==m*n) break;
            endx--;
          
            for(int i=endx;i>=startx;i--)
               res.push_back(matrix[endy][i]);
			if(res.size()==m*n) break;
            endy--;
            
            for(int i=endy;i>=starty;i--)
               res.push_back(matrix[i][startx]);
            startx++;
        }
		return res;
    }
};

void main()
{   
	
	Solution sl;
	vector<int> m1;
	m1.push_back(1);
	m1.push_back(2);
	vector<vector<int> > matrix;
	matrix.push_back(m1);

	vector<int> res=sl.spiralOrder(matrix);
	showvector(res);
	waitKey();
}