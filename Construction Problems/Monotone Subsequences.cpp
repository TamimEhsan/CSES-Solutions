#include<bits/stdc++.h>
using namespace std;
 
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
#define endl '\n'

void solve() {
    int n, x;
    cin>>n>>x;
    int slots = (n+x-1)/x;
    if (slots > x) {
        cout<<"IMPOSSIBLE\n";
        return;
    }
 
    for(int i=1;i<=slots;i++) {
        int st = min(n,i*x);
        int en = (i-1)*x+1;
        for(int j=st;j>=en;j--) cout<<j<<" ";
    }
    cout<<"\n";
    
}
 
signed main() {
    FASTIO;
    int tc;
    cin>>tc;
 
    for(int i=1;i<=tc;i++) {
        solve();
    }
}