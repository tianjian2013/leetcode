#include "globe.h"

class Solution {
public:
    string convert(string s, int nRows) {
        string res;
        for(int i=0;i<nRows;i++)
        {
           string thisrow;
           bool down=true;
           int k=i;
           while( k<s.size() )
           {
               thisrow+=s[k];
               if(i==0||nRows-1)
               {
                   k+=2*nRows-2;   
               }
               else
               {
                if(down)  k+=2*(nRows-1-i);
                else k+=2*i;
                 down=!down;
               }
               
           }
           res+=thisrow;
           
        }
        return res;
    }
};

void main()
{
Solution sl;
string res=sl.convert("PAYPALISHIRING",3);
waitKey();
}
