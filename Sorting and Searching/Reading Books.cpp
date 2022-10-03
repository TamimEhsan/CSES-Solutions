#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main(){
    int n;
    cin>>n;
    ll ara[n];
    for(int i=0;i<n;i++)
        cin>>ara[i];
    sort(ara,ara+n);
    ll sum = 0;
    for(int i=0;i<n-1;i++){
        sum+=ara[i];
    }
    if( sum>ara[n-1] ) cout<<sum+ara[n-1];
    else cout<<2*ara[n-1];

}
