class Solution {
public:
    bool isPalindrome(int x) {
     //if(x<0)
     //{
      //  x=-x;
     //}
     int start=x>0?x:-x;
     int com=0;
     while(x)
     {
         //x=x%10;
         com*=10;
         com+=x%10;
         x=x/10;
     }
     if(start==com)
      return true;
     else
      return false;
    
        
    }
};