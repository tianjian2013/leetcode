#include "globe.h"

int calc(string &str)
{
	string str1;
	while(1)
	{    
		bool xiaochu=false;
		int n=str.size();
		if(n<2) break;
		int i=0;
		while(i<n)
		{
			if(i==n-1) 
			{ 
				str1.push_back(str[i]);
				break;
			}
			if(str[i]==str[i+1])
			{
				xiaochu=true;
				i+=2;
				while(i<n&&str[i]==str[i-1])
				{
					i++;
				}
			}
			else
			{
				str1.push_back(str[i]);
				i++;
			}

		}
		swap(str,str1);
		str1.clear();
		if(!xiaochu) break;
	}
	return str.size();
}

int  main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		string input;
		cin>>input;
		int a=input.size();
		int b=calc(input);
		int min=b;
		for(int j=0;j<b;j++)
		{
			string input1=input;
			input1.insert(j,1,input[j]);
			int newmin=calc(input1);
			if(newmin<min) min=newmin;
		}
		cout<<a-min+1<<endl;

	}
	return 0;
}
