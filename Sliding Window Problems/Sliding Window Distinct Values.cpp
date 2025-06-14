#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

map<int, int> freq;

void add(int v) {
    freq[v]++;
}
void remove(int v) {
    freq[v]--;
    if (freq[v] == 0) {
        freq.erase(v);
    }
}

int get() {
    return freq.size();
}

void solve() {
    int n, k;
    cin >> n >> k;
    int ara[n];
    for(int i = 0; i < n; ++i) {
        cin >> ara[i];
    }
    
    for(int i = 0; i < k; ++i) {
        add(ara[i]);
    }
    
    cout << get() << " ";
    for(int i = k; i < n; ++i) {
        remove(ara[i-k]);
        add(ara[i]);
        cout << get() << " ";
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}