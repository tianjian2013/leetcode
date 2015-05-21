class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int k=n-m+1;
        int ret=0;
        int mask=1;
        int up=2;
        while(up-mask&m<=k)
        {
            up<<=1;
            mask=(mask<<1)+1;
        }
        mask>>=1;
        ret=m & (!mask);
        return ret;
    }
};

void main()
{
	Solution sl;
	int ret=sl.rangeBitwiseAnd(0,0);
}