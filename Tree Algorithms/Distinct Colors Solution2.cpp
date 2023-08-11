#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#pragma GCC optimize("O3,unroll-loops")
#define INF 2047483647
#define INFL 9223372036854775807
#define ll long long
#define pii pair<int,int>
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define ull unsigned long long
//#define M 1000000007
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
#define take(x) scanf("%d",&x)
#define DE(x) printf("\ndebug %d\n",x);
#define vout(x) for(int i=0;i<x.size();i++) printf("%d ",x[i]);
#define pie acos(-1)
#define MOD 998244353
#define infl 10000000000
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int my_rand(int l, int r){return uniform_int_distribution<int>(l,r) (rng);}

const int N = 200005;

vector<int> adj[N];
int sack[N];
set<int> subcolor[N] ;
int color[N];
int res[N];

void dfs(int u,int p){
    int mxChild = -1;
    for(auto v:adj[u]){
        if( v == p ) continue;
        dfs(v,u);
        if( mxChild == -1 ) mxChild = v;
        else if( subcolor[ sack[v] ].size() > subcolor[ sack[mxChild] ].size() ) mxChild = v;


    }
    if( mxChild != -1 ){
        sack[u] = sack[mxChild];
        for(auto v:adj[u]) {
            if( v != p and v!=mxChild ){
                for(auto s:subcolor[sack[v]]) subcolor[sack[mxChild]].insert(s);
            }
        }

    }
    subcolor[ sack[u] ].insert(color[u]);
    res[u] = subcolor[ sack[u] ].size();
}


int main(){
    FASTIO;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>color[i];

        sack[i] = i;
    }
    for(int i=1;i<n;i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(1,0);
    for(int i=1;i<=n;i++) cout<<res[i]<<" ";
}
