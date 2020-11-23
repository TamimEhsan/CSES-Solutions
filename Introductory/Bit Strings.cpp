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

ll bigmod(ll x,int p){
    if( p == 0 ) return 1;
    ll mul = bigmod(x,p/2);
    if( p%2 == 0 ) return (mul%M*mul%M)%M;
    else return (mul%M*mul%M*x)%M;
}

int main(){
    int t = 1;
    //scanf("%d",&t);
    for(int tc=1;tc<=t;tc++){
        int n;
        cin>>n;
        cout<<bigmod(2,n);
    }
}

