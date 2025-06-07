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

const int N = 100005;

ll HP(ll n,ll N){
    ll sum = 0;

    for (int i = 1; i <= N; i++) {
        sum += min(( n / i),N);
    }


    return sum;
}

int main(){

    ll n;
    cin>>n;
    ll target = n*n/2+1;
    ll res = -1,l=1,r=n*n;
    cout<<endl;
    while(l<=r){
        ll mid = (l+r)/2;
        ll ret = HP(mid,n);
        //cout<<mid<<" "<<ret<<endl;
        if( ret>=target ){
            res = mid;
            r = mid-1;
        }else l = mid+1;
    }
    cout<<res;
}

// https://cses.fi/problemset/task/2076/
