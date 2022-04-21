#include<bits/stdc++.h>
using namespace std;
#define INF 2047483647
#define INFL 9223372036854775807
#define ll long long
#define pii pair<ll,ll>
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


const int N = 1e3+5;
ll d[N][N];

void floyd_warshal(int n){
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}

int main(){
    int n,m,q;
    cin>>n>>m>>q;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++){
            if( i == j ) continue;
            d[i][j] = 223372036854775807;
        }
    }
    for(int i=0;i<m;i++){
        ll a,b,c;
        cin>>a>>b>>c;
        a--;b--;
        d[a][b] = min(d[a][b],c);
        d[b][a] = min(d[b][a],c);
    }
    floyd_warshal(n);
    while(q--){
        int u,v;
        cin>>u>>v;
        u--;v--;
        if( d[u][v] == 223372036854775807 )
            cout<<-1<<endl;
        else cout<<d[u][v]<<endl;
    }

}
