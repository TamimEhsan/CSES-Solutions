#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    
    map<int,int> last;
    long long result = 0;
    
    for(int i=1;i<=n;i++){
        int lastIndex = last[a[i]];
        result += (long long)(i - lastIndex) * (n-i+1);
        last[a[i]] = i;
    }
    
    cout << result << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    solve();
    
    return 0;
}