#include<bits/stdc++.h>
using namespace std;
#define INF 2047483647
#define INFL 9223372036854775807
//#define int long long
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


const int MAX = 100005;

ll mods[2] = {1000000007, 1000000009};
//Some back-up primes: 1072857881, 1066517951, 1040160883
ll bases[2] = {137, 281};
//int bases[2] = {53, 41};
int pwbase[3][MAX];

void Preprocess(){
    pwbase[0][0] = pwbase[1][0] = 1;
    for(ll i = 0; i < 2; i++){
        for(ll j = 1; j < MAX; j++){
            pwbase[i][j] = (pwbase[i][j - 1] * bases[i]) % mods[i];
        }
    }
}

struct Hashing{
    ll hsh[2][MAX];
    string str;

    Hashing(){}
    Hashing(string _str) {str = _str; memset(hsh, 0, sizeof(hsh)); build();}

    void build(){
        for(ll i = str.size() - 1; i >= 0; i--){
            for(int j = 0; j < 2; j++){
                hsh[j][i] = (hsh[j][i + 1] * bases[j] + str[i]) % mods[j];
                hsh[j][i] = (hsh[j][i] + mods[j]) % mods[j];
            }
        }
    }

    pair<int,int> GetHash(ll i, ll j){
        assert(i <= j);
        ll tmp1 = (hsh[0][i] - (hsh[0][j + 1] * pwbase[0][j - i + 1]) % mods[0]) % mods[0];
        ll tmp2 = (hsh[1][i] - (hsh[1][j + 1] * pwbase[1][j - i + 1]) % mods[1]) % mods[1];
        if(tmp1 < 0) tmp1 += mods[0];
        if(tmp2 < 0) tmp2 += mods[1];
        return make_pair(tmp1, tmp2);
    }
};


void solve(){

    string s;
    cin>>s;
    int n = s.size();
    Hashing hsh(s);

    int l=1,r=n-1;
    int res = -1;
    int ind;
    while(l<=r){
        int mid = (l+r)/2;
        bool pos = false;
        vector<pair<pii,int>> st;
        for(int i=mid-1;i<n;i++){
            auto ret = hsh.GetHash(i-mid+1,i);
            //cout<<i-mid+1<<" "<<ret.first<<" "<<ret.second<<endl;
            st.push_back({ret,i-mid+1});

        }
        sort(st.begin(),st.end());
        for(int i=1;i<st.size();i++) if( st[i].first == st[i-1].first ) {
            pos = true;
            ind = st[i].second;
        }
        if( pos ){
            res = mid;
            l = mid+1;
        }else{
            r = mid-1;
        }
    }
    if( res == -1 ) cout<<res;
    else {
        for(int i=0;i<res;i++) cout<<s[i+ind];
    }
}
signed main(){
    //freopen("test_input.txt","r",stdin);
    Preprocess();
    FASTIO;
    int tc=1;
    //cin>>tc;

    while(tc--) solve();
}
