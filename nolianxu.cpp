#include "globe.h"


bool visit(string &ret,int m,int n,int pre0,int pre1)
{
	if(m==0&&n==0) return true;
	if(m>0&&pre0==0)
	{
		ret.push_back('0');
		if(visit(ret,m-1,n,1,0)) 
			 return true;
		else 
			ret.pop_back();
	}
	if(n>0&&pre1<2)
	{
		ret.push_back('1');
		if(visit(ret,m,n-1,0,pre1+1))
			return true;
		else 
			ret.pop_back();
	}
	return false;
}


void main()
{
	int m=2,n=7;
	string ret;
	if(visit(ret,m,n,0,0) )
    	cout<<ret<<endl;
}