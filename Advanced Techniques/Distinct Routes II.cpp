/**
Max flow min cost
if we want k flow min cost, just add a dummy node with source with a edge with capacity k and cost 0

If we want to find which edge contributed what amount, we can check the flow variable in edge,
thus can reconstruct the flow graph too U w U
*/

#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

typedef long long T1;//for cost
typedef long long T2;//for flow
const int maxn = 5005;
const T1 INF = 1e12;
const T2 inf = 1e12;
const T1 eps = 0;
struct Edge {
    int from, to;
    T2 cap, flow;
    T1 cost;
};
struct MCMF {//0-indexed
    int n, m, s, t;
    vector<Edge> edges;
    vector<int> G[maxn];
    int p[maxn],inq[maxn];
    T1 d[maxn];
    T2 a[maxn];
    void init(int n) {
        this->n = n;
        for(int i = 0; i < n; i++) G[i].clear();
        edges.clear();
    }
    void AddEdge(int from,int to,T2 cap,T1 cost) {
        edges.push_back((Edge){from, to, cap, 0, cost});
        edges.push_back((Edge){to, from, 0, 0, -cost});
        m = edges.size();
        G[from].push_back(m-2);
        G[to].push_back(m-1);
    }

    pair<T1,T2> Mincost(int s,int t) {//SPFA
        T1 tot_cost = 0;
        T2 tot_flow = 0;
        while(true) {
            for(int i = 0; i < n; i++) d[i] = INF;
            memset(inq, 0, sizeof(inq));
            d[s] = 0;
            inq[s] = 1;
            p[s] = 0;
            a[s] = inf;
            queue<int> Q;
            srand(time(NULL));
            Q.push(s);
            while(!Q.empty()) {
                int u = Q.front();
                Q.pop();
                inq[u] = 0;
                for(int i = 0; i < G[u].size(); i++) {
                    Edge& e = edges[G[u][i]];
                    if(e.cap > e.flow && d[e.to] > d[u] + e.cost+eps) {
                        d[e.to] = d[u] + e.cost;
                        p[e.to] = G[u][i];
                        a[e.to] = min(a[u], e.cap - e.flow);
                        if(!inq[e.to]) {
                            Q.push(e.to);
                            inq[e.to] = 1;
                        }
                    }
                }
            }
            if(abs(d[t]-INF)<=eps)break;
            tot_cost += (T1)d[t] * a[t];
            tot_flow += a[t];
            int u = t;
            while(u != s) {
                edges[p[u]].flow += a[t];
                edges[p[u]^1].flow -= a[t];
                u = edges[p[u]].from;
            }
        }

        return {tot_cost,tot_flow};
    }
};

vector<int> adj[maxn];
vector<int> path;
void dfs(int s){
    path.push_back(s);
    if( adj[s].size() ){
        dfs( adj[s].back() );
        adj[s].pop_back();
    }

}
void solve(){
    int n,m,k;
    cin>>n>>m>>k;
    MCMF mcmf;
    mcmf.init(n+2);

    int s=0,t=n;

    for(int i=1;i<=m;i++){
        int from,to;
        cin>>from>>to;
        mcmf.AddEdge(from,to,1,1);

    }
    mcmf.AddEdge(0,1,k,0);

    auto [c,f] = mcmf.Mincost(s,t);
    if( f <k ){
        cout<<-1<<endl;
        return;
    }
    cout<<c<<endl;
    for(auto edge:mcmf.edges){
        if( edge.from == 0 or edge.flow == 0 or edge.cap == 0 ) continue;
        adj[edge.from].push_back(edge.to);
    }


    for(auto v:adj[1]){
        path.clear();
        path.push_back(1);
        dfs(v);
        cout<<path.size()<<endl;
        for(auto p:path) cout<<p<<" ";
        cout<<endl;
    }

}

int main(){
   // FASTIO;
    solve();

}

// https://cses.fi/problemset/task/2121/
