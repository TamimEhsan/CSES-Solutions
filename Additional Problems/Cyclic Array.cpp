#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
const int N = 400005;

int ara[N];
ll cum[N];
int len[N];
int nxt[N];
int n;
ll k;
int get(int st){
    if( st == 0 ) st = n;
    if( st > n ) st -= n;
    int it = st;
    int sub = 0;
    while(it<st+n){
        sub++;
        it = nxt[it];
    }
    return sub;
}
int main(){

    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>ara[i];
        ara[n+i] = ara[i];
    }
    for(int i=1;i<=2*n;i++) cum[i] = cum[i-1]+ara[i];
    if( cum[n]<=k ){
        cout<<1;
        return 0;
    }
    int ind = 1;
    for(int i=1;i<=2*n;i++){
        int it = upper_bound(cum,cum+2*n+1,cum[i-1]+k)-cum;
        nxt[i] = it;
    }
    for(int i=1;i<=n;i++){
        int it = nxt[i];
        it--;
        len[i] = it-i+1;
        if( len[i]<=len[ind] ) ind = i;
    }
    int mn = n;
    for(int i=-1;i<=len[ind];i++){
        mn = min(mn,get(ind+i) );
    }
    cout<<mn;
}
