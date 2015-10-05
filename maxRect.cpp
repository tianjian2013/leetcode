#include "help.h"



int largest(vector <int > &height)
   {
     int ret=0;
       height.push_back(0);
       stack<int> ref;
       int i=0;
       while(i<height.size() )
       {
           if(ref.empty()|| height[i]>=height[ref.top()])
               ref.push(i++);
           else
           {
               int k=ref.top();
               ref.pop();
               int newret=height[k]*(ref.empty()?i:i-ref.top()-1);
               ret=max(ret,newret);
           }
       }
       return ret;
   }
int maximalRectangle(vector<vector<int> >& matrix) {

 int n=matrix.size();
        if(n==0) return 0;
        int m=matrix.size();
        if(m==0)  return 0;
        vector<vector<int > > a(n, vector <int > (m,0));
        for(int j=0;j<m;j++)
        {
            int lianxu=0;
            for(int i=0;i<n;i++)
            {
                if(matrix[i][j]=='0')
                {
                    lianxu=0;
                }
                else
                {
                    lianxu++;
                    a[i][j]=lianxu;
                }
            }
        }
        int ret=0;
        for(int i=0;i<n;i++)
        {
            ret=max(ret,largest(a[i]));
        }
        return ret;

}
int main()
{

   vector <vector <int > > input=read2D();
   //show2D(input);
cout<<maximalRectangle(input);
   return 0;
}
