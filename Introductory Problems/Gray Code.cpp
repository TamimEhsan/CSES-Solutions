#include "bits/stdc++.h"
using namespace std;
#define ll long long

ll gray_code(ll x){return x ^ (x >> 1);}
ll inverse_gray_code(ll x){
    ll h = 1, res = 0;
    do{
        if (x & 1) res ^= h;
        x >>= 1, h = (h << 1) + 1;
    } while (x);
    return res;
}


void printBin(ll x,int rem){
    if( !rem ) return;
    printBin(x>>1,rem-1);
    cout<<x%2;
}
int main(){
    int n;
    cin>>n;
    for(int i=0;i<(1<<n);i++){
        printBin( gray_code(i),n );
        cout<<endl;
    }
}
