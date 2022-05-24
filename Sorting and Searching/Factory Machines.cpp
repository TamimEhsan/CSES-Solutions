#include "bits/stdc++.h"
using namespace std;
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define ll long long

const int N = 200006;
ll machines[N];
int n;
bool check(ll val,ll target){
    ll products = 0;
    for(int i=0;i<n;i++){
        products+=val/machines[i];
        if( products>=target ) return true;
    }
    return products>=target;
}

int main(){
//ifstream cin("test_input.txt");
    ll t;
    cin>>n>>t;
    for(int i=0;i<n;i++)
        cin>>machines[i];
    ll hi = 2e18;
    ll lo = 0;
    ll res = 0;
    while(lo<=hi){
        ll mid = (lo+hi)/2;
        if( check(mid,t) ){
            res = mid;
            hi = mid-1;
        }else{
            lo = mid+1;
        }
    }
    cout<<res;
}
