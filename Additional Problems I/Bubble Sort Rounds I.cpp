#include<bits/stdc++.h>
using namespace std;
 
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
#define endl '\n'
 

 
void solve() {
 
    int n;
    cin >> n;
    pair<int,int> ara[n];
    for(int i=0;i<n;i++) {
        cin>>ara[i].first;
        ara[i].second = i;
    }
    sort(ara, ara+n);
    int mx = 0;
    for(int i=0;i<n;i++) {
        mx = max(mx, ara[i].second - i);
    }
    cout<<mx;
}

int main(){
    FASTIO;
 
    solve();
}
