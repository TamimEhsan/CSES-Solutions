#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll,ll>
#define F first9
#define S second
 
const int N = 100;
int grid[N][N][N];
 
vector<int> getBits(int n){
    vector<int>bits;
    int nn = n;
    int b = 0;
    while(nn){
        if( nn%2 ) bits.push_back(b);
        b++;
        nn/=2;
    }
    //for(auto bit:bits) cout<<bit<<" ";
    reverse(bits.begin(),bits.end());
    if( bits.size() == 1 ){
        vector<int>res;
        for(int i=1;i<=n;i++){
            res.push_back(i);
        }
        return res;
    }
    int retN = 0;
    for(int i=1;i<bits.size();i++)
        retN+= (1<<bits[i]);
    auto ret = getBits(retN);
    int sz = ret.size();
    int offset = 1<<bits[0];
    for(int i=0;i<sz;i++)
        ret.push_back( ret[i]+offset );
    return ret;
}
 
int main(){
    int n;
    cin>>n;
    int ara[n];
    for(int i=0;i<n;i++) cin>>ara[i];
    auto bits = getBits(n);
    int xorr = 0;
    for(auto bit:bits){
        xorr^=ara[bit-1];
    }
    cout<<xorr;
 
}