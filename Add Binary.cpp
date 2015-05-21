#include "globe.h"

class Solution {
public:
    string addBinary(string a, string b) {
    int lena=a.size();
    int lenb=b.size();
    int lenres=0,times=0;
    if(lena>lenb)  {lenres=lena;  times=lenb;}
    else           {lenres=lenb;  times=lena;}
    string res(lenres,'0');
    bool jinwei=false;
    int i;
    for( i=0;i<times;i++)
    {
        if(a[lena-1-i]!= b[lenb-1-i])
        {
            if(!jinwei) 
            { 
                res[lena-1-i]=1;
            }
        }
        else
        {
            if(a[lena-1-i]=='0')
            {
                if(jinwei) 
                {
                    res[lena-1-i]='1';
                    jinwei=false;
                }
            }
            else
            {
                if(jinwei) 
                {
                    res[lena-1-i]='1';
                }
                jinwei=true;
            }
        }
		 }
    if(lenres==lena)
    {
      for(;i<lenres;i++)
      {
        if(jinwei)
        {
			if(a[lena-1-i]=='0')   {res[lena-1-i]='1'; jinwei=false;}
        }
        else
        {
            res[lena-1-i]=a[lena-1-i];
        }
	  }
    }
    else
    {
         for(;i<lenres;i++)
      {
        if(jinwei)
        {
			if(a[lena-1-i]=='0') {res[lena-1-i]='1'; jinwei=false;}
        }
        else
        {
            res[lena-1-i]=a[lena-1-i];
        }
      }
    }
    
    if(jinwei )  return ("1"+res);
    else 
    return res;
    
        
    }
};


void main()
{
	string a="10010";
	string b="110";
	Solution sl;
	string res=sl.addBinary(a,b);
	cout<<res;
	waitKey();
}
