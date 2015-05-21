#include "globe.h"

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
		map<int,int> ref;
        vector<int> res;
        for(int i=0;i<numbers.size();i++)
        {
            if(ref.count(target-numbers[i]))
            {
                    res.push_back(ref[target-numbers[i]]+1);
                    res.push_back(i+1);
                    return res;      
            }
            ref[numbers[i]]=i;
        }
        return res;
    }
};

void main()
{
	Solution sln;
	vector<int> input;
	input.push_back(0);
	input.push_back(4);
	input.push_back(3);
	input.push_back(0);
	vector<int> res=sln.twoSum(input,0);
	cout<<"sdfs"<<endl;
}