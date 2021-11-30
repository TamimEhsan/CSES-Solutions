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
int disa[maxn],disb[maxn];

int mxDis = 0;
int Left,Right;
void dfs(int u,int height){
    disa[u] = height;
     if( height>mxDis ) {
        mxDis = height;
        Left = u;
    }
    for(auto v:adj[u]){
        if( disa[v] == 0 )
            dfs(v,height+1);
    }
}

void dfs2(int u,int height){
    disa[u] = height;
    if( height>mxDis ) {
        mxDis = height;
        Right = u;
    }
    for(auto v:adj[u]){
        if( disa[v] == 0 )
            dfs2(v,height+1);
    }
}

void dfs3(int u,int height){
    disb[u] = height;
    for(auto v:adj[u]){
        if( disb[v] == 0 )
            dfs3(v,height+1);
    }
}

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;

        adj[a].pb(b);
        adj[b].pb(a);
    }
    dfs(1,1); mxDis = 0; fill(disa,disa+n+1,0);
    dfs2(Left,1);
    dfs3(Right,1);
    //DE(Left); DE(Right)
    for(int i=1;i<=n;i++){
        cout<<max(disa[i],disb[i])-1<<" ";
    }

}
