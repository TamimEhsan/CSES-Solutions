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

const int N = 1005;


int main(){
    int n,k;
    cin>>n>>k;
    long double res = 0;
    for(int i=1;i<=k;i++){
        long double temp = pow((long double)i/k,n) - pow((long double)(i-1)/k,n);
        res+=temp*i;
    }
    cout<<fixed<<setprecision(6);
    cout<<res;
}
