#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int  > ret;

int a0[]={0};
	int a1[]={9,8,7,6,5,4,3,2,1,0};
	int a2[]={9,8,6,5,3,2,0};
	int a3[]={9,6,3};
	int a4[]={9,8,7,6,5,4,0};
	int a5[]={9,8,6,5,0};
	int a6[]={9,6};
	int a7[]={9,8,7,0};
	int a8[]={9,8,0};
	int a9[]={9};
	int *a[10]={a0,a1,a2,a3,a4,a5,a6,a7,a8,a9};
	int size[]={ 1,10,7,3,7,5,2,4,3,1};

int dfs(string &str,int i,bool suiyi)
	
{
	if(i==str.size()) return 0;

	if(suiyi )
	{
		ret.push_back(  a[ret[i-1]][size[ret[i-1]]]  );
		dfs(str,i+1,suiyi);
		return 0;
	}

	int k=(int )(str[i]-'0');

	int x=0;
	while(x<  size[ret[i-1]] )
	{
		
		if(a[ret[i-1]][x]<=k) break;
		x++;
	}

	if(x== size[ret[i-1]] ) return -1;
	else
	{
		while(x<  size[ret[i-1]] )
	    {
		   ret.push_back(a[ret[i-1]][x]);
		   int mm=dfs(str,i+1,suiyi||a[ret[i-1]][x]==k);
		   if(mm==-1) 
			{
				x++;
				ret.pop_back();
		    }
		   else return 0;
		}
	}
	return -1;

}

int cal(string &str)
{
	ret.clear();

	int k=(int )(str[0]-'0');
	for(int m=k;m>=0;m--)
	{
		 ret.push_back(m);
		 if (  dfs(str,1,m==k)==0 ) break;
		 ret.pop_back();
	}
	int num=0;
	for(int i=0;i<ret.size();i++)
		num=num*10+ret[i];
	cout<<num<<endl;
	return 0;
}


int main()
{
    int k;
	cin>>k;
	

	for(int i=0;i<k;i++)
	{
		string str;
		cin>>str;
		cal(str);
	}

}