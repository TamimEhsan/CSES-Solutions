#include<bits/stdc++.h>
using namespace std;
#define INF 2147483647
#define INFL 9223372036854775807
#define pii pair<int,int>
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define ll long long
#define ull unsigned long long
#define M 1000000007
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
#define take(x) scanf("%d",&x)
#define DE(x) printf("\ndebug %d\n",x);
#define vout(x) for(int i=0;i<x.size();i++) printf("%d ",x[i]);
#define pie acos(-1)
#define MOD 998244353

ll bigmod(ll x,ll p,ll m){
    if( p == 0 ) return 1;
    ll mul = bigmod(x,(ll)p/2,m);
   // cout<<mul<<" ";
    if( p%2 == 0 ) return (ll)(mul%m*mul%m)%m;
    else return (ll)((mul%m*mul%m)%m*x%m)%m;
}

int main(){
    int tc;
    cin>>tc;
    while(tc--){
        ll a,b,c;
        cin>>a>>b>>c;
        ll pow = bigmod(b,c,M-1);
        cout<<bigmod(a,pow,M)<<endl;
    }
}
/*
A ^ (B ^ C) % M
=> y = (B ^ C) % (M - 1)
=> Ans = (A ^ y) % M
*/
