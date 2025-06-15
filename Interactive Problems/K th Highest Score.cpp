#include<bits/stdc++.h>
using namespace std;

int n, k; 
int ask(int x, int country) {
    if ( x <= 0 ) return 1000000004;
    if ( x > n ) return 0;
    string country_str = (country == 0) ? "F" : "S";
    cout << country_str << " " << x << endl;
    int res;
    cin >> res;
    return res ;
}
void answer(int x) {
    cout << "! " << x << endl;
}

bool tries(int country) {
    int res = -1;
    int l = 1, r = k;
    int dec = k/2;
    while( l <= r) {
        int mid = (l + r) / 2;
        int res1 = ask(mid, country);
        int res2 = ask(k-mid, 1 - country);
        if ( res1 <= res2 ) {
            res = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    if ( res != -1 ) {
        int res1 = ask(res, country);
        int res2 = ask(k-res+1, 1 - country);
        if ( res1 >= res2 ) {
            answer(res1);
            return true;
        } 
    }
    return false;

}

void solve () {
    cin >> n >> k;
    
    bool found = tries(0);
    if ( found ) return;
    found = tries(1);
    if ( found ) return;
    answer(-1);
}
 
int main() {

    solve();
 
    return 0;
}