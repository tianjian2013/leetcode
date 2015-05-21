#include "globe.h"

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(denominator==0) return "0";
        string ret;
        if((numerator <0) ^ (denominator<0 ) ) ret+="-";
        long long num=abs(numerator);
        long long den=abs(denominator);
        long long k=num/ den;
        if(k==0) ret+="0.";
        else
        {
            stringstream ss;
            ss<<k;
            string str;
            ss>>str;
            ret+=str;
        }
        string xiaoshu;
        map<int,int  > yushu;
        int d=0;
        int m= num% den*10;
        while(1)
        {
            int k=m%den;
            if(yushu.count(k)) 
            {
                xiaoshu.insert(yushu[k],1,'(');
                xiaoshu.push_back(')');
                break;
            }
            else
            {
                yushu[k]=d;
                d++;
                xiaoshu.push_back('0'+m/den);
            }
            m=k% den*10;
        }
        return ret+xiaoshu;
        
    }
};

void main()
{
	Solution sl;
	cout<<sl.fractionToDecimal(2,3)<<endl;
}