#include<bits/stdc++.h>
using namespace std;
#define M 1000000007

int repeats = 0;
map<int,int> freq;

void add(int x) {
    freq[x]++;
    if (freq[x] == 2) {
        repeats++;
    }
}

void remove(int x) {
    if (freq[x] == 2) {
        repeats--;
    }
    freq[x]--;
}

void solve() {
    int n;
    cin >> n;
    int ara[n];
    for (int i = 1; i <= n; i++) {
        cin >> ara[i];
    }

    long long dp[n+1] = {0}; 
    long long cumsum[n+1] = {0}; cumsum[0] = 1;

    int left = 1;
    for(int i=1;i<=n;i++) {
        add(ara[i]);
        while (repeats > 0) {
            remove(ara[left]);
            left++;
        }
        
        dp[i] = cumsum[i-1] - (left > 1 ? cumsum[left-2] : 0);
        dp[i]%= M; dp[i] += M; dp[i] %= M;
        cumsum[i] = cumsum[i-1] + dp[i];
        cumsum[i] %= M;
    }
    
    cout << dp[n] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    solve();
    
    return 0;
}