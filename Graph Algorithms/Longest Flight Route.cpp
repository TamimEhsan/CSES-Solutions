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
#define ld long double


const int N = 100005;
vector<int>adj[N];
int vis[N],parent[N],dis[N];
vector<int> top;
void dfs(int u){
    vis[u] = 1;
    for(auto v:adj[u])
        if( !vis[v] )
            dfs(v);
    top.push_back(u);
}
int main(){
   // ifstream cin("test_input1.txt");
    //ofstream cout("test_output.txt");
    FASTIO;
    int n,m;
    cin>>n>>m;

    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        a--;b--;
        adj[a].push_back(b);
    }

    dfs(0);
    if( vis[n-1]  == 0 ){
        cout<<"IMPOSSIBLE";
        return 0;
    }
    reverse(top.begin(),top.end());
    for(auto u:top){
        for(auto v:adj[u]){
            if( dis[v]<dis[u]+1 ){
                dis[v] = dis[u]+1;
                parent[v] = u;
            }
        }
    }
    vector<int>path;
    path.push_back(n-1);
    int curr = n-1;

    while(curr!=0){
        curr = parent[curr];
        path.push_back(curr);
    }
    reverse(path.begin(),path.end());
    cout<<path.size()<<endl;
    for(auto p:path) cout<<p+1<<" ";
}

