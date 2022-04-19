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


int main(){
    FASTIO;
    int n,up;
    cin>>n>>up;
    int ara[n];
    for(int i=0;i<n;i++) cin>>ara[i];
    ll dp[up+2]={0};
    ll dpp[up+2]={0};
    if( ara[0] == 0 ){
        for(int i=1;i<=up;i++) dp[i] = 1;
    }
    else dp[ ara[0] ] = 1;
    for(int i=1;i<n;i++){
        if( ara[i] == 0 ){
            for(int i=1;i<=up;i++) {
                dpp[i] = dp[i-1]+dp[i]+dp[i+1];
                dpp[i]%=M;
            }
        }
        else{
            dpp[ ara[i] ] = dp[ara[i]-1]+dp[ara[i]]+dp[ara[i]+1];
            dpp[ara[i]]%=M;
        }
        for(int i=0;i<=up;i++)
            dp[i] = dpp[i],dpp[i] = 0;
    }
    ll res = 0;
    for(int i=0;i<=up;i++){
        res+=dp[i];
        res%=M;
    }

    cout<<res;

}
