#include "globe.h"

class Solution {
public:
	vector<vector<int> > res;
	
	void change(vector<int> &num,int depth)
	{
		if(depth==num.size()+1)
		{
			return;
		}
		for(int i=depth;i<num.size();i++)
		{
			bool exchange=true;
			for(int k=depth-1;k<i;k++)
			{
				if(num[k]==num[i])
				{
					exchange=false;
				}
			}
			if(exchange)
			{
			 vector<int> add=num;
			 int temp=add[depth-1];
			 add[depth-1]=add[i];
			 add[i]=temp;
			 res.push_back(add);
			 change(add,depth+1);
			}
		}
		change(num,depth+1);
	}
    vector<vector<int> > permute(vector<int> &num) {
		res.push_back(num);
		change(num,1);
        return res;
    }
};

void main()
{
	Solution sl;
	vector <int > num;
	num.push_back(1);
	num.push_back(2);
	num.push_back(2);
	//num.push_back(4);
	vector<vector<int> > res=sl.permute(num);
	
	waitKey();
}