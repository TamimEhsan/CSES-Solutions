#include<bits/stdc++.h>
using namespace std;
 
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
#define endl '\n'
 

int aggFunc(int a, int b) {
    return a | b; // Bitwise OR operation
}
struct AggStack {
    // Each element is stored as (value, current_min)
    stack<pair<int, int>> st;
    
    // Push a new number; compute the new min.
    void push(int x) {
        int cur = st.empty() ? x : aggFunc(st.top().second , x);
        st.push({x, cur});
    }
    
    // Pop the top element.
    void pop() {
        st.pop();
    }
    
    // Return the current minimum.
    int agg() const {
        return st.top().second;
    }
};
 
struct AggQueue {
    AggStack in, out;
        
 
    // Push a new number into the queue.
    void push(int x) {
        in.push(x);
    }
    
    // Pop the oldest number.
    void pop() {
        if (out.st.empty()) {
            while (!in.st.empty()) {
                int v = in.st.top().first;
                in.pop();
                out.push(v);
            }
        }
        out.pop();
    }
    
    // Query the current minimum.
    int query() const {
        if (in.st.empty()) return out.agg();
        if (out.st.empty()) return in.agg();
        return aggFunc(in.agg() , out.agg());
    }
};
 
void solve() {
    int n, k;
    cin >> n >> k;
    int x, a, b, c;
    cin >> x >> a >> b >> c;
    AggQueue aggQueue;
 
    auto next = [&](int v) {
        return (1LL * a * v + b) % c;
    };
 
    int l = x, r = x;
    aggQueue.push(r);
    for(int i = 1; i < k; ++i) {
        r = next(r);
        aggQueue.push(r);
    }
    long long ans = aggQueue.query();
    for(int i=k; i < n; ++i) {
        aggQueue.pop();
        l = next(l);
        r = next(r);
        aggQueue.push(r);
        ans = ans ^ aggQueue.query();
    }
    cout << ans ;
}
 
int main(){
    FASTIO;
 
    solve();
}