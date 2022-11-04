#include "bits/stdc++.h"
using namespace std;
#define ll long long

ll val[20];
ll d[20];
void preprocess(int n){
    ll dec = 1;
    for(int i=1;i<n;i++){
        val[i] = val[i-1] + (dec*10-dec)*i;
        dec*=10;
        d[i] = dec-1;
    }
}



void getDigit(ll k){
    auto pos = lower_bound(val,val+17,k)-val;
    ll dis = k - val[pos-1];
    ll ith = dis/pos;
    if( ith*pos!=dis ) ith++;
    ll rem = dis - (ith-1)*pos;
    ll V = ith+d[pos-1];
    for(int i=0;i<pos-rem;i++){
        V/=10;
    }
    cout<<V%10<<endl;
}

int main(){
    preprocess(17);
    int q;
    cin>>q;
    while(q--){
        ll k;
        cin>>k;
        getDigit(k);
    }
}
