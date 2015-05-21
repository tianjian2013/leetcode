#include "globe.h"

int  main()
{
	int a[]={3,2,1,5,4};
	int n=5;
	stack<int > sk;
	int j=0;
	for(;j<a[0];j++)
	{
		sk.push(j);
	}
	for(int i=1;i<n;i++)
	{
		if(a[i]<a[i-1])
		{
			if(sk.size()==0) return -1;
			int k=sk.top();
			if(k!=a[i]) return -1;
			sk.pop();
		}
		else
		{
			for(;j<a[i];j++)
				sk.push(j);
		}
	}
	return 0;
}