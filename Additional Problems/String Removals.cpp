#include<bits/stdc++.h>
using namespace std;
#define INF 2047483647
#define INFL 9223372036854775807
#define int long long
#define ll long long
#define pii pair<ll,ll>
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define ull unsigned long long
#define M 1000000007
//#define M 998244353
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
#define take(x) scanf("%d",&x)
#define DE(x) printf("\ndebug %d\n",x);
#define vout(x) for(int i=0;i<x.size();i++) printf("%d ",x[i]);
#define pie acos(-1)
#define MOD 998244353
#define endl '\n'

#define int long long

int Set(int N,int pos){return N=N | (1<<pos);}
int reset(int N,int pos){return N= N & ~(1<<pos);}
bool check(int N,int pos){return (bool)(N & (1<<pos));}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int my_rand(int l, int r){return uniform_int_distribution<int>(l,r) (rng);}

const int N = 500005;
int dp[N];
int last[26];

int get(int l,int r){
    if( l == 0 ) return dp[r];
    else return (dp[r] - dp[l-1] + M)%M;
}
void solve(){
    dp[0] = 1;
    string s;
    cin>>s;
    s = "#" + s;
    int res = 0;
    for(int i=1;i<s.size();i++){
        dp[i] = dp[i-1];
        int c = s[i] - 'a';
        int l = last[c];
        int r = i-1;
        dp[i] += get(l,r);
        last[c] = i;
        res+=dp[i];
        res%=M;
        //cout<<i<<" "<<l<<" "<<r<<" "<<dp[i]<<" \n";
    }
    cout<<(dp[s.size()-1]-1+M)%M;

}
signed main(){
    FASTIO;
    int tc=1;
    //cin>>tc;

    while(tc--) solve();
}
