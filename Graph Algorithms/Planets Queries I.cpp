#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define F first
#define S second
#define ll long long
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
#define endl ' '

const int N = 200005;
int to[N];
int vis[N];
int parent[N];
int lifting[N][32];

int get(int u,int dis){
    if( lifting[u][dis]!=0 ) return lifting[u][dis];
    if( dis == 0 ) return lifting[u][dis] = to[u];
    else return lifting[u][dis] = get( get(u,dis-1),dis-1 );
}
void solve(){
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        int v;
        cin>>v;
        to[i] = v;
    }
    while(q--){
        int u,dis;
        cin>>u>>dis;
        int mul = 0;
        while(dis){
            if( dis%2 ){
                u = get(u,mul);
            }
            mul++;;
            dis/=2;
        }
        cout<<u<<endl;
    }
}

int main(){
    FASTIO;
    solve();
}





