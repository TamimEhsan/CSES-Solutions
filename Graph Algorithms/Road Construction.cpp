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
int sz[N];
void Dsu(int n){
    for(int i=0;i<=n;i++) {
        parent[i] = i;
        rnk[i] = 0;
        sz[i] = 1;
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
        sz[a]+=sz[b];
        if (rnk[a] == rnk[b])
            rnk[a]++;
    }
}


void solve(){
    int n,m;
    cin>>n>>m;
    Dsu(n+1);
    int mxSize = 1;
    int forest = n;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        if( Find(u)!=Find(v) ){
            Union(u,v);
            mxSize = max({mxSize,sz[Find(u)],sz[Find(v)]});
            forest--;
        }
        cout<<forest<<" "<<mxSize<<endl;
    }

}

int main(){
    FASTIO;
    solve();
}




