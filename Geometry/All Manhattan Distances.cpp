#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

void print_int128(__int128 x) {
    if (x == 0) {
        cout << 0;
        return;
    }
    if (x < 0) {
        cout << '-';
        x = -x;
    }
    string res;
    while (x > 0) {
        res += (x % 10) + '0';
        x /= 10;
    }
    reverse(res.begin(), res.end());
    cout << res;
}

void solve() {
    int n;
    cin >> n;
    
    long long x[n], y[n];
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
    }
    
    __int128 total_distance = 0;
    
    sort(x, x + n);
    sort(y, y + n);
    long long cum_sum = 0;
    for (int i = 0; i < n; ++i) {
        total_distance +=  x[i] * i - cum_sum;
        cum_sum += x[i];
    }
    cum_sum = 0;
    for (int i = 0; i < n; ++i) {
        total_distance += y[i] * i - cum_sum;
        cum_sum += y[i];
    }
    
    print_int128(total_distance);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}