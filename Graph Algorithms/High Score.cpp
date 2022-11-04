#include<bits/stdc++.h>
using namespace std;

//#define INFL 9223372036854775807
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

const int N = 2505;
const ll INFL = 9223372036854775807;
vector<int> adj[N];
int reachable[N];
struct edge{
    int a, b;
    ll cost;
};

int n, m, source;
vector<edge> e;

ll BellmanFord()
{
    vector<ll> d (n+1, INFL);
    d[source] = 0;
    vector<int> p (n+1, - 1);
    ll x;
    for (int i=0; i<n; ++i)
    {
        x = -1;
        for (int j=0; j<m; ++j)
            if (d[e[j].a] < INFL)
                if (d[e[j].b] > d[e[j].a] + e[j].cost){
                    d[e[j].b] = max (-INFL, d[e[j].a] + e[j].cost);
                    p[e[j].b] = e[j].a;
                    if( reachable[e[j].b] == 1 ) x = e[j].b;
                }
    }
    if (x == -1 and d[n] != INFL){
        return -d[n];
    }else{
        return -1;
    }
}

void dfs(int u){
    reachable[u] = 1;
    for(auto v:adj[u])
        if( !reachable[v] )
            dfs(v);
}
void solve(){
    cin>>n>>m;
    source = 1;
    for(int i=0;i<m;i++){
        ll u,v,x;
        cin>>u>>v>>x;
        e.push_back({u,v,-x});
        adj[v].push_back(u);
    }
    dfs(n);
    cout<<BellmanFord();
}
int main(){
    FASTIO;
    int tc=1;
    //cin>>tc;
    //cout<<fixed<<setprecision(8);
    for(int t=1;t<=tc;t++){
      //  cout<<"Case "<<t<<": ";
        solve();

    }
}
