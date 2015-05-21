#include "globe.h"

class Solution {
public:
    void nextPermutation(vector<int> &num) {
        if(num.size()<2) return ;
        int i=num.size()-2,j=i+1;
        while(i>=0)
        {
            if(num[i]<num[j])  break;
            i--;
            j--;
        }
        if(i<0) sort(num.begin(),num.end());
        int k=num.size()-1;
        while(k>i)
        {
            if(num[k]>num[i])
            {
                swap(num[k],num[i]);
            }
            k--;
        }
        int m=num.size()-1;
        while(j<m)
        {
            swap(num[j],num[m]);
            j++;
            m--;
        }
    }
};

void main()
{
	vector<int> input(2,1);
	Solution sl;
	sl.nextPermutation(input);
}