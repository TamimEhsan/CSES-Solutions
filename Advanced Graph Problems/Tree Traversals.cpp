#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define ll long long
#define F first
#define S second

vector<int> res;
void post(int n,int in[],int pre[],int pos[],int il,int ir,int pl,int pr){
    if( il > ir ){
        return;
    }
    int p = pos[ in[il] ];
    int len1 = p-pl;
    int len2 = pr-p;
    res.push_back(in[il]);
    post(n,in,pre,pos,il+len1+1,ir,p+1,pr);
    post(n,in,pre,pos,il+1,il+len1,pl,p-1);

}

int main(){
    int n;
    cin>>n;
    int in[n],pre[n],pos[n+2];
    for(int i=0;i<n;i++) cin>>in[i];
    for(int i=0;i<n;i++) {
        cin>>pre[i];
        pos[ pre[i] ] = i;
    }
    post(n,in,pre,pos,0,n-1,0,n-1);
    for(int i=n-1;i>=0;i--) cout<<res[i]<<" ";
}
