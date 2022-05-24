#include<bits/stdc++.h>
using namespace std;
#define INF 2047483647
#define INFL 9223372036854775807
#define ll long long
#define pii pair<int,int>
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
int parent[N];
vector<int> adj_rev[N], adj[N];
int used[N];
vector<int> order;

void dfs1(int v) {
    used[v] = true;
    for (auto u : adj_rev[v])
        if (!used[u])
            dfs1(u);
    order.push_back(v);
}

void dfs2(int v,int p) {
    used[v] = true;
    parent [v] = p;
    for (auto u : adj[v])
        if (!used[u])
            dfs2(u,p);
}

int main() {
    int n,m;
    cin>>n>>m;

    for (int i=0;i<m;i++) {
        int a, b;
        cin>>a>>b;
        a--;b--;
        adj[a].push_back(b);
        adj_rev[b].push_back(a);
    }

    fill(used,used+n,false);

    for (int i = 0; i < n; i++)
        if (!used[i])
            dfs1(i);

    fill(used,used+n,false);
    reverse(order.begin(), order.end());

    int label[n];
    int cnt = 0;
    for (auto v : order)
        if (!used[v]) {
            label[v] = ++cnt;
            dfs2 (v,v);
        }
    cout<<cnt<<endl;
    for(int i=0;i<n;i++)
        cout<< label[ parent[i] ]<<" ";

}
