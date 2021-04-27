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

ll dp[64][6][6];

void fillDP(){
    int n=2;
    for(int n=1;n<65;n++){
        for(int i = 0;i<6;i++){
            for(int j=0;j<6;j++){
                for(int k=0;k<6;k++){
                    dp[n][i][j]=(dp[n][i][j]+(dp[n-1][i][k]*dp[n-1][k][j])%M)%M;
                }
            }
        }
    }
   /* for(int i = 0;i<6;i++){
        for(int j=0;j<6;j++){
            cout<<dp[60][i][j]<<" ";
        }
        cout<<endl;
    }*/
}
int solve(ll p){
    int og[] = {1,1,2,4,8,16};
    if( p<6 ) return og[p];
    p-=5;
    ll res[6][6],temp[6][6];
    for(int i=0;i<6;i++) for(int j=0;j<6;j++){
        if( i == j ) res[i][j] = 1;
        else res[i][j] = 0;
    }
    int pos = 0;
    while(p){
        if( p%2 ){
            for(int i=0;i<6;i++) for(int j=0;j<6;j++) temp[i][j] = 0;
            for(int i = 0;i<6;i++){
                for(int j=0;j<6;j++){
                    for(int k=0;k<6;k++){
                        temp[i][j]=(temp[i][j]+(res[i][k]*dp[pos][k][j])%M)%M;
                    }
                }
            }
            for(int i=0;i<6;i++) for(int j=0;j<6;j++) res[i][j]=temp[i][j];
        }
        p/=2;
        pos++;
    }

    ll ans = 0;
    for(int i=0;i<6;i++){
        ans = (ans%M+ res[0][i]*og[5-i]%M)%M;
    }
    return ans;
}
int main(){
    ll temp[6][6]={
        {1,1,1,1,1,1},
        {1,0,0,0,0,0},
        {0,1,0,0,0,0},
        {0,0,1,0,0,0},
        {0,0,0,1,0,0},
        {0,0,0,0,1,0}
    };
    for(int i=0;i<6;i++) for(int j=0;j<6;j++) dp[0][i][j]=temp[i][j];
    fillDP();
    ll n = 8;
    cin>>n;
    cout<<solve(n)<<endl;
}

