#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int my_rand(int l, int r) {
    return uniform_int_distribution<int>(l,r) (rng);
}


// p[u] = parent of u in centroid tree
// d[x][u] = distance from u to a parent of u at level x of centroid tree
//           if u is in subtree of centroid c, then d[lvl[c]][u] = dist(c, l)
// Taken from Rezwan Arefin
// If (x, y) edge exist, then x must be in adj[y] and y must be in adj[x]
const int maxn = 2e5 + 10;
vector<int> adj[maxn];
int lvl[maxn], sub[maxn], p[maxn], vis[maxn];

// lvl is the level of a vertex in the decomposed tree
// sub is the size of sub graph rooted at that vertex
// p is the parent of the vertex in centroid tree
// vis is the visited check


int cnt[maxn];
ll ans = 0;
int k1,k2;
int mxHeight = 0;

struct FenwickTree {
    vector<int> bit;  // binary indexed tree
    int n;

    FenwickTree(int n) {
        this->n = n;
        bit.assign(n, 0);
    }

    FenwickTree(vector<int> a) : FenwickTree(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }

    int sum(int r) {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
    void update(int idx,int val){
        int prevVal = sum(idx,idx);
        int delta = val - prevVal;
        add(idx,delta);
    }
};

FenwickTree ft(maxn);

void dfs(int u,int par,bool filling,int height = 1){
    if( height>k2 ) return;
    mxHeight = max(height,mxHeight);
    if( !filling )
        ans+=ft.sum( max(k1-height,0), k2-height );
    else
        ft.add(height,1);


    for(auto v:adj[u])
        if( v!=par and !vis[v] )
            dfs(v,u,filling,height+1);
}

// calculates the sub graph size
void calc(int u, int par) {
    sub[u] = 1;
    for(int v : adj[u])
        if(v!=par && !vis[v])
            calc(v, u), sub[u] += sub[v];
}

// finds the centroid of a subgraph
int centroid(int u, int par, int r) {
    for(int v : adj[u])
        if(v!=par && !vis[v])
            if(sub[v] > r)
                return centroid(v, u, r);
    return u;
}

void decompose(int u, int par) {
    calc(u, -1);
    int c = centroid(u, -1, sub[u] >> 1);
    vis[c] = 1, p[c] = par, lvl[c] = 0;

    if(par!=-1)
        lvl[c] = lvl[par] + 1;
    mxHeight = 0;
    for(auto v:adj[c]){
        if( v!=par and !vis[v] ){
            dfs(v,c,false);
            dfs(v,c,true);
        }
    }
    for(int i=1;i<=mxHeight;i++)
        ft.update(i,0);

    for(int v : adj[c])
        if(v!=par && !vis[v])
            decompose(v, c);
}

int main(){


    FASTIO;
    int n;
    cin>>n>>k1>>k2;
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        a--;b--;
        adj[a].push_back(b);
        adj[b].push_back(a);

    }
    ft.add(0,1); //< the root node for all subtree has distance 0
    decompose(0,-1);
    cout<<ans;
}

// https://cses.fi/problemset/result/3140100/
