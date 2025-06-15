#include<bits/stdc++.h>
using namespace std;
 
#define endl '\n'
 
int basis[35];
void add (int x) {
    for (int i = 31; i >= 0; --i) {
        if ((x >> i) & 1) {
            if (!basis[i]) {
                basis[i] = x;
                return;
            }
            x ^= basis[i];
        }
    }
}
 
int getMaxXor() {
    int ans = 0;
    for (int i = 31; i >= 0; --i) {
        if ( (ans ^ basis[i]) > ans) {
            ans ^= basis[i];
        }
    }
    return ans;
}
void solve () {
    int n, val;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> val;
        add(val);
    }
    
    cout << getMaxXor() << endl;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    solve();
 
    return 0;
}