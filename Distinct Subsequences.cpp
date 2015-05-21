#include "globe.h"

class Solution {
public:
   
    int numDistinct(string S, string T) {
        int m=S.size();
        int n=T.size();
        vector <  vector <int > > ref (m+1,vector <int > (n+1 , 0)  );
        for(int i=1;i<=m;i++) ref[i][0]=1;
        
        for(int i=1;i<=m;i++ )
        {
            for(int j=1;j<=n;j++)
            {
                if(S[i-1]==T[j-1])
                {
                    ref[i][j]=ref[i-1][j]+ref[i-1][j-1];
                }
                else
                {
                     ref[i][j]=ref[i-1][j-1];
                }
            }
        }
        return ref[m][n];
       
    }
};

void main()
{
	string a="ccc";
	string b="c";
	Solution sl;
	int res=sl.numDistinct(a,b);
	cout<<res;
	waitKey();
}