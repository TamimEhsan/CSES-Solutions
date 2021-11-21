#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define INF 2047483647
#define INFL 9223372036854775807
#define ll long long
#define pii pair<int,int>
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define ull unsigned long long
#define M 1000000007
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
#define take(x) scanf("%d",&x)
#define DE(x) printf("\ndebug %d\n",x);
#define vout(x) for(int i=0;i<x.size();i++) printf("%d ",x[i]);
#define pie acos(-1)
#define MOD 998244353

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int my_rand(int l, int r) {
    return uniform_int_distribution<int>(l,r) (rng);
}


const int maxn = 1000005;
int cnt[maxn];
int mx = 1;
void seive(){
    for(int i = 1;i<maxn;i++){
        int cnts = 0;
        for(int j=1;j*i<maxn;j++){
            cnts+=cnt[i*j];
        }
        if( cnts>1 ) mx = i;
    }
}


int main() {
    int n;
    scanf("%d",&n);

    for(int i=0; i<n; i++) {
        int a;
        scanf("%d",&a);
       cnt[a]++;
    }
    seive();

    printf("%d",mx);

}

