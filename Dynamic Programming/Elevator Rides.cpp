#include<bits/stdc++.h>
using namespace std;
 
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
#define endl '\n'

const int MAXN = (1<<20)+5;

pair<int,int> dp[MAXN];

void solve() {
    int n, w;
    cin >> n >> w;
    int ara[n];
    for(int i = 0; i < n; i++) {
        cin >> ara[i];
    }
    dp[0] = {1, 0}; // dp[mask] = {number of rides, current weight}
    for(int i=0;i<(1<<n);i++) {
        for(int j=0;j<n;j++) {
            if( !(i & (1<<j))) {
                int nextIndex = i ^ (1<<j);
                pair<int,int> nextVal = {dp[i].first, dp[i].second + ara[j]};
                if(nextVal.second > w) {
                    nextVal.first++;
                    nextVal.second = ara[j];
                }
                if(dp[nextIndex].first == 0 && dp[nextIndex].second == 0) {
                    dp[nextIndex] = nextVal;
                } 
                dp[nextIndex] = min(dp[nextIndex], nextVal);
            }
        }
    }
    cout << dp[(1<<n)-1].first << endl;
}

int main() {
    FASTIO;

    solve();
    
    return 0;
}