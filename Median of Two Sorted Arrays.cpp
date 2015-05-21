#include "globe.h"

class Solution {
public:
    double findKthElements(int A[], int m, int B[], int n,int k)
    {
        if(m>n)  
		{
			return findKthElements(B,n,A,m,k);
		}
        if(m==0) return B[k];
        if(k==0) return min(A[0],B[0]);
        
        int pa=min(m-1,k/2), pb=k-pa-1;
        if(A[pa]>B[pb] )  return findKthElements(A,m,B+pb+1,n-pb-1,k-pb-1);
        else if(A[pa]<B[pb] )  return findKthElements(A+pa+1,m-pa-1,B,n,k-pa-1);
        else return A[pa];
    }
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        if( (m+n)%2==0 )  return (double)(findKthElements(A,m,B,n,(m+n)>>1)+ findKthElements(A,m,B,n,(m+n)/2-1) )/2.0;
        else return findKthElements(A,m,B,n,(m+n)>>1);
     }
};

void main()
{
	int a[]={1,2};
	int b[]={1,2};
	Solution sl;
	double ret=sl.findMedianSortedArrays(a,2,b,2);
}