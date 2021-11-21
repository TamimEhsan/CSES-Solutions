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
#define vout(x) for(int i=0;i<x.size();i++) printf("%d ",x[i]+1);
#define pie acos(-1)
#define MOD 998244353

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int my_rand(int l, int r){return uniform_int_distribution<int>(l,r) (rng);}

int Set(int N,int pos){return N=N | (1<<pos);}
int reset(int N,int pos){return N= N & ~(1<<pos);}
bool check(int N,int pos){return (bool)(N & (1<<pos));}



vector<bool> vis;
vector<vector<int>> adj;
vector<int> childs;

int dfs(int u){
    for(auto v:adj[u]){
        if( !vis[v] ){
            vis[v] = true;
            childs[u]+=dfs(v);
        }
    }
    return childs[u]+1;
}

int main(){
    int n;
    cin>>n;
    adj.resize(n,vector<int>());
    vis.resize(n,false);
    childs.resize(n,0);

    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        a--;b--;
        adj[a].pb(b );
        adj[b].pb(a);
    }
    vis[0] = true;
    dfs(0);
    vis.clear();
    vis.resize(n,false);
    int centroid = 0;
    while(true){
        vis[centroid] = true;
        //cout<<centroid<<" ";
        bool isCentroid = true;
        for(auto v: adj[centroid]){
            if( childs[v]+1>n/2 and !vis[v] ){
                isCentroid = false;
                centroid = v;
                break;
            }
        }
        if( isCentroid){
            cout<<centroid+1;
            return 0;
        }
    }

}
