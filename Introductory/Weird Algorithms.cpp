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
#define vout(x) for(int i=0;i<x.size();i++) cout<<x[i]<<" ";
#define pie acos(-1)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main(){
    int t = 1;
    //cin>>t;
    while(t--){
        ll n;
        cin>>n;
        while(n>1){
            printf("%lld ",n);
            if( n%2 == 0 ) n/=2;
            else n = n*3+1;
        }
        cout<<1;
    }
}
