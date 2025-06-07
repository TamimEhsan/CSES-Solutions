#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
 
 
const int N = 3005;
bitset<N> bsets[N];
 
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   // ifstream cin("input.in");
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        for(int j=0;j<n;j++)
            if( s[j] == '1' ) bsets[i][j] = true;
            else bsets[i][j] = false;;
 
    }
    ll res = 0;
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            ll t = (bsets[i]&bsets[j]).count();
            res+=t*(t-1)/2;
 
        }
 
    }
    cout<<res<<endl;
}
 