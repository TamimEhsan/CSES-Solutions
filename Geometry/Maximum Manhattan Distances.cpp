#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve() {
    int n;
    cin >> n;
    long long mnX , mxX;
    long long mnY, mxY;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        
        long long xx = x + y;
        long long yy = x - y;
        if (i == 0) {
            mnX = mxX = xx;
            mnY = mxY = yy;
        }
        mnX = min(mnX, xx);
        mxX = max(mxX, xx);
        mnY = min(mnY, yy);
        mxY = max(mxY, yy);

        cout << max(mxX - mnX, mxY - mnY) << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
    
    return 0;
}