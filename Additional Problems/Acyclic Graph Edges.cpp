#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define pii pair<int,int>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

const int N = 100005;

vector<int>adj[N];
int dis[N];


void bfs(int u){
    queue<int>q;
    dis[u] = 1;
    q.push(u);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(auto v:adj[u]){
            if( dis[v] == 0 ){
                dis[v] = dis[u]+1;
                q.push(v);
            }
        }
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<pii> e;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        e.push_back({a,b});
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i=1;i<=n;i++){
        if( dis[i] == 0 ) bfs(i);
    }
    for(auto [u,v]:e){
        if( dis[u]<dis[v] or (dis[u] == dis[v] and u<v) )
            cout<<u<<" "<<v<<endl;
        else cout<<v<<" "<<u<<endl;
    }

}

