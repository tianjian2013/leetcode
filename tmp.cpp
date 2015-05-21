#include <iostream>
#include <vector>
#include <opencv2\opencv.hpp>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <queue>
#include <algorithm>

using namespace std;
using namespace cv;


class Solution {
public:
	void reOrderArray(vector<int> &array) {
		int p=-1;
        int i=0;
        int n=array.size();
        while(i<n)
            {
            if(array[i]%2)
                {
               // swap(array[p+1],array[i]);
                int k=array[i];
                for(int j=i;j>p+1;j--)
                    array[j]=array[j-1];
                array[p+1]=k;
                p++;
            }
            i++;
        }
	}
};


void main()
{
	Solution sl;
	vector <int > input;
	for(int i=0;i<7;i++)
	input.push_back(i+1);
	sl.reOrderArray(input);

}