#include<bits/stdc++.h>
using namespace std;
//#define INF 2047483647
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
#define ld long double



struct Edge {
    int a, b;
    ll cost;
};

int n, m;
vector<Edge> edges;

void NegativeCycle(){
    vector<ll> d(n);
    vector<int> p(n, -1);
    int x;
    for (int i = 0; i < n; ++i) {
        x = -1;
        for (Edge e : edges) {
            if (d[e.a] + e.cost < d[e.b]) {
                d[e.b] = d[e.a] + e.cost;
                p[e.b] = e.a;
                x = e.b;
            }
        }
    }

    if (x == -1) {
        cout << "NO";
    } else {
        for (int i = 0; i < n; ++i)
            x = p[x];

        vector<int> cycle;
        for (int v = x;; v = p[v]) {
            cycle.push_back(v);
            if (v == x && cycle.size() > 1)
                break;
        }
        reverse(cycle.begin(), cycle.end());

        cout << "YES\n";
        for (int v : cycle)
            cout << v+1 << ' ';
        cout << endl;
    }
}


void solve(){
    cin>>n>>m;
    for(int i=0;i<m;i++) {
        int u,v;
        ll w;
        cin>>u>>v>>w;
        u--;v--;
        edges.push_back({u,v,w});
    }
    NegativeCycle();

}
int main(){
    FASTIO;
    solve();
    return 0;
}
