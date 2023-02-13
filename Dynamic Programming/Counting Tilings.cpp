#include<bits/stdc++.h>
#define eb emplace_back
#define ep emplace
#define pub push_back
#define pob pop_back
#define puf push_front
#define pof pop_front
#define mt make_tuple
#define fi first
#define se second
#define fastio ios::sync_with_stdio(false);cin.tie(NULL)
#define rng_23 mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define DBG(a) cerr<< "line "<<__LINE__ <<" : "<< #a <<" --> "<<(a)<<endl
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef tuple<int ,int , int > tiii;
const int INF=1e9;
const ll mod=1000000007;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());


const int N = 1024;
vector<int> adj[N];
void solve(){
    int n=10,m=1000;
    cin>>n>>m;
    int hi = 1<<n;

    for(int i=0;i<hi;i++){
        for(int j=0;j<hi;j++){
            if( (i&j) != 0 ) continue;
            int emp = 0;
            bool pos = true;
            for(int k=0;k<n;k++){
                if( ((i>>k)&1) == 0 and ((j>>k)&1) == 0 ) emp++;
                else{
                    if( emp%2 == 1 ) pos = false;
                    emp = 0;
                }
            }
            if( emp%2 == 1 ) pos = false;
            if(pos)adj[i].push_back(j);

        }

    }
    ll dp[1025] = {0};
    ll prevDp[1025] = {0};
    dp[0] = 1;
    for(int i=1;i<=m;i++){
        for(int j=0;j<hi;j++) {
            prevDp[j] = dp[j];
            dp[j] = 0;
        }
        for(int j=0;j<hi;j++){
            for(auto k:adj[j]) {
                dp[j]+=prevDp[k];
                dp[j]%=mod;
            }
        }
    }
    cout<<dp[0];
}

int main(){
    solve();
}
