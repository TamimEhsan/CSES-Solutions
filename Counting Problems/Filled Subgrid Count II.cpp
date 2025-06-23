#include<bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
#define endl '\n'
 
const int N = 3005;
string grid[N];
int dp[N][N];
long long result[30];
void solve() {
    
    int n,m;
    cin >> n >> m;
    for(int i=0;i<n;i++) 
        cin >> grid[i];
    for(int i=1;i<=n;i++) {
        vector<pair<int,int>> monotone;
        long long rects = 0;
        for(int j=1;j<=n;j++){
            dp[i][j] = 1;
            if( i > 1 and grid[i-1][j-1] == grid[i-2][j-1] ) 
                dp[i][j] += dp[i-1][j];
            
            if ( j > 1 and grid[i-1][j-1] != grid[i-1][j-2] ) {
                monotone.clear();
                rects = 0;
            }
            int cnt = 1;
            while(monotone.size() and monotone.back().first >= dp[i][j] ){
                cnt += monotone.back().second;
                rects -= 1LL * monotone.back().first * monotone.back().second;
                monotone.pop_back();
            }
            monotone.push_back({dp[i][j],cnt});
            rects += 1LL * dp[i][j] * cnt;
            result[grid[i-1][j-1]-'A'] += rects;
        }
    }
    for(int i=0;i<m;i++) cout<< result[i]<<endl;
}
 
int main(){
    FASTIO;
    solve();
 
}