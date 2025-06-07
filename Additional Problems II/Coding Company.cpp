#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 105;

const int M = 20005;
int offset = 10001;
int dp[2][N][M];
const int MOD = 1000000007;
signed main(){
    int n, x;
    cin >> n >> x;
    int ara[n+1];
    for(int i = 1; i <= n; i++){
        cin >> ara[i];
    }
    sort(ara+1,ara+n+1);

    dp[0][0][offset] = 1;
    for(int i=1;i<=n;i++){
        int cur = i&1;
        int prev = cur^1;
        for(int j=0;j<i;j++){
            for(int k=0;k<M;k++){
                dp[cur][j][k] = 0;
            }
        }
        for(int j=0;j<i;j++){
            for(int k=0;k<M;k++){

                // single element segment
                dp[cur][j][k] += dp[prev][j][k];
                dp[cur][j][k] %= MOD;

                // insert into any of the opening j segment
                dp[cur][j][k] += dp[prev][j][k]*j;
                dp[cur][j][k] %= MOD;

                // add new segment
                if( k-ara[i]>=0 ){
                    dp[cur][j+1][k-ara[i]] += dp[prev][j][k];
                    dp[cur][j+1][k-ara[i]] %= MOD;
                }



                // close any of the j segment
                if( j == 0 or k+ara[i]>=M ) continue;
                dp[cur][j-1][k+ara[i]] += dp[prev][j][k]*j;
                dp[cur][j-1][k+ara[i]] %= MOD;


            }
        }
    }
    int res = 0;
    for(int i=0;i<=x;i++){

        res+=dp[n&1][0][i+offset];
        //cout<<i<<" "<<dp[n&1][0][i+offset]<<endl;
        res%=MOD;


    }
    cout<<res<<endl;
}
