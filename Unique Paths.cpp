#include "globe.h"

class Solution {
public:
    int uniquePaths(int m, int n) {
       
        if(m<=1||n<=1)  return 1;
        vector < vector <int > > res(m,vector<int> (n,0) );
        //int tmp1=1;
        for(int i=0;i<m;i++)  res[i][0]=1;
        for(int i=1;i<n;i++)  res[0][i]=1;
        
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
             
             res[i][j]=res[i-1][j]+res[i][j-1];
            //res=   (res*(m+i) )/i;
          
        }
        return res[m-1][n-1];
        
    }
};
void main()
{
	Solution sl;
	int res=sl.uniquePaths(2,2);
}