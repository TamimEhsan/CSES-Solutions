#include<bits/stdc++.h>
using namespace std;
 
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
#define endl '\n'
 
void solve() {
    long long n,m,k;
    cin>>n>>m>>k;
    int x = k%(2*(n-1));
    int y = k%(2*(m-1));
    if( x>=n-1 ) x = n*2-x-2;
    if( y>=m-1 ) y = m*2-y-2;
    int g = __gcd(n-1, m-1);
    long long lcm = (n-1)*(m-1)/g;
    long long t = k/(n-1)+k/(m-1)-k/lcm;
    cout<<x+1<<" "<<y+1<<" "<<t<<endl; 
}
 
int main() {
    FASTIO; 
    int tc;
    cin>>tc;
    while(tc--)
        solve();
 
    return 0;
}