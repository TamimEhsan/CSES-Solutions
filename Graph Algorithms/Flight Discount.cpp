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
#define ld long double

const int N = 1e5+5;
ll d[N],dr[N];
vector<pair<int,ll>>adj[N],rev[N];

void dijkstra(int s) {
    d[s] = 0;
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

void dijkstra2(int s) {
    dr[s] = 0;
    set<pair<ll, ll>> q;
    q.insert({0, s});
    while (!q.empty()) {
        int v = q.begin()->second;
        q.erase(q.begin());

        for (auto edge : rev[v]) {
            int to = edge.first;
            ll len = edge.second;

            if (dr[v] + len < dr[to]) {
                q.erase({dr[to], to});
                dr[to] = dr[v] + len;
                q.insert({dr[to], to});
            }
        }
    }
}

int main(){
   // ifstream cin("test_input1.txt");
    //ofstream cout("test_output.txt");
    FASTIO;
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
        d[i] = dr[i] = INFL;
    for(int i=0;i<m;i++){
        int a,b;
        ll c;
        cin>>a>>b>>c;
        a--;b--;
        adj[a].push_back({b,c});
        rev[b].push_back({a,c});
    }
    dijkstra(0);
    dijkstra2(n-1);
    ll mn = INFL;
    for(int u=0;u<n;u++){
        if( d[u] == INFL ) continue;
        for(auto [v,c]:adj[u]){
            if( dr[v] == INFL ) continue;
            mn = min(mn,d[u]+c/2+dr[v]);

        }
    }
    cout<<mn;

}

