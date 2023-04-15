#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>


const int N = 200005;

vector<int> adj[N], adj_rev[N],adj_scc[N];
vector<bool> used;
vector<int> order, condensedOrder, component, root_nodes;
int sz[N];
ll res[N];
int roots[N];

ll coins[N];

void dfs1(int v) {
    used[v] = true;
    for (auto u : adj[v])
        if (!used[u])
            dfs1(u);
    order.push_back(v);
}

void dfs2(int v) {
    used[v] = true;
    component.push_back(v);
    for (auto u : adj_rev[v])
        if (!used[u])
            dfs2(u);
}



void solve(){

    int n,m;
    cin>>n>>m;
    used.assign(n,false);
    for(int i=0;i<n;i++) cin>>coins[i];
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        a--;
        b--;
        adj[a].push_back(b);
        adj_rev[b].push_back(a);

    }
    for (int i = 0; i < n; i++)
        if (!used[i])
            dfs1(i);
    used.assign(n, false);
    reverse(order.begin(), order.end());

    for (auto v : order){
        if (!used[v]) {
            dfs2 (v);
            int root = component.front();
            for (auto u : component) roots[u] = root;
            root_nodes.push_back(root);
            sz[root] = component.size();
            component.clear();
        }
    }

    for (int v = 0; v < n; v++){
        for (auto u : adj[v]) {
            int root_v = roots[v],
                root_u = roots[u];

            if (root_u != root_v)
                adj_scc[root_v].push_back(root_u);
        }
    }


    // topsort of the condensed graph
    for(auto ord:order)
        if( roots[ord] == ord ) condensedOrder.push_back(ord);
    reverse(condensedOrder.begin(),condensedOrder.end());
    // deleting multiple edges
    for(auto root:root_nodes){
        if( adj_scc[root].size()>=2 )
            sort(adj_scc[root].begin(),adj_scc[root].end());
        vector<int> nodes;
        if( adj_scc[root].size() ) nodes.push_back( adj_scc[root][0] );
        for(int i=1;i<adj_scc[root].size();i++){
            if( adj_scc[root][i]!=adj_scc[root][i-1] ){
                nodes.push_back(adj_scc[root][i]);
            }
        }
        adj_scc[root] = nodes;
    }
    for(int i=0;i<n;i++) {
        if( roots[i] == i ) continue;
        coins[ roots[i] ]+=coins[i];
    }
    ll mx = 0;
    for(auto ord:condensedOrder) {
        for(int i=0;i<adj_scc[ord].size();i++){
            res[ord]=max(res[ord],res[ adj_scc[ord][i] ]);
        }
        res[ord]+=coins[ord];
        mx = max(mx, res[ord] );
    }


    cout<<mx<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc=1;
    //cin>>tc;

    for(int i=0;i<tc;i++){
        solve();
    }
}

