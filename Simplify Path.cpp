#include "globe.h"

class Solution {
public:
    string simplifyPath(string path) {
        if(path.compare("/")==0) return path;
        
        vector <string> ref;
        string diandian="..";
        string dian=".";

		int i=0;
		string str;
		while(i<path.size())
		{
			if(path[i]=='/')
			{
				if(!str.empty()) 
				{
					if(str.compare(diandian)==0)
					{
						if(!ref.empty())
                          ref.pop_back();
					}
					else if(str.compare(dian)==0)
                    { 
                    }
                    else
                    {
                       ref.push_back(str);
                    }
					str.clear();
				 }
			}
			else
			{
				str.push_back(path[i]);
			}
			i++;
		}
        ref.push_back(str);
        string ret;
        for(int i=0;i<ref.size();i++)
        {
            ret+="/"+ref[i];
        }
        return ret;
    }
};

void main()
{
	Solution sl;
	string res=sl.simplifyPath("/...");
}