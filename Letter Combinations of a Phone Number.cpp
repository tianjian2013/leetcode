#include "globe.h"
class Solution {
public:
    vector<string> res;
    void dfs(string &digits,int index,string base)
    {
        if(index==digits.size() )  
        {
             res.push_back(base);
             return ;
        }
        char ch='a';
        int gap=digits[index]-'2';
        if(digits[index]>='2' &&  digits[index]<='6')
        {
            
            ch+=3*gap;
            for(int i=0;i<3;i++,ch++)
            {
                
                //base+=ch++;
                dfs(digits,index+1,base+ch);
                //base[base.size()-1]='\0';
            }
        }
        else if(digits[index]=='7')
        {
            ch+=3*gap;
            for(int i=0;i<4;i++,ch++)
            {
                
                //base+=ch++;
                dfs(digits,index+1,base+ch);
                //base[base.size()-1]='\0';
            }
        }
        else if(digits[index]=='8')
        {
            ch+=3*gap+1;
            for(int i=0;i<3;i++,ch++)
            {
                
                //base+=ch++;
                dfs(digits,index+1,base+ch);
                //base[base.size()-1]='\0';
            }
	    }
        else if(digits[index]=='9')
        {
            ch+=3*gap+1;
            for(int i=0;i<4;i++,ch++)
            {
                
               // base+=ch++;
                dfs(digits,index+1,base+ch);
                //base[base.size()-1]='\0';
            }
        }
        else
        {
            dfs(digits,index+1,base);
        }
    }
    
    vector<string> letterCombinations(string digits) {
        string base;
        dfs(digits,0,base);
        return res;
    }
};

void main()
{
	Solution sl;
	string input("22");
	vector<string> res=sl.letterCombinations(input);
	waitKey();
}