#include<bits/stdc++.h>
using namespace std;
#define INF 2047483647
#define INFL 9223372036854775807
#define ll long long
#define pii pair<int,int>
#define pII pair<ll,ll>
#define vi vector<int>
#define vii vector<pii>
#define vI vector<ll>
#define VII vector<pII>
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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int my_rand(int l, int r){return uniform_int_distribution<int>(l,r) (rng);}

int Set(int N,int pos){return N=N | (1<<pos);}
int reset(int N,int pos){return N= N & ~(1<<pos);}
bool check(int N,int pos){return (bool)(N & (1<<pos));}

const int maxn = 2e5+5;
vector<int> adj[maxn];
ll sub[maxn],path[maxn],res[maxn];
int n;
void dfs(int u,int par){
    sub[u] = 1;
    for(auto v:adj[u]){
        if(v!=par){
            dfs(v,u);
            sub[u]+=sub[v];
            path[u]+=path[v] + sub[v];
        }
    }
}


void dfs2(int u,int par){
    if( u!=1 ){
        path[u] = path[par] + n - 2*sub[u];
    }
    for(auto v:adj[u]){
        if( v!=par ){
            dfs2(v,u);
        }
    }
}

int main(){
    cin>>n;
    for(int i=1;i<n;i++){
        int a,b;
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    dfs(1,-1);
    dfs2(1,-1);
    for(int i=1;i<=n;i++) cout<<path[i]<<" ";
}
