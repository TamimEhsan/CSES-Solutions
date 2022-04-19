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
vector<int>adj[N];
int vis[N];
int parent[N];

int main(){
    int n,m;
    cin>>n>>m;

    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        a--;b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    queue<int>q;

    q.push(n-1);
    vis[n-1] = 1;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(auto v:adj[u]){
            if( vis[v] == 0 ){
                vis[v] = 1;
                q.push(v);
                parent[v] = u;
            }
        }
    }
    if( vis[0] == 0 ){
        cout<<"IMPOSSIBLE";
        return 0;
    }
    int length = 0;
    int u = 0;
    while(u!=n-1){
        length++;
        u = parent[u];
    }
    cout<<length+1<<endl;
    u = 0;

    while(u!=n-1){
        cout<<u+1<<" ";
        u = parent[u];
    }
    cout<<n;
}
