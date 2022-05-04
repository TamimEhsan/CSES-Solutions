#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define pii pair<int,int>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);




int main(){
    ll n,x;
    cin>>x>>n;
    priority_queue<ll>pq;
    for(int i=0;i<n;i++){
        ll a;
        cin>>a;
        pq.push(-a);
    }
    ll res = 0;
    while(pq.size()>=2){
        ll a = pq.top(); pq.pop();
        ll b = pq.top(); pq.pop();
        res-=(a+b);
        pq.push(a+b);
    }
    cout<<res;
}
