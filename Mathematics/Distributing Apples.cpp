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

const int N=2000007;
ll fact[N],inv[N];

ll bigmod(ll x,int p){
    if( p == 0 ) return 1;
    ll mul = bigmod(x,p/2);
    mul%=M;
    if( p%2 == 0 ) return (mul*mul)%M;
    else return ((mul*mul)%M*x)%M;
}

void calcFact(){
    fact[0] = 1;
    for(ll i=1;i<N;i++){
        fact[i] = (fact[i-1]*i)%M;
    }
    inv[N-1] = bigmod(fact[N-1],M-2);
    for(ll i=N-2;i>=0;i--){
        inv[i] = (inv[i+1]*(i+1))%M;
    }
}

ll nCr(int a,int b){
    return ((fact[a]*inv[b])%M*inv[a-b])%M;
}

int main(){
    calcFact();
    int a,b;
    cin>>a>>b;
    cout<<nCr(a+b-1,a-1);
}


