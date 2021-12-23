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
    int n,m;
    cin>>n>>m;
    int recs[n+1][m+1];
    for(int i =1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if( i == j  ){
                recs[i][j] = 0;
                continue;
            }
            recs[i][j] = n*m;
            for(int k=1;k<i;k++){
                recs[i][j] = min( recs[k][j] + recs[i-k][j] + 1, recs[i][j]);
            }
            for(int k=1;k<j;k++){
                recs[i][j] = min( recs[i][k] + recs[i][j-k] + 1, recs[i][j]);
            }
        }
    }
    cout<<recs[n][m];
}




