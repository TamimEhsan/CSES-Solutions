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
    int n,a,b;
    cin>>n>>a>>b;

    long double dp[n+1][6*n+1]={0};
    for(int i=0;i<=n;i++) for(int j=0;j<=6*n;j++) dp[i][j] = 0;
    dp[0][0] = 1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=6*n;j++){
            for(int k=1;k<=6;k++){
                if( j-k>=0 ) dp[i][j] += dp[i-1][j-k];
            }
        }
    }
    long double tot = 0;
    for(int i=0;i<=6*n;i++) tot+=dp[n][i];
    long double res = 0;
    for(int i=a;i<=b;i++) res+=dp[n][i];
    cout<<fixed<<setprecision(6)<<(long double)res/tot;
}

