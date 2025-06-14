#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

deque< pair<int, int> > window;

void add(int val, int index) {
    while (!window.empty() && window.back().first >= val)
       window.pop_back();
     window.push_back(make_pair(val, index));
}
void remove(int index) {
    while( !window.empty() && window.front().second <= index)
       window.pop_front();
}

int get() {
    if (!window.empty())
        return window.front().first;
    return 0;
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
    add(r, 0);
    for(int i = 1; i < k; ++i) {
        r = next(r);
        add(r, i);
    }
    long long ans = get();
    for(int i=k; i < n; ++i) {
        remove(i - k);
        l = next(l);
        r = next(r);
        add(r, i);
        ans = ans ^ get();
    }
    cout << ans << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}