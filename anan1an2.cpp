#include <iostream>

using namespace std;

const unsigned long long NUM=19999997;

struct two2two
{
    public :
    two2two()
    {
        x0=1;
        x1=1;
        x2=1;
        x3=1;
    }
    unsigned long long x0,x1,x2,x3;
};

two2two pn(two2two input,unsigned long long n)
{
    //input.x0%=NUM;
    //input.x1%=NUM;
    //input.x2%=NUM;
    //input.x3%=NUM;
    two2two ret;
    if(n<=0) return ret;
    if(n==1) return input;
    ret=pn(input,n/2);
    
    two2two ret1;
    ret1.x0=(ret.x0*ret.x0+ret.x1*ret.x2)%NUM;
    ret1.x1=(ret.x0*ret.x1+ret.x1*ret.x3)%NUM;
    ret1.x2=(ret.x0*ret.x2+ret.x3*ret.x2)%NUM;
    ret1.x3=(ret.x2*ret.x1+ret.x3*ret.x3)%NUM;
    
    
    if(n%2)
    {
      two2two ret2;
      ret2.x0=(ret1.x1)%NUM;
      ret2.x1=(ret1.x0+ret1.x1)%NUM;
      ret2.x2=(ret1.x3)%NUM;
      ret2.x3=(ret1.x2+ret1.x3)%NUM;
      return ret2;
    }
    return ret1;
}


int  main()
{
    unsigned long long n;
    cin>>n;

	for(int i=2;i<n;i++)
	{
    two2two xxx;
    xxx.x0=0;
    xxx=pn(xxx,i-1);
    unsigned long long ret=xxx.x3;
    cout<< ret%19999997<<endl;
	}
    return 0;
}
