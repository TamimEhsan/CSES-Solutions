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


const int N = 200005;
vector<char> is_prime(N+1, true);
vector<ll> primes;
int n, l;
vector<vector<int>> adj;

int timer;
vector<int> tin, tout,height;
vector<vector<int>> up;

void dfs(int v, int p,int h = 1){
    tin[v] = ++timer;
    height[v] = h;
    up[v][0] = p;
    for (int i = 1; i <= l; ++i)
        up[v][i] = up[up[v][i-1]][i-1];

    for (int u : adj[v]) {
        if (u != p)
            dfs(u, v,h+1);
    }

    tout[v] = ++timer;
}


int getKth(int u,int k){
    if( height[u]-1<k ) return -1;
    for (int i = l; i >= 0; --i) {
        if( u == 1 and k ) return -1;
        if ( (1<<i)<k ){
             k-=(1<<i);
             u = up[u][i];
        }
    }
    return up[u][0];
}


void preprocess(int root) {
    tin.resize(n+1);
    tout.resize(n+1);
    height.resize(n+1);
    timer = 0;
    l = ceil(log2(n+1));
    up.assign(n+1, vector<int>(l + 1));
    dfs(root, root);
}

int main(){
    int q;
    cin>>n>>q;
    adj.resize(n+1,vector<int>());
    for(int i=2;i<=n;i++){
        int v;
        cin>>v;
        adj[v].pb(i);
    }
    preprocess(1);
    while(q--){
        int u,k;
        cin>>u>>k;
        cout<<getKth(u,k)<<endl;
    }
}
