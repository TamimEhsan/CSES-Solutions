#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll,ll>
const int N = 5005;
ll ara[N];
ll dp[2][N][N];
bool calculated[N][N];
ll maxScore = 0;
void calc(int player,int start,int end){
    if( calculated[start][end] ) return ;
   // cout<<player<<" "<<start<<" "<<end<<endl;
    if( start == end ) {
        calculated[start][end] = true;
        dp[player][start][end] = ara[start];
        dp[1-player][start][end] = 0;
        return ;
    }
    calc(1-player,start+1,end);
    calc(1-player,start,end-1);
 
    if( ara[start]+dp[player][start+1][end]>ara[end]+dp[player][start][end-1]  ){
        dp[player][start][end] = dp[player][start+1][end]+ara[start];
        dp[1-player][start][end] = dp[1-player][start+1][end];
    }else{
        dp[player][start][end] = dp[player][start][end-1]+ara[end];
        dp[1-player][start][end] = dp[1-player][start][end-1];
    }
 
 
    calculated[start][end] = true;
   
}
 
 
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++) cin>>ara[i];
    calc(0,0,n-1);
    cout<<dp[0][0][n-1];
 
}
 