#include<bits/stdc++.h>
using namespace std;
//#define INF 2147483647
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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int my_rand(int l, int r){return uniform_int_distribution<int>(l,r) (rng);}


const int MAX = 1000005;
int mob[MAX];

// mob = mobius function
int least[MAX];
vector<int> primes;

void RunLinearSieve(int n) {
    n = max(n, 1);
    for(int i = 0; i <= n; i++) least[i] = 0;

    primes.clear();
    mob[1] = 1;

    for(int i = 2; i <= n; i++){
        if(least[i] == 0){
            least[i] = i;
            mob[i] = -1;
            primes.push_back(i);
        }
        for(int x : primes){
            if(x > least[i] || i * x > n) break;
            least[i * x] = x;
            if(least[i] == x){
                mob[i * x] = 0;
            }else{
                mob[i * x] = -mob[i];
            }
        }
    }
}

int Numbers[MAX];
int main(){
    RunLinearSieve(1000004);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        Numbers[a]++;
    }
    ll res = 0;
    for(int i=1;i<MAX;i++){
        ll pairs = 0;
        for(int j=i;j<MAX;j+=i){
            pairs+=Numbers[j];
        }
        pairs = pairs*(pairs-1)/2;
        res+=pairs*mob[i];
    }
    cout<<res;

}
