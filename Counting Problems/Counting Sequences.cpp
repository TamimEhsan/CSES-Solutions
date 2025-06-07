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

//#ifdef "LOCAL"
//#define infile freopen("input.txt","r",stdin);
#define endl '\n'

const int N = 1000006;
ll fact[N],inv[N];
ll bigmod(ll x,int pow){
    if( pow == 0 ) return 1;
    ll mul = bigmod( x,pow/2 );
    if( pow%2 == 0 ) return (mul*mul)%M;
    return ((mul*mul)%M*x)%M;
}
void calcFact(){
    fact[0] = 1;
    for(int i=1;i<N;i++){
        fact[i] = (fact[i-1]*i)%M;
    }

    inv[N-1] = bigmod(fact[N-1],M-2);
    for(int i=N-2;i>=0;i--){
        inv[i] = (inv[i+1]*(i+1))%M;
    }
}

ll NcR(int n,int r){
    if( n<r ) return 0;
    ll val = ((fact[n]*inv[r])%M*inv[n-r])%M;
    return val;
}


void solve(){
    int n,m;
    cin>>n>>m;
    ll res = 0;
    for(int i=0;i<m;i++){
        if(i%2 == 0) res = res + (bigmod(m-i,n)*NcR(m,i))%M;
        else res = res - (bigmod(m-i,n)*NcR(m,i))%M + M;
        res%=M;
    }
    cout<<res;
}

int main(){

    calcFact();
    FASTIO;
    int tc=1;
    //cin>>tc;
    for(int t=1;t<=tc;t++){
        //cout<<"Case "<<t<<": ";
        solve();
    }
}

