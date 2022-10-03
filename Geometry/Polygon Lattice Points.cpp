#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define aa first
#define bb second
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
#define PIE acos(-1)

struct point{
    ll x;
    ll y;
};
ll getLineLattice(ll x,ll y){
    if( x<0 ) x = -x;
    if(y<0) y = -y;

    return __gcd(x,y)+1;
}

ll getArea(const vector<point>& fig) {
    ll res = 0;
    for (unsigned i = 0; i < fig.size(); i++) {
        point p = i ? fig[i - 1] : fig.back();
        point q = fig[i];
        res += (p.x - q.x) * (p.y + q.y);
    }
    return labs(res);
}

int main(){
    cout<<fixed<<setprecision(20);
    int n;
    cin>>n;

    vector<point> pol;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        pol.push_back({a,b});
    }
    ll area = getArea(pol);
    ll B = 0;
    for(int i=0;i<pol.size();i++){
        B+= getLineLattice(  pol[i].x-pol[(i+1)%n].x,pol[i].y-pol[(i+1)%n].y );
    }
    B-=n;
    ll I = (area+2-B)/2;
    cout<<I<<" "<<B;

}
