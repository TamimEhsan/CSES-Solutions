#include<bits/stdc++.h>
using namespace std;
#define INF 2047483647
#define INFL 9223372036854775807
#define ll long long
#define pii pair<int,int>
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define ull unsigned long long
#define M 1000000007
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
#define take(x) scanf("%d",&x)
#define DE(x) printf("\ndebug %d\n",x);
#define vout(x) for(int i=0;i<x.size();i++) printf("%d ",x[i]);
#define pie acos(-1)
#define MOD 998244353

const int N = 5e4+5;
bitset<N> bset[N];
int parent[N];
vector<int> adj_rev[N], adj[N];
vector<bool> used;
vector<int> order, component;

void dfs1(int v) {

    used[v] = true;
    for (auto u : adj_rev[v])
        if (!used[u])
            dfs1(u);
    order.push_back(v);
}

void dfs2(int v,int p) {

    parent[v] = p;
    used[v] = true;
    for (auto u : adj[v])
        if (!used[u])
            dfs2(u,p);
}

void dfs3(int u) {
    used[u] = true;
    for (auto v : adj[u])
        if (!used[v])
            dfs3(v);
    order.push_back(u);
}
void dfs4(int u){
    used[u] = true;
    bset[u].set(u);
    for(auto v:adj[u]){
        if( !used[v] )
            dfs4(v);
        bset[u] |=bset[v];
    }
}
int main() {
    int n,m,q;
    cin>>n>>m>>q;
    vector<pii> edges;
    for (int i=0;i<m;i++) {
        int a, b;
        cin>>a>>b;
        a--;b--;
        edges.push_back({a,b});
        adj[a].push_back(b);
        adj_rev[b].push_back(a);
    }

    used.assign(n, false);

    for (int i = 0; i < n; i++)
        if (!used[i])
            dfs1(i);

    used.assign(n, false);
    reverse(order.begin(), order.end());

    for (auto v : order)
        if (!used[v]) {
            dfs2 (v,v);
        }
    map<pii,int> taken;
    for(int i=0;i<n;i++) adj[i].clear();

    for(auto [u,v]:edges){
        if( parent[u] == parent[v] ) continue;
        u = parent[u];
        v = parent[v];
        if( taken[{u,v}] ) continue;
        taken[{u,v}] = 1;
        adj[u].push_back(v);
    }
    used.assign(n, false);
    order.clear();
    for(int i=0;i<n;i++){
        int u = parent[i];
        if( !used[u] )
            dfs3(u);
    }
    used.assign(n, false);
    for(auto u:order){
        if( !used[u] )
            dfs4(u);
    }
    for(int i=0;i<q;i++){
        int u,v;
        cin>>u>>v;
        u--;v--;
        u = parent[u];
        v = parent[v];
        if( bset[u][v] ) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}
