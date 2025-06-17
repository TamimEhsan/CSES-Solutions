#include<bits/stdc++.h>
using namespace std;

struct Node {
    long long tot, pref, suf, mx;
};

Node Merge(Node l, Node r) {
    Node res;
    res.tot = l.tot + r.tot;
    res.pref = max(l.pref, l.tot + r.pref);
    res.suf = max(r.suf, r.tot + l.suf);
    res.mx = max({l.mx, r.mx, l.suf + r.pref});
    return res;
}

const int N = 200005;
int ara[N];
Node seg[4 * N];

void build(int node, int l, int r) {
    if (l > r) return;
    if (l == r) {
        seg[node].tot  = ara[l];
        seg[node].pref = seg[node].suf = seg[node].mx = max(0, ara[l]);
        return;
    }
    int mid = (l + r) / 2;
    build(2 * node, l, mid);
    build(2 * node + 1, mid + 1, r);
    seg[node] = Merge(seg[2 * node], seg[2 * node + 1]);
}

Node query(int node, int l, int r, int L, int R) {
    if (l > r || l > R || r < L) return {0, 0, 0, 0};
    if (l >= L && r <= R) return seg[node];
    int mid = (l + r) / 2;
    Node left = query(2 * node, l, mid, L, R);
    Node right = query(2 * node + 1, mid + 1, r, L, R);
    return Merge(left, right);
}

void solve() {
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> ara[i];
    }
    build(1, 1, n);
    
    while (q--) {
        int i, j;
        cin >> i >> j;
        Node res = query(1, 1, n, i, j);
        cout << res.mx << endl;
    }
}

int main() {
    solve();
}