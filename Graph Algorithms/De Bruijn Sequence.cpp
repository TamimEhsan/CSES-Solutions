#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
#define endl '\n'

int Set(int N,int pos){return N=N | (1<<pos);}
int reset(int N,int pos){return N= N & ~(1<<pos);}
bool check(int N,int pos){return (bool)(N & (1<<pos));}

int o;

int flip(int n, int pos) {
    int bit = check(n,o-1);
    if(bit) {
        n = reset(n,o-1);
    } else {
        n = Set(n,o-1);
    }
    return n;
}
bool is_necklace(int _n) {
    int n = _n;
    for(int i=o-1;i>=0;i--) {
        int bit = check(n,o-1);
        n = reset(n,o-1);
        n = n*2 + bit;
        if(n<_n) return false;
    }
    return true;
}
void solve() {
    cin>>o;
    int cur = 0;
    do {
        int bit = check(cur,o-1);
        cur = reset(cur,o-1);
        cur = cur*2;
        if(is_necklace(cur+1)) {
            cur+=1-bit;
        } else {
            cur+=bit;
        }
        cout<<bit;
    } while(cur!=0);
    for(int i=0;i<o-1;i++) cout<<0;
}

signed main() {
    //FASTIO;
    int tc = 1;
    // cin>>tc;

    for(int i=1;i<=tc;i++) {
        solve();
    }
}
