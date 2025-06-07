#include<bits/stdc++.h>
using namespace std;
#define INF 2047483647
#define INFL 9223372036854775807
#define ll long long
//#define int long long
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
#define endl '\n'




const int N = 2000005;
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
    ll dp[m+1];
    pii para[m+1];
    for(int i=0;i<m;i++){
        cin>>para[i].first>>para[i].second;
    }
    para[m] = {n,n};
    sort(para,para+m);
    for(int i=0;i<=m;i++){
        dp[i] = NcR(para[i].first+para[i].second-2,para[i].first-1);
        for(int j=0;j<i;j++){
            if( para[j].first<=para[i].first and para[j].second<=para[i].second ){
                int dx = para[i].first-para[j].first+1;
                int dy = para[i].second-para[j].second+1;
                ll temp = 1LL*dp[j] * NcR(dx+dy-2,dx-1);
                dp[i] = (dp[i]-temp%M+M)%M;
            }
        }
        ;
    }
    cout<<dp[m];
}


int main(){
    calcFact();
    FASTIO;
    int tc=1;
    //cin>>tc;
    while(tc--)
    solve();

}
