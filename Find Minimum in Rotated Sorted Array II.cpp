#include "globe.h"

class Solution {
public:
    int findMin(vector<int> &num) {
        int ret=INT_MAX;
        int start=0,end=num.size()-1;
        while(start<=end)
        {
            int mid=(start+end)>>1;
            if(num[start]<ret)  ret=num[start];
            if(num[end]<ret)  ret=num[end];
            if(num[mid]<ret)  ret=num[mid];
            
            if(num[start]>num[mid]) end=mid-1;
            else if(num[end]<num[mid])  start=mid+1;
            else 
            {
                if(num[mid]!=num[mid+1]) start=mid+1;
                if(num[mid]!=num[mid-1]) end=mid-1;
                else break;
            }
        }
        return ret;
    }
};

void main()
{
	vector <int >  input ;
	input.push_back(3);
	input.push_back(3);
	input.push_back(1);
	input.push_back(3);

	Solution sl;
	int ret =sl.findMin(input);
}