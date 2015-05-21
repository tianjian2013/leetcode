#include "globe.h"

class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
     int n=matrix.size();
      int innerloop=n-1;
        for(int i=0;i<(n+1)/2;i++)
        {
            for(int j=i;j<innerloop+i;j++)
            {
                int x=i,y=j,tmp=0,tmp1=0;
                    tmp=matrix[y][n-x-1];
                    matrix[y][n-x-1]=matrix[x][y];
                    int temp1=x;
                    x=y;
                    y=n-1-temp1;

					tmp1=matrix[y][n-x-1];
					matrix[y][n-x-1]=tmp;
					temp1=x;
                    x=y;
                    y=n-1-temp1;

					tmp=matrix[y][n-x-1];
					matrix[y][n-x-1]=tmp1;
					temp1=x;
                    x=y;
                    y=n-1-temp1;

					tmp1=matrix[y][n-x-1];
					matrix[y][n-x-1]=tmp;
					temp1=x;
                    x=y;
                    y=n-1-temp1;

            }
            innerloop-=2;
        }
        
    }
};

void main()
{   Solution  sl;
    vector<int> a0;
	a0.push_back(1);
	a0.push_back(2);
	vector<int> a1;
	a1.push_back(3);
	a1.push_back(4);
	vector<vector<int> > input;
	input.push_back(a0);
	input.push_back(a1);
	sl.rotate(input);
	waitKey();
}