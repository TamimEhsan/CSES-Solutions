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


//<<<<<<<<<<<<<<<<<<<<<<<Lowest Common Ancestor Template>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\\


//<<<<<<<<<<<<<<<<<<<<<<<Sparse Table Template>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\\

template <class T>
class STable {
    int n;
    pair<int,int> *cal;
    vector<T> *SparseTable;
    T (*comp)(T,T);
    void initialize() {
        int i,j;
        cal[1].second=1;
        for(i=1,j=1<<i; j<=n; i++,j=1<<i) {
            cal[j].first=1;
            cal[j].second=j;
        }
        for(i=2; i<=n; i++) {
            cal[i].first=cal[i].first+cal[i-1].first;
            if(cal[i].second==0) cal[i].second=cal[i-1].second;
        }
    }
public:
    STable() {

    }
    STable(vector<T> &arr,T (*f)(T,T)) {
        n=arr.size();
        comp=f;
        cal=new pair<int,int>[n+1];
        initialize();
        SparseTable=new vector<T>[n];
        int i,j,m;
        for(i=0,j=0; i<n; i++) {
            SparseTable[i].push_back(arr[i]);
        }
        for(j=0,m=1<<j; m<n; j++,m=1<<j) {
            for(i=0; i+m<n; i++) {
                SparseTable[i].push_back(comp(SparseTable[i][j],SparseTable[i+m][SparseTable[i+m].size()-1]));
            }
        }
    }
    void inits(vector<T> &arr,T (*f)(T,T)) {
        n=arr.size();
        comp=f;
        cal=new pair<int,int>[n+1];
        initialize();
        SparseTable=new vector<T>[n];
        int i,j,m;
        for(i=0,j=0; i<n; i++) {
            SparseTable[i].push_back(arr[i]);
        }
        for(j=0,m=1<<j; m<n; j++,m=1<<j) {
            for(i=0; i+m<n; i++) {
                SparseTable[i].push_back(comp(SparseTable[i][j],SparseTable[i+m][SparseTable[i+m].size()-1]));
            }
        }
    };
    T query(int l,int r) {
        int difference=(r-l+1);
        return comp(SparseTable[l][cal[difference].first],SparseTable[r-cal[difference].second+1][cal[difference].first]);
    }
    ~STable() {
        int i;
        for(i=0; i<n; i++) {
            SparseTable[i].clear();
        }
        delete []SparseTable;
        delete []cal;
        comp=0;
    }
};
pii minimum(pii a,pii b) {
    return min(a,b);
}

//<<<<<<<<<<<<<<<<<<<<<<<Sparse Table Template Ended>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\\


class LCA {

public:


    vector<vector<int>> adj;
    vector<int> first,dis; // first position of a node
    vector< pii > euler; // .F = height; .S = node
    unordered_map<int,int>vis;
    STable<pair<int,int> > stableLca;

    LCA() {
        adj.clear();
        first.clear();
        dis.clear();
        euler.clear();
        vis.clear();
    }
    LCA(int n) {
        init(n);
    }
    void init(int n) {
        adj.clear();
        first.clear();
        dis.clear();
        euler.clear();
        vis.clear();
        adj.resize(n,vector<int>());
        first.resize(n,0);
        dis.resize(n,0);
    }
    void createLCA() {
        dfs(0);
        stableLca.inits(euler,minimum);
    }
    void dfs(int u,int height = 0) {
        first[u] = euler.size();
        vis[u] = 1;
        dis[u] = height;
        euler.pb(mp(height,u));
        for(int v:adj[u]) {
            if( !vis[v] ) {
                dfs(v,height+1);
                euler.pb(mp(height,u));
            }
        }
    }

    int findLca(int x,int y) {
        int lca = stableLca.query( min( first[x], first[y]), max( first[x],first[y]) ).S;
        return lca;
    }

    int findDistance(int u,int v) {
        int l = findLca(u,v);
        return dis[u] + dis[v] - 2*dis[l];
    }

    bool isAncestor(int u,int v) {
        return findLca(u,v) == u;
    }
};

//<<<<<<<<<<<<<<<<<<<<<<<Lowest Common Ancestor Template Ended>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\\

int main() {
    int n,q;
    scanf("%d %d",&n,&q);
    LCA lca(n);
    for(int i=1; i<n; i++) {
        int a,b;
        scanf("%d %d",&a,&b);
        a--,b--;
        lca.adj[a].pb(b);
        lca.adj[b].pb(a);
    }
    lca.createLCA();

    while(q--) {
        int a,b;
        scanf("%d %d",&a,&b);
        a--;b--;
        printf("%d\n",lca.findDistance(a,b));
    }
}

