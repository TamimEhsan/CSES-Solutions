#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define ll long long
#define pii pair<int,int>
#define endl '\n'
#define mod 1000000007
 
/**
https://cses.fi/problemset/task/1691/
Euler Circuit/Tour::
A path that starts and ends in the same vertex (fixed given)
and traverses each edges exactly once
*/
 
const int N = 100005;
//assumes G is connected undirected simple Graph
set<int>  G[N];
vector<int> sol;
int indeg[N];
int outdeg[N];
void etour(int node)
{
    stack<int> dStack;
    dStack.push(node);
    while(!dStack.empty())
    {
        int tnode=dStack.top();
        if(G[tnode].empty())
        {
            sol.push_back(tnode);
            dStack.pop();
        }
        else{
            int v=*G[tnode].begin();
            dStack.push(v);
            G[tnode].erase(G[tnode].begin());
            //G[v].erase(G[v].find(tnode));
        }
    }
    reverse(sol.begin(),sol.end());
}
 
 
void solve(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        G[u].insert(v);
       // G[v].insert(u);
        outdeg[u]++;
        indeg[v]++;
    }
    for(int i=2;i<n;i++){
        if( indeg[i]!=outdeg[i]){ // each intermediate vertex must have even degrees
            cout<<"IMPOSSIBLE"<<endl;
            return ;
        }
    }
    if( outdeg[1]-indeg[1] != 1 or indeg[n]-outdeg[n] != 1  ){ // start and end must have odd degrees
            cout<<"IMPOSSIBLE"<<endl;
            return ;
    }
    etour(1);
    if( sol.size() != m+1 ){ // checking if all edges are covered
        cout<<"IMPOSSIBLE"<<endl;
        return ;
    }
    for(auto e:sol) cout<<e<<" ";
}
 
int main(){
 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int tc=1;
    //cin>>tc;
 
    for(int i=0;i<tc;i++){
        solve();
    }
}
