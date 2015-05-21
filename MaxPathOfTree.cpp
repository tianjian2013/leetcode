#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int dfs(int p,int n,vector<vector<int> > &a,int &res){
    int l1=-1,l2=-1;
    for (int i=0;i<a[n].size();i++) {
        if (a[n][i]==p) continue;
        int l=dfs(n,a[n][i],a,res);
        if (l>l1) {l2=l1;l1=l;}
        else l2=max(l2,l);
    }
    res=max(res,l1+1+l2+1);
    return l1+1;
}

int main(){
    int N;cin>>N;
    vector<vector<int> > a(N);
    for (int i=1,p,q;i<N;i++) {
        cin>>p>>q;
        a[p-1].push_back(q-1);
        a[q-1].push_back(p-1);
    }
    int res=0;
    dfs(-1,0,a,res);
    cout<<res<<endl;
    return 0;
}