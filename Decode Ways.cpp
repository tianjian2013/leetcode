#include "globe.h"

class Solution {
public:
    int numDecodings(string s) {
      if(s.size()==0|| s[0]=='0')  return 0;
      vector<int > tmp(s.size()+1,1);
      for(int i=1;i<s.size();i++)
      {

		  if(s[i]=='0')
		  {
			  if(s[i-1]>='3'||s[i-1]=='0') return 0;
			  else 
			  {
					  tmp[i+1]=tmp[i-1];
					  continue;
			  }
		  }
          if(s[i-1]=='1' || (s[i-1]=='2'&&s[i]<='6') )
             tmp[i+1]=tmp[i]+tmp[i-1];
          else
             tmp[i+1]=tmp[i];
      }
      return tmp[s.size()];
    }
};

void main()
{
	string input("10");
	Solution sl;
	int ret=sl.numDecodings(input);
	cout<<ret;
}