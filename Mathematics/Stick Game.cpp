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


int main(){
    int n,k;
    cin>>n>>k;
    int ara[k];
    for(int i=0;i<k;i++) cin>>ara[i];
    int dp[n+1]={0};
    for(int i=0;i<=n;i++){
        if( dp[i] == 0 ){
            for(int j=0;j<k;j++){
                if( i+ara[j]<=n ) dp[ i+ara[j] ] = 1;
            }
        }
    }
    for(int i=1;i<=n;i++){
        if( dp[i] ) cout<<'W';
        else cout<<'L';
    }
}


