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

//#ifdef "LOCAL"
//#define infile freopen("input.txt","r",stdin);
#define endl '\n'

#define Max 1000000
#define sz(u) u.size()

struct DominatorTree {
    vector <int> g[Max], tree[Max],bucket[Max],rg[Max];
    int sdom[Max],dom[Max],label[Max],arr[Max],rev[Max],T;
    int papa[Max]; //store u's dominator in papa[u]
    int n,m,par[Max],dsu[Max];
    int Find(int u,int x=0) {
        if(u == dsu[u])return x ? -1 : u;
        int v = Find(dsu[u],x+1);
        if(v<0)return u;
        if(sdom[label[dsu[u]]]<sdom[label[u]])
            label[u] = label[ dsu[u] ];
        dsu[u] = v;
        return x ? v : label[u];
    }
    void Union(int u,int v) {dsu[v] = u;}
    void dfs0(int u) {
        ++T;
        rev[T]=u;
        arr[u]=sdom[T]=label[T]=dsu[T]=T;
        for(int i = 0; i < sz(g[u]); i++) {
            int w = g[u][i];
            if(!arr[w])dfs0(w),par[arr[w]]=arr[u];
            rg[arr[w]].pb(arr[u]);
        }
    }
    void dominator_tree_init() {
        dfs0(1);
        for(int i = T; i >= 1; i--) {
            for(int j = 0; j<sz(rg[i]); j++)
                sdom[i] = min(sdom[i],sdom[ Find(rg[i][j]) ]);
            if(i > 1)bucket[ sdom[i] ].pb(i);
            for(int j = 0; j < sz(bucket[i]); j++) {
                int w = bucket[i][j];
                int v = Find(w);
                if( sdom[w] == sdom[v] )dom[w] = sdom[w];
                else dom[w] = v;
            }
            if(i > 1)Union(par[i],i);
        }
        for(int i = 2; i <= T; i++) {
            if(dom[i] != sdom[i])dom[i] = dom[ dom[i] ];
            tree[ rev[ dom[i] ] ].pb(rev[i]);
            papa[rev[i]]=rev[dom[i]];
            //here rev[dom[i]] dominates rev[i]
        }
    }
    void Clear() {
        for(int i = 1; i <= n; i++) {
            arr[i] =  sdom[i] = dom[i] = par[i] = dsu[i] = label[i] = rev[i] = 0;
            tree[i].clear();
            g[i].clear();
            rg[i].clear();
            bucket[i].clear();
        }
        T=0;
    }
} dtree;
//dree.g[u].pb(v)&then call dominator_tree_init()

int main(){


    FASTIO;
    int tc=1;
    //cin>>tc;
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        dtree.g[u].pb(v);
    }
    dtree.dominator_tree_init();

    vector<int> doms;
    int curr = n;
    while(curr!=1){
        doms.push_back(curr);
        curr = dtree.papa[curr];
    }
    doms.push_back(1);
    cout<<doms.size()<<endl;
    sort(doms.begin(),doms.end());
    for(auto dom:doms) cout<<dom<<" ";
}

// https://cses.fi/problemset/task/1703/
