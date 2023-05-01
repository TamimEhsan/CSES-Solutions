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

void solve(){
    int n;
    cin>>n;
    MCMF mcmf;
    mcmf.init(2*n+2);

    int s=0,t=2*n+1;
    int cost[n+1][n+1];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++){
            cin>>cost[i][j];
            mcmf.AddEdge(i,j+n,1,cost[i][j]);
        }
    for(int i=1;i<=n;i++){
        mcmf.AddEdge(0,i,1,0);
        mcmf.AddEdge(i+n,2*n+1,1,0);
    }

    auto [c,f] = mcmf.Mincost(s,t);
    cout<<c<<endl;
    for(auto edge:mcmf.edges){
        if( edge.flow == 1 and edge.from>=1 and edge.from<=n ) cout<<edge.from<<" "<<edge.to-n<<endl;
    }
}

int main(){
    FASTIO;
    solve();
}

// https://cses.fi/problemset/task/2121/
