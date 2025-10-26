#include<bits/stdc++.h>
using namespace std;
 
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
#define endl '\n'
 
void solve() {
    int n, x, y;
    cin>>n>>x>>y;
    if (x == 0 and y == 0) {
        cout<<"YES\n";
        for(int i=0;i<n;i++) cout<<i+1<<" "; cout<<"\n";
        for(int i=0;i<n;i++) cout<<i+1<<" "; cout<<"\n";
        return;
    } 
    if (x == 0 or y == 0 or x+y > n){
        cout<<"NO\n";
        return;
    }
    cout<<"YES\n";
    int offset = n-x-y;
    for(int i=0;i<n;i++) cout<<i+1<<" "; 
    cout<<"\n";
    
    for(int i=0;i<offset;i++) cout<<i+1<<" ";
    for(int i=offset+x;i<n;i++) cout<<i+1<<" ";
    for(int i=offset;i<offset+x;i++) cout<<i+1<<" ";
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
