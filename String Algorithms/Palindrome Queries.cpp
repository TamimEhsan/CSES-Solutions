#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

const int MAX = 200009;

struct FenwickTree {
    ll bit[MAX];
    int n;

    FenwickTree() {
        int n = MAX;
        this->n = n;
        memset(bit, 0, sizeof(bit));
    }
    int sum(int r,int MOD) {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1){
            ret += bit[r];
            ret%=MOD;
        }
        return ret;
    }

    int sum(int l, int r,int MOD) {
        return (sum(r,MOD) - sum(l - 1,MOD)+MOD)%MOD;
    }

    void add(int idx, int delta,int MOD) {
        for (; idx < n; idx = idx | (idx + 1)){
            bit[idx] += delta;
            bit[idx]%=MOD;
        }
    }
    void update(int idx,int val,int MOD){
        int prevVal = sum(idx,idx,MOD);
        int delta = (val - prevVal + MOD)%MOD;
        add(idx,delta,MOD);
    }
};


ll mods[2] = {1000000007, 1000000009};
//Some back-up primes: 1072857881, 1066517951, 1040160883
ll bases[2] = {137, 281};
ll pwbase[3][MAX];

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
    FenwickTree ftree[2];
    string str;

    Hashing(){}
    Hashing(string _str) {str = _str; memset(hsh, 0, sizeof(hsh)); Build();}
    void init(string _str) {str = _str; memset(hsh, 0, sizeof(hsh)); Build();}

    void Build(){
        for(ll i = str.size() - 1; i >= 0; i--){
            for(int j = 0; j < 2; j++){
                hsh[j][i] = (str[i]*pwbase[j][i]) % mods[j];
                hsh[j][i] = (hsh[j][i] + mods[j]) % mods[j];
                ftree[j].add(i, hsh[j][i],mods[j] );
            }
        }
    }
    void update(int i,char c){
        for(int j = 0; j < 2; j++){
            hsh[j][i] = (c*pwbase[j][i]) % mods[j];
            hsh[j][i] = (hsh[j][i] + mods[j]) % mods[j];
            ftree[j].update(i, hsh[j][i],mods[j] );
        }
    }
    pair<ll,ll> GetHash(ll i, ll j){
        assert(i <= j);

        ll tmp1 = ftree[0].sum(i,j,mods[0]);
        ll tmp2 = ftree[1].sum(i,j,mods[1]);
        if(tmp1 < 0) tmp1 += mods[0];
        if(tmp2 < 0) tmp2 += mods[1];
        return make_pair(tmp1, tmp2);
    }
};

Hashing hashed,reverseHashed;
int n;
bool comparePalindrom(int l,int r){

    auto h1 = hashed.GetHash(l,r);
    auto h2 = reverseHashed.GetHash(n-r-1,n-l-1);

    bool b1 = (h1.F*pwbase[0][ n-r-1 ])%mods[0] == (h2.F*pwbase[0][l])%mods[0];
    bool b2 = (h1.S*pwbase[1][ n-r-1 ])%mods[1] == (h2.S*pwbase[1][l])%mods[1];

    return b1 and b2;

}
string s,rev;
int main(){
    FASTIO;
    Preprocess();
    int q;
    cin>>n>>q;
    cin>>s;
    rev = s;
    reverse(rev.begin(),rev.end());

    hashed.init(s);
    reverseHashed.init(rev);

    while(q--){
        int t;
        cin>>t;
        if( t == 2 ){
            int l,r;
            cin>>l>>r;
            l--;r--;
            if( comparePalindrom(l,r) ) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }else{
            int k;
            char x;
            cin>>k>>x;
            k--;
            hashed.update(k,x);
            reverseHashed.update(n-k-1,x);
        }
    }
}
