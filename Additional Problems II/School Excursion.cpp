#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
#define endl '\n'

const int N = 100006;
bitset<N> bullshit;

vector<int> adj[N];
int vis[N];
int sz;
void dfs(int u){
    vis[u] = 1;
    sz++;
    for(auto v:adj[u]){
        if( !vis[v] ) dfs(v);
    }
}


int main(){
    FASTIO;
    int n,m;
    cin>>n>>m;

    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    bullshit[0] = 1;
    for(int i=1;i<=n;i++){

        if( vis[i] ) continue;
        sz = 0;
        dfs(i);
        bullshit |= bullshit<<sz;
    }
    for(int i=1;i<=n;i++) cout<<bullshit[i];
}

