class Solution {
public:
    void sortColors(int A[], int n) {
        int a0=-1,a1=-1;
        int rear=n-1;
        for(int i=0;i<=rear;i++)
        {
            if(A[i]==0)
            {
                a0+=1;
                a1+=1;
                A[a0]=0;
                if(a1!=a0)
                   A[a1]=1;
            }
            else if(A[i]==1)
            {
                a1+=1;
            }
            else if(A[i]==2)
            {
                A[i]=A[rear];
                A[rear]=2;
                rear--;
                i--;
            }
            else
            {
                return ;
            }
        }
        
    }
};