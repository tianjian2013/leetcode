
//#include <vector>
//using namespace std;
#include "help.h"

bool searchMatrix(vector<vector<int> >& matrix, int target)
{        
  
 int n=matrix.size();
       if(n==0) return false;
       int m=matrix[0].size();
       if(m==0) return false;
       int xp=0,xq=n-1,yp=0,yq=m-1;
       
      int p=xp,q=xq;
      int mid;
      while(p<=q)
      {
        mid=(p+q)>>1;
        if(matrix[mid][yp]==target)
          return true;
        else if(matrix[mid][yp]>target)
          q=mid-1;
        else
        {
          if(mid+1>q || matrix[mid+1][yp]>target) break;
          else
                p=mid+1;
        }
      }
      if(p>q) return false;
      xq=mid;
      
      p=xp,q=xq;
      while(p<=q)
      {
        mid=(p+q)>>1;
        if(matrix[mid][yq]==target)
          return true;
        else if(matrix[mid][yq]<target)
          p=mid+1;
        else
        {
          if(mid-1<p || matrix[mid-1][yq]<target) break;
          else
                q=mid-1;
        }
      }
      if(p>q) return false;
      xp=mid;


      p=yp,q=yq;
      while(p<=q)
      {
        mid=(p+q)>>1;
        if(matrix[xp][mid]==target)
          return true;
        else if(matrix[xp][mid]>target)
          q=mid-1;
        else
        {
          if(mid+1>q || matrix[xp][mid+1]>target) break;
          else
                p=mid+1;
        }
      }
      if(p>q) return false;
      yq=mid;
      
       p=yp,q=yq;
      while(p<=q)
      {
        mid=(p+q)>>1;
        if(matrix[xq][mid]==target)
          return true;
        else if(matrix[xq][mid]<target)
          p=mid+1;
        else
        {
          if(mid-1<p || matrix[xq][mid-1]<target) break;
          else
                q=mid-1;
        }
      }
      if(p>q) return false;
      yp=mid;

      for(int i=xp;i<=xq;i++)
{
 for(int j=yp;j<=yq;j++)
 {
   if(matrix[i][j]==target) return true;
 }
}
return false;
    }


int main()
{

vector<vector<int> > matrix;
int a0[]={1,4,7,11,15};
int a1[]={2,5,8,12,19};
int a2[]={3,6,9,16,22};
int a3[]={10,13,14,17,24};
int a4[]={18,21,23,26,30};
 
vector <int> b0(a0,a0+5);
vector <int> b1(a1,a1+5);
vector <int> b2(a2,a2+5);
vector <int> b3(a3,a3+5);
vector <int> b4(a4,a4+5);

matrix.push_back(b0);
matrix.push_back(b1);
matrix.push_back(b2);
matrix.push_back(b3);
matrix.push_back(b4);

cout<<searchMatrix( matrix, 5);
  
  return 0;

}
