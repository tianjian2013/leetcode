#include "globe.h"

class Solution {
public:
    int trap(int A[], int n) {
		 if(n<3)  return 0;
       vector <int > leftmax(n,0);
       vector <int > rightmax(n,0);
       
       int left=A[0];
       for(int i=1;i<n-1;i++)
       {
           if(A[i-1]>left)
           {
               left=A[i-1];
           }
           leftmax[i]=left;
       }
       int right=A[n-1];
       for(int i=n-2;i>0;i--)
       {
           if(A[i+1]>right)
           {
               right=A[i+1];
           }
           rightmax[i]=right;
       }
       int res=0;
       for(int i=1;i<n-1;i++)
       {
           int h=min(rightmax[i],leftmax[i]);
           if(h-A[i]>0)
           res+=h-A[i];
       }
       return res;
    }
};

void main()
{   
	
	Solution sl;
	int a[]= {5,2,1,2,1,5};
	int res=sl.trap(a,6);
	waitKey();
}