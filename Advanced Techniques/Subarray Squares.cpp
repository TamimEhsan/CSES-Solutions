#include<bits/stdc++.h>
using namespace std;


#pragma GCC optimize("O3,unroll-loops")
#define INF 2047483647
#define INFL 9223372036854775807
#define ll long long
#define pii pair<int,int>
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define ull unsigned long long
//#define M 1000000007
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
#define take(x) scanf("%d",&x)
#define DE(x) printf("\ndebug %d\n",x);
#define vout(x) for(int i=0;i<x.size();i++) printf("%d ",x[i]);
#define pie acos(-1)
#define MOD 998244353
#define infl 10000000000
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int my_rand(int l, int r){return uniform_int_distribution<int>(l,r) (rng);}

/***********set based implementation
source:https://github.com/kth-competitive-programming/kactl/blob/main/content/data-structures/LineContainer.h
***************************/
struct Line {
	mutable ll k, m, p;
	bool operator<(const Line& o) const { return k < o.k; }
	bool operator<(ll x) const { return p < x; }
};

// queries for maximum
// if we want minimum then make minimum = true
bool minimum = true;
struct LineContainer : multiset<Line, less<>> {
	// (for doubles, use inf = 1/.0, div(a,b) = a/b)
	static const ll inf = LLONG_MAX;
	ll div(ll a, ll b) { // floored division
		return a / b - ((a ^ b) < 0 && a % b); }
	bool isect(iterator x, iterator y) {
		if (y == end()) return x->p = inf, 0;
		if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
		else x->p = div(y->m - x->m, x->k - y->k);
		return x->p >= y->p;
	}
	// y = m*x+c; x will be the query parameter used later
	void add(ll m, ll c) {
	    if( minimum ){
            m=-m;
            c=-c;
	    }
		auto z = insert({m, c, 0}), y = z++, x = y;
		while (isect(y, z)) z = erase(z);
		if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
		while ((y = x) != begin() && (--x)->p >= y->p)
			isect(x, erase(y));
	}
	ll query(ll x) {
		assert(!empty());
		auto l = *lower_bound(x);
		if( minimum ) return -(l.k * x + l.m);
		return l.k * x + l.m;
	}
};

const int N = 3005;
ll dp[N][N];
ll cumsum[N];
int main(){
    FASTIO;
    int n,k;
    cin>>n>>k;
    ll ara[n+1];
    for(int i=1;i<=n;i++){
        cin>>ara[i];
        cumsum[i] = cumsum[i-1]+ara[i];
    }
    for(int i=1;i<=k;i++){
        LineContainer cht;
        for(int j=1;j<=n;j++){
            if( j<i-1 ) {
                //cout<<-1<<" ";
                continue;
            }
            if( j == i-1 ){
               // cout<<-1<<" ";
                cht.add( -2*cumsum[j],dp[i-1][j]+cumsum[j]*cumsum[j] );
                continue;
            }
            dp[i][j] = (cht.empty()?0: cht.query(cumsum[j])) + cumsum[j]*cumsum[j];
           // cout<<dp[i][j]<<" ";
            if( i!=1 )  cht.add( -2*cumsum[j],dp[i-1][j]+cumsum[j]*cumsum[j] );
        }

    }
    cout<<dp[k][n]<<endl;

}


