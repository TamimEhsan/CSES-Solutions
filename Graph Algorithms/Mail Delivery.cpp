#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define ll long long
#define pii pair<int,int>
#define endl '\n'
#define mod 1000000007
 
const int N = 100005;
//assumes G is connected undirected simple Graph
set<int>  G[N];
vector<int> sol;
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
            G[tnode].erase(v);
            G[v].erase(tnode);
        }
    }
}
 
 
void solve(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        G[u].insert(v);
        G[v].insert(u);
    }
    for(int i=1;i<=n;i++){
        if( G[i].size()%2 ){
            cout<<"IMPOSSIBLE"<<endl;
            return ;
        }
    }
    etour(1);
    if( sol.size() != m+1 ){
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
