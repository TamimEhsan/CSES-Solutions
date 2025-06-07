#include<bits/stdc++.h>
using namespace std;
 
const int N = 200005;
 
int vis[N];
int nextt[N];
vector<int> prevv[N];
int res[N];
void setNext(int s){
    int sz = 1;
    int curr = s;
 
   // cout<<"cyc "<<curr<<" ";
    while(nextt[curr]!=s){
        sz++;
        curr = nextt[curr];
       // cout<<curr<<" ";
    }
   // cout<<":"<<sz<<endl;
    res[s] = sz;
 
    curr = s;
    while(nextt[curr]!=s){
        curr = nextt[curr];
        res[curr] = sz;
    }
}
 
 
 
void dfs(int u){
    vis[u] = 1;
    int v = nextt[u];
    if( vis[v] == 0 ){
        dfs(v);
    }else if( vis[v] == 1 ){
        setNext(v);
    }else if( vis[v] == 2 ){
 
    }
    vis[u] = 2;
 
}
 
int dfs2(int u){
    if( res[u]!=0 ) return res[u];
    return res[u] = dfs2(nextt[u])+1;
}
 
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int a;
        cin>>a;
        nextt[i] = a;
        prevv[a].push_back(i);
    }
    for(int i=1;i<=n;i++){
 
        if( vis[i] == 0 ){
            dfs(i);
            dfs2(i);
        }
        cout<<res[i]<<" ";
    }
 
}