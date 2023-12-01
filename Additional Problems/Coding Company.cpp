#include<bits/stdc++.h>
using namespace std;


void solve(){
    int n,k;
    cin>>n>>k;
    int ara[n];
    for(int i=0;i<n;i++) cin>>ara[i];
    if( k>1 ) {
        cout<<"YES"<<endl;
        return;
    }
    bool sorted = true;
    for(int i=1;i<n;i++) if( ara[i]<ara[i-1] ) sorted = false;
    if( sorted ) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

signed main(){
    int tc;
    cin>>tc;
    while(tc--) solve();
}
