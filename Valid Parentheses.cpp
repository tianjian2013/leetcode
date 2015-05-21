#include "globe.h"

class Solution {
public:
    bool isValid(string s) {
        int x=0,y=0,z=0;
        stack <char> sk;
        for(int i=0;i<s.size();i++)
        {
            
            if(s[i]=='(' || s[i]=='['  || s[i]=='{')
            {
                sk.push(s[i]);
            }
            else
            {
                if(  sk.empty() )  return false;
				char tmp=sk.top();
                if(s[i]==')' && tmp=='(' )  sk.pop();
				else if(s[i]==']' && tmp=='[' )  sk.pop();
				else if(s[i]=='}' && tmp=='{' )  sk.pop();
                else return false;
            }
        }
        if(  sk.empty() )  return true;
        else
        return false;
    }
};

void main()
{
	Solution sl;
	string str ("()");
	bool res=sl.isValid(str);
	waitKey();
}