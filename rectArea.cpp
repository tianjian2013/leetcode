#include "help.h"

class Rect
{
  int x,y,h,w;
  public:
  
   Rect(int xx,int yy,int hh,int ww): x(xx),y(yy),h(hh),w(ww)
   {
      
   }
   Rect(): x(0),y(0),h(0),w(0)
   {
      
   }
   int area()
   {
       if(h<0||w<0) return 0;
       else return h*w;
   }
   
   friend Rect operator & ( Rect r1, Rect r2);
};

Rect operator & ( Rect r1, Rect r2)
{
    Rect ret;
    if(r1.x>r2.x) swap(r1,r2);
    ret.x=r2.x;
    ret.y=min(r1.y,r2.y);
    
    if(r2.y>r1.y)
       ret.h=min(r1.h,r2.h+r1.y-r2.y);
    else
      ret.h=min(r2.h,r1.h-r1.y+r2.y);
    
    ret.w=min(r2.w,r1.w-r2.x+r1.x);
    return ret;
}


    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        Rect r1(A,D,D-B,C-A);
        Rect r2(E,H,H-F,G-E);
        Rect ret=r1&r2;
        return r1.area()+r2.area()-ret.area();
    }


int main()
{
   cout<<computeArea(-2,-2,2,2,-2,-2,2,2);
}
