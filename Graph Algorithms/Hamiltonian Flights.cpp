#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define ll long long
#define pii pair<int,int>
#define endl '\n'
#define mod 1000000007
 
 
int Set(int N,int pos){return N=N | (1<<pos);}
int reset(int N,int pos){return N= N & ~(1<<pos);}
bool check(int N,int pos){return (bool)(N & (1<<pos));}
int popCount(int x){ return __builtin_popcount(x); }
 
/**
 
*/
 
const int N = 22;
const int M = (1<<N)+5;
ll dp[M][N];
 
int adj[N][N];
 
 
void solve(){
 
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        u--;v--;
        adj[u][v] += 1;
    }
 
    int up = (1<<(n-1));
    dp[ Set(0,0) ][0] = 1;
    for(int mask=0;mask<up;mask++){
        for(int i=0;i<n-1;i++){
            if( check(mask,i) ) continue;
            for(int j=0;j<n-1;j++){
                if( adj[j][i] == 0 ) continue;
                if( !check(mask,j) ) continue;
                dp[ Set(mask,i) ][i] += (dp[mask][j]*adj[j][i])%mod;
                dp[ Set(mask,i) ][i] %= mod;
            }
        }
    }
    ll res = 0;
    for(int i=0;i<n-1;i++){
        int up = (1<<n)-1;
        up = reset(up,n-1);
        res += dp[up][i]*adj[i][n-1];
        res%=mod;
    }
    cout<<res;
}
 
int main(){
 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int tc=1;
    //cin>>tc;
 
    for(int i=0;i<tc;i++){
        solve();
    }
}
