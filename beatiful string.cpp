#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int commomsubstring(string &s1,string &s2)
{
	int ret=0;
	int indexs2=0;
	int i=0;

	while(i<s1.size()-2&&indexs2<s2.size()-2)
	{
		string start=s1.substr(i,3);
		for(int j=indexs2;j<s2.size()-2;j++)
		{
			string starts2=s2.substr(j,3);
			if(!start.compare(starts2) )
			{
				ret+=3;
				int p=i+3,q=j+3;
				while(p<s1.size()&&q<s2.size()&&s1[p]==s2[q])
				{
					p++;
					q++;
					ret++;
				}
				i=p-1;
				indexs2=q;
				break;
			}
		}
		i++;
	}
	return ret;
}


void main()
{
	string s1;
	cin>>s1;
	string s2;
	cin>>s2;
	int res=commomsubstring(s1,s2);
	cout<<res;
}
