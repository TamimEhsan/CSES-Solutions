#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);


int main(){
    ll bits[54] = {0};
    for(int i=1;i<54;i++)
        bits[i] = bits[i-1]*2+ (1LL<<(i-1));

    ll n,res = 0,i = 0,nn = 0,mul = 1;
    cin>>n;
    while(n){
        ll d = n%2;
        n = n>>1;
        if( d == 1 ){
            res+= bits[i]+nn+1;
            nn = nn | mul;
        }
        mul = mul<<1;
        i++;
    }
    cout<<res<<endl;

}
