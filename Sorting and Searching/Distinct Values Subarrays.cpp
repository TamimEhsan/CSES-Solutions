#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

map<int,int> freq;

int repeats;

void add(int x) {
    freq[x]++;
    if (freq[x] == 2) {
        repeats++;
    }
}

void remove(int x) {
    freq[x]--;
    if (freq[x] == 1) {
        repeats--;
    }
}

void solve() {
    int n;
    cin >> n;
    vector<int> ara(n);
    for (int i = 0; i < n; i++) {
        cin >> ara[i];
    }

    int l = 0, r = 0;
    long long ans = 0;

    while (r < n) {
        add(ara[r]);
        while (repeats > 0) {
            remove(ara[l]);
            l++;
        }
        ans += r - l + 1;
        r++;
    }

    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}