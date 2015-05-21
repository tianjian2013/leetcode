#include "globe.h"

class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int > num1,num2;
        int i=0,j=0;
        int k1=0,k2=0;
        while(i<version1.size() )
        {
            if(version1[i]=='.' )
            {
                num1.push_back(k1);
                k1=0;
            }
            else
            {
                k1*=10;
                k1+=(int)(version1[i]-'0');
            }
            i++;
        }
         num1.push_back(k1);

        while(j<version2.size() )
        {
            if(version2[j]=='.' )
            {
                num2.push_back(k2);
                k2=0;
            }
            else
            {
                k2*=10;
                k2+=(int)(version2[j]-'0');
            }
            j++;
        }
		 num2.push_back(k2);

       int add=num1.size()-num2.size();
        if(add>0) 
        {
            for(int i=0;i<add;i++)  num2.push_back(0);
        }
        else
        {
            for(int i=0;i<-add;i++)  num1.push_back(0);
        }
        
        int m=0;
        for(m=0;m<num1.size();m++)
        {
            if(num1[m]>num2[m]) return 1;
            if(num1[m]<num2[m]) return -1;
        }
        return 0;
        
    }
};

void main()
{
	string s1("1");
	string s12("0");
	Solution sl;
	int ret=sl.compareVersion(s1,s12);
	cout<<ret;
}