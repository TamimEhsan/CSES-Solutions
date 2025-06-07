#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll,ll>
#define F first9
#define S second

ll dp[19];
void preProcess(){
    ll mul = 1;
    for(int i=1;i<19;i++){
        dp[i] = dp[i-1]*10+mul;
        mul*=10;
    }
}
ll getOnes(ll n){
    ll mul = 1;
    ll pos = 1;
    ll ones = 0;
    ll revN = 0;
    while(n){
        ll d = n%10;
        if( d == 0 ){}
        else if( d == 1 ){
            ones+=d*dp[pos-1]+revN+1;
        }else{
            ones+=mul+d*dp[pos-1];
        }
        revN = revN+mul*d;
        mul*=10;
        pos++;
        n/=10;
    }
    return ones;
}
int main(){
    preProcess();
    ll n;
    cin>>n;
    ll res = -1;
    ll hi = 1000000000000000000;
    ll lo = 1;
    while(hi>=lo){
        ll mid = (hi+lo)/2;
       // cout<<"de "<<mid<<endl;
        ll ones = getOnes(mid);
        if( ones>n ) hi = mid-1;
        else{
            res = mid;
            lo = mid+1;
        }
    }
    cout<<res<<endl;

}
