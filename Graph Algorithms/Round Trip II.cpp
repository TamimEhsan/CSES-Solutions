#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define F first
#define S second
#define ll long long
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);


const int N = 100005;
vector<int> adj[N];
int color[N];
int parent[N];

void dfs(int u){
    color[u] = 1;
    for(auto v:adj[u]){
        if( color[v] == 0 ) {
            parent[v] = u;
            dfs(v);
        }else if( color[v] == 1 ){
            int curr = u;
            vector<int> path;
            path.push_back(v);

            while(curr!=v){
                path.push_back(curr);
                curr = parent[curr];
            }
            path.push_back(v);
            cout<<path.size()<<endl;
            for(int i=path.size()-1;i>=0;i--) cout<<path[i]<<" ";
            exit(0);
        }
    }
    color[u] = 2;
}

void solve(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    for(int i=1;i<=n;i++){
        if( color[i] == 0 ) dfs(i);
    }
    cout<<"IMPOSSIBLE";
}

int main(){

   // int tc;
   // cin>>tc;
   // for(int t=1;t<=tc;t++){
   //     cout<<"Case "<<t<<": ";
        solve();
  //  }

}





