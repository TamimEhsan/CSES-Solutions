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


const int N = 1e5+5;
vector<int> adj[N];
int vis[N];
vector<int> topsort;
void dfs(int u){
    vis[u] = 1;
    for(auto v:adj[u]){
        if( vis[v] == 0 )
            dfs(v);
        else if( vis[v] == 1 ){
            cout<<"IMPOSSIBLE";
            exit(0);
        }
    }
    vis[u] = 2;
    topsort.pb(u+1);
}

int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        u--;v--;
        adj[u].pb(v);
    }
    for(int i=0;i<n;i++)
        if( vis[i] == 0 )
            dfs(i);
    reverse(topsort.begin(),topsort.end());
    vout(topsort);
}
