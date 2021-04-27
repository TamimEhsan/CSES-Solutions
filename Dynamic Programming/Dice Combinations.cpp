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

ll dp[1000006];
int main(){
    int n;
    cin>>n;
    dp[1] = dp[0] = 1;
    for(int i=2;i<=n;i++){
        dp[i] = (2*dp[i-1])%M;
        if( i-7>=0 ) dp[i]=(dp[i]-dp[i-7]+M)%M;
        //cout<<dp[i]<<" ";
    }
    cout<<dp[n];
}

