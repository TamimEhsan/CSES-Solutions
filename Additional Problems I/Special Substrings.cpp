#include<bits/stdc++.h>
using namespace std;
#define INF 2047483647
#define INFL 9223372036854775807
#define ll long long
//#define int long long
#define pii pair<ll,ll>
#define F first
#define S second
//#define mp make_pair
#define pb push_back
#define ull unsigned long long
#define M 1000000007
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
#define take(x) scanf("%d",&x)
#define DE(x) printf("\ndebug %d\n",x);
#define vout(x) for(int i=0;i<x.size();i++) printf("%d ",x[i]);
#define pie acos(-1)
#define MOD 998244353
#define endl '\n'




const int N = 2000005;

map<vector<int>,int> mp;


void solve(){
    string s;
    cin>>s;
    vector<int> freq;
    int ch;
    int pres[26] = {0};
    for(auto &c:s){
        if( !pres[c-'a'] ) {
            freq.push_back(0);
            pres[c-'a'] = freq.size();
        }
        c = pres[c-'a'] + 'a' - 1;

    }
    long long res=0;

    mp[freq]++;
    for(int i=0;i<s.size();i++){
        freq[s[i]-'a']++;
        int mn = freq[0];
        for(auto f:freq) mn = min(mn,f);
        for(auto &f:freq) f-=mn;
        res+=mp[freq];
        mp[freq]++;
    }
    cout<<res;
}


int main(){

    FASTIO;
    int tc=1;
    //cin>>tc;
    while(tc--)
    solve();

}
