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
priority_queue<ll> best[N];
vector<pair<int, int>> adj[N];
priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
 
int k;
 
void dijkstra(int s) {
    
    best[s].push(0);
    pq.push({0, s});
 
    while (!pq.empty()) {
        auto [d, v] = pq.top();
        pq.pop();
        if (d > best[v].top()) continue;
 
        for (auto edge : adj[v]) {
            int to = edge.first;
            ll len = edge.second;
 
            if ( best[to].size() < k ) {
                best[to].push(d + len);
                pq.push({d + len, to});
            } else if (d + len < best[to].top()) {
                best[to].pop();
                best[to].push(d + len);
                pq.push({d + len, to});
            }
        }
    }
 
}
 
void solve() {
    int n,m;
    cin>>n>>m>>k;
   
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        adj[a].pb({b,c});
    }
    dijkstra(1);
    vector<ll> ans;
    while(!best[n].empty()){
        ans.pb(best[n].top());
        best[n].pop();
    }
    reverse(ans.begin(), ans.end());
    for(auto x : ans)
        cout << x << " ";
}
 
int main(){
    FASTIO;
    solve();
 
}