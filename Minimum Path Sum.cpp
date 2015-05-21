#include "globe.h"
class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        if(grid.size()==0)  return 0;
        int m=grid.size(),n=grid[0].size();
		int **c=new int *[m];
		for(int k=0;k<m;k++)
		{
			c[k]=new int [n];
		}
        //int c[m][n];
       // c[0][0]=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                int tmp1=0,tmp2=0,sum1=0,sum2=0;
                if(i-1<0)
                {
                    sum1=-1;
                }
                else
                {
                    sum1=c[i-1][j];
                }
                if(j-1<0)
                {
                    sum2=-1;
                }
                else
                {
                    sum2=c[i][j-1];
                }
    
                //tmp=sum1<sum2?sum1;sum2;
               // tmp2=sum1>=sum2?sum1;sum2;
               if(sum1<sum2)
               {
                   tmp1=sum1;
                   tmp2=sum2;
               }
               else
               {
                   tmp1=sum2;
                   tmp2=sum1;
               }
                if(tmp1>=0)
				{
                    c[i][j]=tmp1+grid[i][j];
                }
                else if(tmp2>=0)
                {
                    c[i][j]=tmp2+grid[i][j];
                }
                else
                {
                    c[i][j]=grid[i][j];
                }
                
            }
        }
        return c[m-1][n-1];
        
    }
};

void main()
{
	Solution sl;
	vector<int> a1;
	a1.push_back(1);
	a1.push_back(2);
	vector<int> a2;
	a2.push_back(1);
	a2.push_back(1);

	vector<vector<int> > grid;
	grid.push_back(a1);
	grid.push_back(a2);
	int res=sl.minPathSum(grid);
	cout<<res<<endl;
	waitKey();

}