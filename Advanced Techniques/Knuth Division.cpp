#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define ll long long
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
#define endl '\n'
 
const int N = 5005;
ll dp[N][N];
int opt[N][N];
ll ara[N];
ll cumsum[N];
ll recurse(int l,int r){
    if( l>r ) return -1;
    if( l == r ) return dp[l][r] = 0;
    if( dp[l][r] != -1 ) return dp[l][r];
 
    for(int k=l+1;k<=r;k++){
        ll a = dp[l][k-1],b=dp[k][r];
        if( a == -1 ) a = recurse(l,k-1);
        if( b == -1 ) b = recurse(k,r);
        if( dp[l][r] == -1 ) dp[l][r] = a + b + cumsum[r] - cumsum[l-1];
        else dp[l][r] = min(dp[l][r], a + b + cumsum[r] - cumsum[l-1]);
    }
    return dp[l][r] ;
}
 
 
 
 
int main(){
    FASTIO;
 
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>ara[i];
        cumsum[i] = ara[i]+cumsum[i-1];
    }
    for(int i=0;i<=n;i++) for(int j=0;j<=n;j++) dp[i][j] = -1;
 
 
    auto C = [&](int i, int j) {
        return cumsum[j]-cumsum[i-1];
    };
 
    for (int i = 0; i < N; i++) {
        opt[i][i] = i;
        dp[i][i] = 0;
    }
 
    for (int i = n-1; i > 0; i--) {
        for (int j = i+1; j <= n; j++) {
            ll mn = LONG_MAX;
            ll cost = C(i, j);
            for (int k = opt[i][j-1]; k <= min(j-1, opt[i+1][j]); k++) {
                if (mn >= dp[i][k] + dp[k+1][j] + cost) {
                    opt[i][j] = k;
                    mn = dp[i][k] + dp[k+1][j] + cost;
                }
            }
            dp[i][j] = mn;
        }
    }
 
 
    cout<<dp[1][n];
 
 
}