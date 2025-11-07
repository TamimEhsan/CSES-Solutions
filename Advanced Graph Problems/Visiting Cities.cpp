#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
#define endl '\n'
#define INFL 9223372036854775807
#define ll long long

const int N = 100005;
vector<pii> adj[N];
vector<int> adj2[N];
long long processed[N],d[N];
int tot[N];
void dijkstra() {
    int s = 1;
    d[s] = 0; tot[s] = 1;
    set<pair<ll, ll>> q;
    q.insert({0, s});
    while (!q.empty()) {
        int v = q.begin()->second;
        q.erase(q.begin());

        for (auto edge : adj[v]) {
            int to = edge.first;
            ll len = edge.second;

            if (d[v] + len < d[to]) {
                q.erase({d[to], to});
                d[to] = d[v] + len;
                q.insert({d[to], to});
            } 
        }
    }
}

bool visited[N];
int tin[N], low[N];
int timer;
vector<int> cuts;
void dfs(int v, int p = -1) {
    visited[v] = true;
    tin[v] = low[v] = timer++;
    int children=0;
    for (int to : adj2[v]) {
        if (to == p) continue;
        if (visited[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] >= tin[v] && p!=-1)
                cuts.push_back(v);
            ++children;
        }
    }
    if(p == -1 && children > 1)
        cuts.push_back(v);
}
int n;
bool dfs2(int u) {
    if(processed[u]) return adj2[u].size() > 0;
    processed[u] = 1;
    bool isInPath = false;
    for(auto [v,w]:adj[u]) {
        if(d[u]+w != d[v]) continue;
        bool ret = dfs2(v);
        if(!ret) continue;
        adj2[u].push_back(v);
        adj2[v].push_back(u);
        isInPath = true;
    }
    return u == n || isInPath;
}

void solve() {
    int m;
    cin >> n >> m;
    for(int i=0;i<=n;i++) d[i] = INFL;
    for(int i=0;i<m;i++) {
        int u,v,w; 
        cin >> u >> v >> w;
        adj[u].push_back({v,w}); 
    }
    
    dijkstra();  
    for(int i=0;i<=n;i++) processed[i] = 0;
    dfs2(1); 
    dfs(1); cuts.push_back(1); cuts.push_back(n);
    cout<<cuts.size()<<endl;
    stable_sort(cuts.begin(),cuts.end());
    for(auto c:cuts) cout<<c<<" ";
}

int main() {
    FASTIO;
    int tc = 1;
    // cin>>tc;

    for(int i=1;i<=tc;i++) {
        solve();
    }
}