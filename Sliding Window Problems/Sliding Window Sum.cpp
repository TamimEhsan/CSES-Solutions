#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

long long val;

void add(int v) {
    val += v;
}
void remove(int v) {
    val -= v;
}

void solve() {
    int n, k;
    cin >> n >> k;
    int x, a, b, c;
    cin >> x >> a >> b >> c;

    auto next = [&](int v) {
        return (1LL * a * v + b) % c;
    };

    int l = x, r = x;
    add(r);
    for(int i = 1; i < k; ++i) {
        r = next(r);
        add(r);
    }
    long long ans = val;
    for(int i=k; i < n; ++i) {
        remove(l);
        l = next(l);
        r = next(r);
        add(r);
        ans = ans ^ val;
    }
    cout << ans << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}