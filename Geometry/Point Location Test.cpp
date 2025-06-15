#include<bits/stdc++.h>
using namespace std;
 
#define endl '\n'
#define ll long long
struct PT {
    ll x, y;
    PT operator+(PT p) {return {x+p.x, y+p.y};}
    PT operator-(PT p) {return {x-p.x, y-p.y};}
    PT operator*(ll d) {return {x*d, y*d};}
    PT operator/(ll d) {return {x/d, y/d};}
    long long CrossProd(const PT &p) const {
        return x * (long long)p.y - y * (long long)p.x;
    }
    bool operator<(const PT &p) const {
        return make_pair(x, y) < make_pair(p.x, p.y);
    }
};
bool operator==(PT a, PT b) {return a.x == b.x && a.y == b.y;}
bool operator!=(PT a, PT b) {return !(a == b);}
ll sq(PT p) {return p.x*p.x + p.y*p.y;}
double abs(PT p) {return sqrt(sq(p));}
ll dot(PT v, PT w) {return v.x*w.x + v.y*w.y;}
ll cross(PT v, PT w) {return v.x*w.y - v.y*w.x;}

void solve() {
    PT x, y, p;
    cin >> x.x >> x.y >> y.x >> y.y >> p.x >> p.y;
    
    long long crss = cross(x - p, y - p);
    if ( crss == 0 ) {
        cout << "TOUCH" << endl;
    } else if ( crss > 0 ) {
        cout << "LEFT" << endl;
    } else {
        cout << "RIGHT" << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) {
        solve();
    }

    return 0;
}