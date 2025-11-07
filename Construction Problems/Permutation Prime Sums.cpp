#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
#define endl '\n'

const int N = 1000000;
vector<char> is_prime(N+1, true);
vector<int> primes;

void seive(){
    is_prime[0] = is_prime[1] = false;
    is_prime[2] = true;
    for (int i = 3; i * i <= N; i+=2) {
        if (is_prime[i]) {
            for (int j = i * i; j <= N; j += i)
                is_prime[j] = false;
        }
    }
    primes.push_back(2);
    for(int i=3;i<N;i+=2){ // if we need only the mapping then remove this
        if( is_prime[i] ) primes.push_back( i );
    }
}

void solve() {
    int n;
    cin >> n;
    int ara[n+1] = {0};
    int cur = n;
    while(cur > 0) {
        int prime = *upper_bound(primes.begin(),primes.end(),cur);
        int a = prime/2;
        int b = prime - a;
        while(a>0 and b<=cur) {
            ara[a] = b;
            ara[b] = a;
            a--;
            b++;
        }
        cur = a;
    }
    for(int i=1;i<=n;i++) cout<<i<<" "; cout<<endl;
    for(int i=1;i<=n;i++) cout<<ara[i]<<" "; cout<<endl;

}

signed main() {
    seive();
    FASTIO;
    int tc = 1;
    // cin>>tc;

    for(int i=1;i<=tc;i++) {
        solve();
    }
}
