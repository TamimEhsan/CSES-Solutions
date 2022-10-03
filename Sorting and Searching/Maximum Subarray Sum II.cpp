#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
#define pub push_back
#define pob pop_back
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

int main(){
    int n,a,b;
    cin>>n>>a>>b;
    int ara[n];
    ll cumsum[n];
    for(int i=0;i<n;i++) cin>>ara[i];
    cumsum[0] = ara[0];
    for(int i=1;i<n;i++) cumsum[i] = cumsum[i-1]+ara[i];
    map<ll,int> cnt;
    set<ll> st;
    for(int i=a-1;i<b;i++) {
        cnt[ cumsum[i] ]++;
        st.insert(-cumsum[i]);
    }
    ll res = -(*st.begin());
    for(int i=a-1,j=b,k=0;k<n-a;i++,j++,k++){
        if( j<n ){
            cnt[cumsum[j]]++;
            if( cnt[cumsum[j]]==1 ) st.insert( -cumsum[j] );
        }
        cnt[ cumsum[i] ]--;
        if( cnt[cumsum[i]] == 0 ) st.erase(-cumsum[i]);

        ll temp = -(*st.begin())-cumsum[k];
        res=max(res,temp);
    }

    cout<<res;
}
