#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define F first
#define S second
#define ll long long
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
#define endl '\n'

const int N = 100005;
int parent[N];
int rnk[N];
void Dsu(int n){
    for(int i=0;i<=n;i++) {
        parent[i] = i;
        rnk[i] = 0;
    }

}
int Find(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = Find(parent[v]);
}

void Union(int a, int b) {
    a = Find(a);
    b = Find(b);
    if (a != b) {
        if (rnk[a] < rnk[b])
            swap(a, b);
        parent[b] = a;
        if (rnk[a] == rnk[b])
            rnk[a]++;
    }
}

struct Edge{
    int u,v,cost;
};
bool comp(Edge a,Edge b){
    return a.cost<b.cost;
}

void solve(){
    int n,m;
    cin>>n>>m;
    vector<Edge>edges;
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        edges.push_back({a,b,c});
    }
    sort(edges.begin(),edges.end(),comp);
    Dsu(n+1);
    ll cost = 0;
    int forest = n;
    for(auto [u,v,w]:edges){
        if( Find(u)!=Find(v) ){
            cost+=w;
            Union(u,v);
            forest--;
        }
    }
    if( forest == 1 )
        cout<<cost;
    else
        cout<<"IMPOSSIBLE";

}

int main(){
    FASTIO;
    solve();
}




