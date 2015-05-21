#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;
    
    if(k<0||k>=n) return -1;
    
    vector <int >seq(n,0);
    for(int i=0;i<n;i++)
       cin>>seq[i];
       
       
    int m=0,p=1,q=n-1;
    while(k>0)
    {
      for(int i=p;i<=q;i++)
      {
         if(seq[i]<seq[m]) 
         {   
            swap(seq[i],seq[p]);
            p++;
			  
         }
      }
      swap(seq[m],seq[p-1]);
      if(p-m==k) 
      {
        cout<<seq[p-1]<<endl;
        return 0;
      }
      else if(p-m>k)
      {
        //k=p-k;
        // m=0;
        q=p-2;
      }
      else 
       {
        k=k-p+m;
        m=p;
        p=m+1;
       }
    }
    return 0;
}