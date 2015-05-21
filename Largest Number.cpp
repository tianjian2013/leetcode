#include "globe.h"

bool  cmp( const string  & n1,const string & n2)
{
       string s1=n1+n2;
       string s2=n2+n1;
       for(int i=0;i<s1.size();i++)
       {
           if(s1[i]==s2[i]) continue;
           else return s1[i]>s2[i];
       }
       return true;
}
class Solution {
public:
   
    string largestNumber(vector<int> &num) {
        vector <string > ref;
		 int maxdata= *max_element(num.begin(),num.end());

        for(int i=0;i<num.size();i++)
        {
            string str;
            stringstream ss;
            ss<<num[i];
            ss>>str;
            ref.push_back(str);
        }
        sort(ref.begin(),ref.end(),cmp);
        string ret;
        for(int i=0;i<ref.size();i++)
        {
            ret+=ref[i];
        }
        return ret;
    }
};

void main()
{
	//int a[]={0,0,0,0,0,0,0,0,0,0,0,0};
	vector <int > a(100,0);
	//sort(a.begin(),a.end() );
	Solution sl;
	string ret=sl.largestNumber(a);
}