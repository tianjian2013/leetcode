#include "globe.h"
class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        sort(num.begin(),num.end());
        vector<vector<int> > res;
        for(int i=0;i<num.size();i++)
        {
            int p=i+1,q=num.size()-1;
            while(p<q)
            {
             int sum=num[i]+num[p]+num[q];
             if(sum>0)
             {
                q--;
             }
             else if(sum<0)
             {
                p++;
             }
             else
             {
                vector<int> tmp;
                tmp.push_back(num[i]);
                tmp.push_back(num[p]);
                tmp.push_back(num[q]);
                res.push_back(tmp);
				p++;
				q--;
             }
            }
        }
        return res;
    }
};

void main()
{
	Solution sln;
	vector<int> input;
	input.push_back(0);
	input.push_back(0);
	//input.push_back(3);
	input.push_back(0);
	vector<vector<int> >  res=sln.threeSum(input);
	cout<<"sdfs"<<endl;
}