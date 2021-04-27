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

int main(){
    ll n;
    cin>>n;
    ll sum = 0;
    for(ll i = 1;i*i<=n;i++){
        ll up = n/i;
        up%=M;
        ll down = n/(i+1)+1;
        down%=M;
        ll temp = ((up+down)%M*(up-down+1+M)%M)%M;
        temp = ((temp*500000004)%M*i)%M;
        if( up != i ) temp = (temp + (up%M*i)%M)%M;
        sum = (sum+temp)%M;
    }
    cout<<sum;
}

