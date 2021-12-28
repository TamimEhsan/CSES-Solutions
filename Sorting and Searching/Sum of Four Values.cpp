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
int my_rand(int l, int r){return uniform_int_distribution<int>(l,r) (rng);}


struct Sum{
    int sum;
    int i;
    int j;
};
int main(){

    int n,x;
    cin>>n>>x;
    int ara[n];
    for(int i=0;i<n;i++) cin>>ara[i];
    map<int,vector<pii>> m;
    vector<Sum> sums;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            m[ ara[i]+ara[j] ].push_back({i,j});
            sums.push_back({ara[i]+ara[j],i,j});
        }
    }
    for(auto [sum,i,j]:sums){
        int req = x-sum;
        for(auto [k,l]:m[req]){
            if( i!=k and i!=l and j!=k and j!=l ){
                cout<<i+1<<" "<<j+1<<" "<<k+1<<" "<<l+1;
                return 0;
            }
        }
    }
    cout<<"IMPOSSIBLE";
}

// 1 2 2 7 9

