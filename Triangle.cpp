#include "globe.h"

class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
       int n=triangle.size();
        if(n==0) return 0;
        vector<int >ref (n,0);
        ref[0]=triangle[0][0];
        for(int i=1;i<n;i++)
        {
            vector<int >tmp (n,0);
            tmp[0]=ref[0]+triangle[i][0];
            for(int j=1;j<i;j++)
            {
                tmp[j]=triangle[i][j]+min(ref[i-1],ref[i]);
            }
            tmp[i]=ref[i-1]+triangle[i][i];
            swap(tmp,ref);
        }
        return *min_element(ref.begin(),ref.end() );
        
        
    }
};


void main()
{
	Solution sl;

	vector<int> m0;
	m0.push_back(-1);

	vector<int> m1;
	m1.push_back(2);
	m1.push_back(3);

	vector<int> m2;
	m2.push_back(1);
	m2.push_back(-1);
	m2.push_back(-1);

	vector<vector<int> > input;
	input.push_back(m0);
	input.push_back(m1);
	input.push_back(m2);

	int res=sl.minimumTotal(input);
	cout<<res<<endl;
	waitKey();
}