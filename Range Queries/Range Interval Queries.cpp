#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
 
#include <bits/stdc++.h>
using namespace std;
 
struct Event {
    int type; // 0 = insert x[i], 1 = query
    int idx;  // i for insert, query index for query
    int val;  // value of x[i]
    int c, d; // [c, d] for query
    int ans_idx; // index to store answer
    int multiplier = 1; // multiplier for value, if needed
};
 
struct FenwickTree {
    vector<int> bit;  // binary indexed tree
    int n;
 
    FenwickTree(int n) {
        this->n = n;
        bit.assign(n, 0);
    }
 
    FenwickTree(vector<int> const &a) : FenwickTree(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }
 
    int sum(int r) {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }
 
    int sum(int l, int r) {
        if (l > r) return 0;
        return sum(r) - sum(l - 1);
    }
 
    void add(int idx, int delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
};
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int n, q;
    cin >> n >> q;
 
    vector<int> x(n);
    for (int i = 0; i < n; ++i)
        cin >> x[i];
 
    vector<vector<int>> queries(q, vector<int>(4));
    for (int i = 0; i < q; ++i) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        queries[i] = {a - 1, b - 1, c, d}; // convert to 0-based
    }
 
    // Coordinate compression
    set<int> all_values;
    for (int v : x)
        all_values.insert(v);
    
 
    unordered_map<int, int> compress;
    int id = 0;
    for (int v : all_values)
        compress[v] = ++id;
 
    for (int &v : x)
        v = compress[v];
    for (auto &qr : queries) {
        auto it = all_values.lower_bound(qr[2]);
        if ( it == all_values.end() ) {
            qr[2] = compress.size()+1; // no valid c
        } else {
            qr[2] = compress[*it];
        }
 
        it = all_values.upper_bound(qr[3]);
        if ( it == all_values.begin() ) {
            qr[3] = 0; // no valid d
        } else {
            it--;
            qr[3] = compress[*it];
        }
        // cout << qr[2] << " " << qr[3] << "\n";
    }
  
 
    // Prepare Events
    vector<Event> events;
    for (int i = 0; i < n; ++i) {
        events.push_back({0, i, x[i]}); // insert x[i]
    }
 
    for (int i = 0; i < q; ++i) {
        int a = queries[i][0], b = queries[i][1];
        int c = queries[i][2], d = queries[i][3];
        events.push_back({1, b, 0, c, d, i, 1}); // query at time b
        events.push_back({1, a-1, 0, c, d, i, -1}); // query at time b
 
    }
 
    // Sort events by index (time), so insertions come before queries
    sort(events.begin(), events.end(), [](const Event &e1, const Event &e2) {
        if (e1.idx != e2.idx) return e1.idx < e2.idx;
        return e1.type < e2.type; // insert before query
    });
 
    // Fenwick Tree
    FenwickTree bit(compress.size()+1);
    vector<int> ans(q);
 
    for (auto e : events) {
        if (e.type == 0) {
            // Insert event: add x[i] to BIT
            bit.add(e.val, 1);
            // cout << "Inserted: " << e.val << "\n";
        } else {
            // Query event: get count of values in [c, d]
            ans[e.ans_idx] += bit.sum(e.c, e.d) * e.multiplier;
            // cout << "Query [" << e.c << ", " << e.d << "] at index " << e.idx 
                //  << ": count = " << bit.sum(e.c, e.d) * e.multiplier << "\n";
        }
    }
 
    // Final output
    for (int a : ans)
        cout << a << "\n";
 
    return 0;
}
