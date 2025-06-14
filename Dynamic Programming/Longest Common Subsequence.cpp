#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    vector<int> ara(n + 1), bara(m + 1);
    for (int i = 1; i <= n; i++) {
        cin >> ara[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> bara[i];
    }

    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            if( ara[i] == bara[j] ) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    cout << dp[n][m] << endl;

    std::function<void(int, int)> printLCS = [&](int i, int j) {
        if (i == 0 || j == 0) return;
        if (ara[i] == bara[j]) {
            printLCS(i - 1, j - 1);
            cout << ara[i] << " ";
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            printLCS(i - 1, j);
        } else {
            printLCS(i, j - 1);
        }
    };
    printLCS(n, m);

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();

    return 0;
}