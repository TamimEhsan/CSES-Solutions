#include<bits/stdc++.h>
using namespace std;
#define INF 2047483647
#define INFL 9223372036854775807
#define ll long long int
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


int Set(int N,int pos){return N=N | (1<<pos);}
int reset(int N,int pos){return N= N & ~(1<<pos);}
bool check(int N,int pos){return (bool)(N & (1<<pos));}

long long bigmod(long long a, long long b, long long m=M) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = (res * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return res;
}


int main(){
    ll n;
    cin>>n;
    ll res = 0;
    ll cnt = 0;
    for(int i=n-1;i>0;i-=2)
        cnt+=i;
    if( n%2 == 1 )
        cnt++;
    res+=bigmod(2,n*n);res%=M;
    if( n%2 == 0 )
        res+=bigmod(2,n/2*n);
    else
        res+=bigmod(2,(n/2)*n + (n+1)/2);
    res%=M;
    res+=bigmod(2,cnt);res%=M;
    res+=bigmod(2,cnt);res%=M;
    res = res*250000002; res%=M;
    cout<<res;


}

