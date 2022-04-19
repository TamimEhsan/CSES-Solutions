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


const int N = 1e5+5;
ll processed[N],d[N];
vector<pii>adj[N];

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

int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++) d[i] = INFL;
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        a--;b--;
        adj[a].pb({b,c});
        //adj[b].pb({a,c});
    }
    dijkstra(0);
    for(int i=0;i<n;i++){
        cout<<d[i]<<" ";
    }

}
