#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define ll long long
#define F first
#define S second


int main(){
    ll n,k;
    cin>>n>>k;
    int hi = n,lo = 1;
    int perm[n+1];
    for(int i=1;i<=n;i++){
        if( k>=n-i ){
            perm[i] = lo++;
            k-=n-i;
        }else{
            perm[i] = hi--;
        }
    }
    for(int i=n;i>0;i--) cout<<perm[i]<<" ";
}
