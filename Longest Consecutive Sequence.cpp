#include "globe.h"
class Solution {
public:
    int longestConsecutive(vector<int> &num) {
		/*
		int ret=0;
		set <int > ref(num.begin(),num.end());
        while(ref.size() )
        {
            set <int > ::iterator it=ref.begin();
            int k =*it;
			ref.erase(k);
			int length=1;
			while(ref.count(--k))
			{
				ref.erase(k);
				length++;
			}
			k+=length;
			while(ref.count(++k))
			{
				ref.erase(k);
				length++;
			}
			if(length>ret) ret=length;
        }
		return ret;*/

		 map<int ,int > ref;
       int max=0;
       for(int i=0;i<num.size() ;i++)
       {
           
           int m=num[i];
           
           if(ref.count (m) )  continue;
           
           if( !ref.count(m-1) && !ref.count(m+1) )  ref[m]=1;
           else if(   !ref.count(m) && ref.count(m+1))
           {
               ref[m]=ref[m+1]+1;
               ref[  m+ref[m+1]    ]=ref[m];
               
           }
           else if(   ref.count(m-1) && !ref.count(m+1)  )
           {
               ref[m]=ref[m-1]+1;
               ref[  m-ref[m-1]    ]=ref[m];
           }
           else 
           {
                int k= ref[  m+1    ]+ ref[  m-1    ]+1;
                ref[  m+ref[m+1]    ]=k;
                ref[  m-ref[m-1]    ]=k;
                ref[m]=k;
           }
           
           if(ref[m]>max) max=ref[m];
        }
        return max;
    }
};
void main()
{
    Solution sl;
	vector<int> m1;
	
	m1.push_back(-1);
	m1.push_back(1);
	m1.push_back(0);
	int res=sl.longestConsecutive(m1);
	cout<<res;
	//waitKey();
}