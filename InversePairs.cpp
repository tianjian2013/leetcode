#include "help.h"

int ret;
void qsort(vector <int > & data,int start,int end )
{
  if(start>=end) return ;
  int val=data[start];
  int p=start+1;
  for(int i=p;i<=end;i++)
  {
     if( data[i]<val )
     {
        ret+=i-p+1;
        int tmp=data[i];
       for(int j=i;j>p;j--)
             data[j]=data[j-1];
        data[p]=tmp;
        p++;
     }
  }
  
  qsort(data,start+1,p-1);
  qsort(data,p,end);
  //swap(data[start],data[p-1]);
}
int InversePairs(vector<int> data) {

ret=0;
qsort(data,0,data.size()-1);
return ret;

}

int main()
{
 int a[]={4,5,3,5,2};
vector <int > input(a,a+5);
cout<<InversePairs(input) ;
}
