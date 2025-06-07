#include<bits/stdc++.h>
using namespace std;
#define INF 2047483647
#define INFL 9223372036854775807
#define ll long long
#define pii pair<ll,ll>
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

const int N = 100005;
int n; // number of nodes
vector<int> adj[N]; // adjacency list of graph

bool visited[N];
int tin[N], low[N];
int timer;

vector<pii> bridges;
int cnt;
void dfs(int v, int p = -1) {
    visited[v] = true;
    tin[v] = low[v] = timer++;
    for (int to : adj[v]) {
        if (to == p) continue;
        if (visited[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] > tin[v]){
                //IS_BRIDGE(v, to);
                bridges.pb({v+1,to+1});
               // cout<<"bridge "<<v<<" "<<to<<endl;
            }
        }
    }
}

set<int> parent[N];
void dfs2(int u){
    visited[u] = true;
    for(auto v:adj[u]){
        if( parent[u].count(v)!=0 or parent[v].count(u)!=0 ) continue;
        cout<<u<<" "<<v<<endl;
        parent[v].insert(u);
        if( visited[v] ) continue;

        dfs2(v);
    }
}

void find_bridges() {
    timer = 0;
    for(int i=0;i<=n;i++){
        visited[i] = false;
        tin[i] = low[i] = -1;
    }
    for (int i = 1; i <= n; ++i) {
        if (!visited[i]){
            cnt++;
            dfs(i);
        }
    }
}

int main(){
    int m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    find_bridges();
    if( bridges.size() or cnt>1 ){
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }
    for(int i=0;i<=n;i++){
        visited[i] = false;
    }
    dfs2(1);

}

// https://cses.fi/problemset/task/2076/
