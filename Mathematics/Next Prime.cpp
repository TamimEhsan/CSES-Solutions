#include<bits/stdc++.h>
using namespace std;
#define INF 2147483647
#define INFL 9223372036854775807
#define pii pair<int,int>
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define ll long long
#define ull unsigned long long
#define M 1000000007
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
#define take(x) scanf("%d",&x)
#define DE(x) printf("\ndebug %d\n",x);
#define vout(x) for(int i=0;i<x.size();i++) printf("%d ",x[i]);
#define pie acos(-1)
#define MOD 998244353

/*
    seive of erasthosomething
    time:   N = 10^7    0.155 s
            N = 10^8    1.829 s
*/
const int N = 10000000;
vector<char> mark(N + 1, false);
vector<long long> primes;
void sieve() {
    for (long long i = 2; i < N; ++i) {
        if (!mark[i]) {
            primes.emplace_back(i);
            for (long long j = i * i; j < N; j += i)
                mark[j] = true;
        }
    }
}

long long segmentedSieve(long long L, long long R) {
    // generate all primes up to sqrt(R)
    vector<char> isPrime(R - L + 1, true);
    for (long long i : primes)
        for (long long j = max(i * i, (L + i - 1) / i * i); j <= R; j += i)
            isPrime[j - L] = false;
    if (L == 1)
        isPrime[0] = false;
    for(int i=0;i<isPrime.size();i++) if ( isPrime[i] ) return L+i;
    return -1;
}

void solve() {
    long long n;
    cin>>n;
    cout<<segmentedSieve(n+1,n+2000)<<endl;
}

int main(){
    sieve();
    int tc;
    cin>>tc;
    while(tc--) solve();
}
