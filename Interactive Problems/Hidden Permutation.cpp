#include<bits/stdc++.h>
using namespace std;
 
 
bool ask(int x, int y) {
    cout << "? " << x << " " << y << endl;
    string res;
    cin >> res;
    return res == "YES";
}
 
void solve() {
    int n;
    cin >> n;
    int ara[n], bara[n];
    for(int i = 0; i < n; i++) {
        ara[i] = i + 1;
    }
 
    stable_sort(ara, ara + n, [](int a, int b) {
        return ask(a, b);
    });
    for (int i = 0; i < n; i++) {
        bara[ ara[i] - 1 ] = i + 1;
    }
    cout << "! ";
    for (int i = 0; i < n; i++) {
        cout << bara[i] << " ";
    }
}
 
int main() {
 
    solve();
 
    return 0;
}