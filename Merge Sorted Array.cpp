#include "globe.h"
class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int up=m-1,down=n-1;
        int res=m+n-1;
        while(res>=0)
        {
            if(up<0)
            {
               A[res]=B[down];
                down--;
				 res--;
                continue;
            }
            if(down<0)
            {
                A[res]=A[up];
                up--;
				 res--;
                continue;
            }
            if(A[up]>B[down])
            {
                A[res]=A[up];
                up--;
            }
            else
            {
                A[res]=B[down];
                down--;
            }
            res--;
        }
        
    }
};

void main()
{
	int A[]={1,2,3,2,5,6};
	int B[]={2,5,6};
	 Solution sl;
	 sl.merge(A,3,B,3);
		 for(int i=0;i<6;i++)
		 {
			 cout<<A[i]<<endl;
		 }
		 waitKey();
}