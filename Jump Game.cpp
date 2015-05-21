#include "globe.h"


/**************************1***************************
class Solution {
public:
   
    bool canJump(int A[], int n) {
      int max=0;
      for(int i=0;i<n;i++)
      {
		  if(i<=max)
		  {
		    if(i+A[i]>max )
		    {
			  max=i+A[i];
		    }
		  }
		  else
		  {
			  return false;
		  }
	  }
	  return true;
    }
};
/**************************1***************************/

/**************************1***************************
class Solution {
public:
    int jump(int A[], int n) {
        vector <int > c(n,0);
        c[0]=0;
        vector <int > index;
        index.push_back(0);
        for(int i=1;i<n;i++)
        {
            vector <int >::iterator iter=index.begin();
            int min=-1;
            //iter++;
            while(iter!=index.end())
            {
                if(  A[*iter]<i-(*iter)  )
                {
                    iter=index.erase(iter);
                    continue;
                }
                if(c[*iter]<min||min<0)
                {
                    min=c[*iter];
                }
				iter++;
            }
            c[i]=min+1;
            index.push_back(i);
        }
        return c[n-1];
    }
};
/**************************1***************************/

class Solution {
public:
    int jump(int A[], int n) {
        if(n<2)
        {
            return 0;
        }
		int cost=1,far=A[0],newfar=A[0];
		for(int i=1;i<n;i++)
        {
			if(i>far)
			{
				++cost;
				far=newfar;
			}
			if(newfar<i+A[i])
			{
				newfar=i+A[i];
			}
		}
       return cost;
    }
};
void main()
{
	int A[] = {2,3,1,1,4};
	 Solution sl;
	int res=sl.jump(A,5);
	 waitKey();
}