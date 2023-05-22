#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define ll long long
#define F first
#define S second

const int N = 100005;
vector<int> adj[N];
vector<int> leaves;

void dfs(int u,int p){

    if( adj[u].size() == 1 ) leaves.push_back(u);
    for(auto v:adj[u]) {
        if( v== p ) continue;
        dfs(v,u);
    }
}

int main(){
    int n;
    cin>>n;
    int edges[n+1] = {0};
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1,0);
    cout<<(leaves.size()+1)/2<<endl;
    int sz = leaves.size();
    for(int i=0;i<sz/2;i++){
        cout<<leaves[i]<<" "<<leaves[i+sz/2]<<endl;
    }
    if( leaves.size()%2 == 1 ) cout<<leaves.back()<<" "<<leaves[0];
}

// https://cses.fi/problemset/task/1704/
// idea:: https://atcoder.jp/contests/arc160/editorial/6387
