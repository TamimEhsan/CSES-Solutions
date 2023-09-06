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

ll dp[N][N][3];
// number of components with elements from i elements into j unordered components having k restricted borders
// eg {[1,6],[2,5,3],[7],[8,4,9]} is dp[9][4][1] cause 9 obstructs one border
// {[2,5],[4,1,3],[6]} is dp[6][3][2] cause 6 creates restrictions on two border
int main(){

    int n;
    cin>>n;
    dp[0][0][0] = 1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            // merge two components into one with i between them
            // so components become j from j+1
            dp[i][j][0] = dp[i-1][j+1][0] * (j+1) *j + //< as we have j+1 components we can merge them by (j+1)*j ways => take any two and permute them
                            dp[i-1][j+1][1] * j * j +
                            dp[i-1][j+1][2] * j * (j-1);
            dp[i][j][0]%=M;

            // append i into any of the existing component
            // so components remains same
            dp[i][j][1] = dp[i-1][j][0] * (j + j) +
                            dp[i-1][j][1] * ( j + j-1) +
                            dp[i-1][j][2] * (j-1 + j-1);
            dp[i][j][1]%=M;

            // create a new component
            // so components become j from j-1
            dp[i][j][2] = dp[i-1][j-1][0] + dp[i-1][j-1][1] + dp[i-1][j-1][2];
            dp[i][j][2]%=M;

        }
    }
    cout<<(dp[n][1][0] + dp[n][1][1] + dp[n][1][2])%M;
}
