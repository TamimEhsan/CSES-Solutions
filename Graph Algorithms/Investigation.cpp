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
ll d[N],number[N],mnFlight[N],mxFlight[N];
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
                number[to] = number[v];
                mnFlight[to] = mnFlight[v]+1;
                mxFlight[to] = mxFlight[v]+1;
            }else if( d[v]+len == d[to] ){
                number[to] += number[v];
                number[to] %= M;
                mnFlight[to] = min(mnFlight[to],mnFlight[v]+1);
                mxFlight[to] = max(mxFlight[to],mxFlight[v]+1);
            }
        }
    }
}
int main(){
    FASTIO;
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++) d[i] = INFL;
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        a--;b--;
        adj[a].pb({b,c});
    }
    number[0] = 1;
    dijkstra(0);
    cout<<d[n-1]<<" "<<number[n-1]<<" "<<mnFlight[n-1]<<" "<<mxFlight[n-1];

}
