#include <iostream>
#include <string>
#include <vector>

using namespace std;

int kmp(string& src,string& dst)
{
   int ret=0;
   int n1=src.size(),n2=dst.size();
   if(n1>n2) return 0;
   vector <int> ref(n1+1,0);
   ref[0]=-1;
   for(int i=2;i<n1+1;i++)
   {
       int k=ref[i-1];
       while(k!=-1)
       {
         if(src[i-1]==src[k])
         {
            ref[i]=k+1;
            break;
         }
         else 
           k=ref[k];
       }
   }
   int i=0,j=0;
   while(i<n2)
   {
	   if(dst[i]==src[j])
	   {
		   i++;
		   j++;
		   if(j==n1)
	       {
		     ret++;
		     j=ref[n1];
		     //i=i-n1+1;
		     continue;
	        }
		   
	    }
	   else
	   {
	     if (j==0) i++;
	     else j=ref[j];
	   }
   }
   return ret;

}

int main()
{
	int k;
	cin>>k;
	for(int i=0;i<k;k++)
	{
		string src,dst;
		cin>>src;
		cin>>dst;
		cout<<kmp( src, dst)<<endl;
	}
	return 0;
}
