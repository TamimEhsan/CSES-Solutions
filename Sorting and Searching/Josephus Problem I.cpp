#include<bits/stdc++.h>
using namespace std;
//#define INF 2147483647
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

// Complexity : O(min(k log(n), m))
// People 1 to n in a circle, counting starts from 1, every k'th
// people dies, returns the position of the m'th killed people
ll Josephus(ll n, ll k, ll m){
    m = n - m;
    if (k <= 1) return n - m;
    ll i = m;
    while (i < n){
        ll r = (i - m + k - 2) / (k - 1);
        if ((i + r) > n) r = n - i;
        else if (!r) r = 1;
        i += r;
        m = (m + (r * k)) % i;
    }
    return m + 1;
}

int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cout<<Josephus(n,2,i)<<" ";
    }
}


