#include "globe.h"
#include <limits>
void main()
{
	int isum=1;
    int n=8,m=58,k;
	//n=m/2;

	for(k=1;k<=n;k++)
    {
      isum=(isum*(m-n+k))/k;//����˷����������㣨m-n+k��/k�������������
    }
	cout<<isum<<endl;

	isum=1;
	for(k=1;k<=30;k++)
    {
		//isum*=k;
		//cout<<k<<"  :  "<<isum<<endl;
	}
	waitKey();
}