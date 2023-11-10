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

const int N = 5005;
int dp[N];

vector<vector<int>> to;
vector<int> endd;
void init(){
    vector<int>v(26,-1);
    to.push_back(v);
    endd.push_back(0);
}
void insert(string t){
    int cur = 0;
    for(int i=0;i<t.size();i++){
        int c = t[i] - 'a';
        if( to[cur][c] == -1 ){
            vector<int>v(26,-1);
            to.push_back(v);
            endd.push_back(0);
            to[cur][c] = to.size()-1;
        }
        cur = to[cur][c];
    }
    endd[cur] = 1;;

}




void solve(){

    string s;
    cin>>s;
    s = "#" + s;
    int k;
    cin>>k;
    init();
    for(int i=0;i<k;i++){
        string t;
        cin>>t;
        insert(t);
    }

    dp[0] = 1;
    for(int i=0;i<s.size()-1;i++){
        int cur = 0;
        for(int j=i+1;j<s.size();j++){
            int c = s[j] - 'a';
            if( to[cur][c] == -1 ) break;
            cur = to[cur][c];

            if( endd[cur] ) {
                dp[j]= (dp[j]+dp[i])%M;
            }
        }
    }
    cout<<dp[s.size()-1];
}
signed main(){
    FASTIO;
    int tc=1;
    //cin>>tc;

    while(tc--) solve();
}
