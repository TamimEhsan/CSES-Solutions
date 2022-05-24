#include<bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define F first
#define S second
#define ll long long

#define M 1000000007;

int main(){
    int n;
    cin>>n;
    int sum = n*(n+1)/2;
    if( sum %2 !=0 ){
        cout<<0<<endl;
        return 0;
    }
    int target = sum/2;

    int dp[n+1][target+1];
    for(int i=0;i<=n;i++)
        for(int j=0;j<=target;j++)
            dp[i][j] = 0;
    dp[0][0] = 1;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=target;j++){
            dp[i][j] = 0;
            if( j-i>=0 )
                dp[i][j]+=dp[i-1][j-i];
            dp[i][j]+=dp[i-1][j];
            dp[i][j]%=M;
        }
    }

    cout<<dp[n][target];
}
