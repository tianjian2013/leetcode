#include "globe.h"
class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        vector <int > :: iterator iter=digits.end();
        iter--;
        while(iter!=digits.begin())
        {
            
            if(*iter!=9)
            {
                  *iter+=1;
                  break;
            }
            else
            {
                *iter=0;
            }
			iter--;
        }
        if(iter==digits.begin())
        {
            if(*iter==9)
            {
                *iter=1;
                digits.push_back(0);
            }
            else
            {
                *iter+=1;
            }
        }
		return digits;
    }
};

void main()
{
	Solution sl;
	vector<int> digits;
	digits.push_back(1);
	digits.push_back(0);
	vector<int> res= sl.plusOne(digits);
	waitKey();
}