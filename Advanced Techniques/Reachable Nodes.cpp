#include<bits/stdc++.h>
using namespace std;
#define INF 2147483647
#define INFL 9223372036854775807
#define pii pair<int,int>
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define ll long long
#define ull unsigned long long
#define M 1000000007
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
#define take(x) scanf("%d",&x)
#define DE(x) printf("\ndebug %d\n",x);
#define vout(x) for(int i=0;i<x.size();i++) printf("%d ",x[i]);
#define pie acos(-1)
#define MOD 998244353

const int N = 50007;
bitset<N> bset[N];
vector<int> adj[N];
int reach[N];
vector<int> topsort;
map<int,int> vis;
void dfs(int u){
    vis[u] = 1;
    for(auto v:adj[u]){
        if( !vis[v] )
            dfs(v);
    }
    topsort.push_back(u);
}
void dfs2(int u){
    vis[u] = 1;
    bset[u].set(u);
    for(auto v:adj[u]){
        if( !vis[v] )
            dfs2(v);
        bset[u] |= bset[v];
    }
}
int main(){
    FASTIO;
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        a--;b--;
        adj[a].push_back(b);
    }
    for(int i=0;i<n;i++)
        if( !vis[i] ) dfs(i);

    vis.clear();
    for(auto u:topsort){
        if( !vis[u] )
            dfs2(u);
    }
    for(int i=0;i<n;i++)
        cout<<bset[i].count()<<" ";
}
