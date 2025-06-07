#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define F first
#define S second
#define ll long long
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
#include <bits/stdc++.h>
using namespace std;
 
void solve(){
 
    int n,k;
    cin>>n>>k;
    int ara[n];
    for(int i=0;i<n;i++) cin>>ara[i];
    int r=n-1;
    map<int,int> last;
    int inFrame = 0;
    ll res = 0;
    for(int l=n-1;l>=0;l--){
        if( last[ ara[l] ] == 0 or last[ ara[l] ] >r ) inFrame++;
        last[ ara[l] ] = l;
        while( inFrame>k ){
            if( last[ ara[r] ] == r ) inFrame--;
            r--;
        }
 
        //cout<<l<<" "<<r<<endl;
        res+=r-l+1;
    }
    cout<<res;
}
 
 
int main(){
    FASTIO;
    solve();
 
}
 
// https://lightoj.com/problem/internet-bandwidth