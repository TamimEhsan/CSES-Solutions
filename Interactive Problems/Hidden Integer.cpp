#include<bits/stdc++.h>
using namespace std;

bool ask(int x) {
    cout << "? " << x << endl;
    string res;
    cin >> res;
    return res == "YES";
}
void answer(int x) {
    cout << "! " << x << endl;
}
void solve() {
    int l = 1, r = 1000000000;
    int res = -1;
    while(l <= r) {
        int mid = (l + r) / 2;
        if(ask(mid)) {
            l = mid + 1; 
        } else {
            res = mid;
            r = mid - 1;
        }
    }
    answer(res);
}
int main() {

    solve();

    return 0;
}