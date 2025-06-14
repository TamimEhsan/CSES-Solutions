#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

set<pair<int,int>> freq_set;
map<int, int> freq_map;
void add(int v) {
    int freq = freq_map[v];

    freq_set.erase({-freq, v});

    freq_set.insert({-(freq + 1), v});
    freq_map[v]++;
}
void remove(int v) {
    int freq = freq_map[v];
    
    freq_set.erase({-freq, v});

    if ( freq > 1 )
        freq_set.insert({-(freq - 1), v});
    freq_map[v]--;
}

int get() {
    return freq_set.begin()->second;
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