#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll,ll>
#define F first
#define S second
 
const int N = 3000;
vector<int> adj[N];
int vis[N];
int parent[N];
int minCycle(int start,int n){
    for(int i=0;i<=n;i++){
        vis[i] = 0;
        parent[i] = 0;
    }
    queue<int> q;
    q.push(start);
    vis[start] = 1;
    int mn = INT_MAX;
    while(!q.empty()){
        int u = q.front();
    //    cout<<u<<":";
        q.pop();
        for(auto v:adj[u]){
          //  cout<<v<<" ";
            if( v ==  parent[u] ) continue;
            if( vis[v]  ){
                mn = min(mn,vis[u]+vis[v]-1);
                continue;
            }
            vis[v] = vis[u]+1;
            parent[v] = u;
            q.push(v);
        }
 
    }
    return mn;
}
 
 
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
  /*  for(int i=1;i<=n;i++){
        cout<<i<<":";
        for(auto v:adj[i]) cout<<v<<" "; cout<<endl;
    }
    return 0;*/
    int mn = INT_MAX;
 
    for(int i=1;i<=n;i++){
        int ret = minCycle(i,n);
        if( ret != -1 )
            mn = min(mn,ret);
     //   cout<<i<<" "<<ret<<endl;
    }
   // cout<<endl;
    if( mn == INT_MAX ) cout<<-1;
    else cout<<mn;
}
/*
5 6
1 2
1 3
2 4
2 5
3 4
4 5
*/