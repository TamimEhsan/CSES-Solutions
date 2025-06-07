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
    int cnt=0;
    for(int i=0;i<n;i++){
        if( machines[i]>val ) return false;
        if( products+machines[i]>val ){
            products = 0;
            cnt++;
        }
        products+=machines[i];
 
 
    }
    cnt++;
  //  cout<<cnt<<endl;
    return cnt<=target;
}
 
int main(){
//ifstream cin("test_input.txt");
    ll t;
    cin>>n>>t;
    for(int i=0;i<n;i++)
        cin>>machines[i];
    ll hi = 2e16;
    ll lo = 0;
    ll res = 0;
    while(lo<=hi){
        ll mid = (lo+hi)/2;
      //  cout<<lo<<" "<<mid<<" "<<hi<<" ";
        if( check(mid,t) ){
            res = mid;
            hi = mid-1;
        }else{
            lo = mid+1;
        }
    }
    cout<<res;
}