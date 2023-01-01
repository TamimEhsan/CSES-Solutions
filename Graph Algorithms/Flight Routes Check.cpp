#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define F first
#define S second
#define ll long long
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
#define endl '\n'

const int N = 100005;
vector<int> adj_rev[N], adj[N];
int used[N];
vector<int> order,component;

void dfs1(int v) {
    used[v] = true;
    for (auto u : adj_rev[v])
        if (!used[u])
            dfs1(u);
    order.push_back(v);
}

void dfs2(int v) {
    used[v] = true;
    //component.push_back(v);
    for (auto u : adj[v])
        if (!used[u])
            dfs2(u);
}


void solve(){
    int n,m;
    cin>>n>>m;

    for (int i=0;i<m;i++) {
        int a, b;
        cin>>a>>b;
        a--;b--;
        adj[a].push_back(b);
        adj_rev[b].push_back(a);
    }


    for (int i = 0; i < n; i++)
        if (!used[i])
            dfs1(i);

    for(int i=0;i<=n;i++) used[i] = 0;
    reverse(order.begin(), order.end());
    vector<int> firsts;
    for (auto v : order)
        if (!used[v]) {
            dfs2 (v);
            firsts.push_back(v);
        }
    if( firsts.size()==1 ) cout<<"YES";
    else cout<<"NO\n"<<firsts[0]+1<<" "<<firsts[1]+1;

}

int main(){
    FASTIO;
    solve();
}




