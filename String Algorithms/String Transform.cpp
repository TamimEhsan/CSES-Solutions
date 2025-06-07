#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#pragma GCC optimize("O3,unroll-loops")
#define INF 2047483647
#define INFL 9223372036854775807
#define ll long long
#define pii pair<int,int>
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define ull unsigned long long
//#define M 1000000007
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
#define take(x) scanf("%d",&x)
#define DE(x) printf("\ndebug %d\n",x);
#define vout(x) for(int i=0;i<x.size();i++) printf("%d ",x[i]);
#define pie acos(-1)
#define MOD 998244353
#define infl 10000000000000000

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int my_rand(int l, int r){return uniform_int_distribution<int>(l,r) (rng);}


// inverse burrows wheeler transform

int main(){
    string s,t;
    cin>>s;
    int n = s.size();
    t = s;
    int tfreq[n]={0};
    sort(t.begin(),t.end());
    int freq[30] = {0};
    vector<int> pos[30];
    for(int i=0;i<n;i++){
        int c=0;
        if( s[i] != '#' ) c = s[i]-'a'+1;
        pos[c].push_back(i);
    }
    for(int i=0;i<n;i++){
        int c=0;
        if( t[i] != '#' ) c = t[i]-'a'+1;
        tfreq[i] = freq[c]++;
    }
    int tt = pos[0][0];

    for(int i=0;i<n-1;i++){
        int cs = 0, ct = 0;
        if( t[tt] != '#' ) ct = t[tt]-'a'+1;
        tt = pos[ ct ][ tfreq[tt] ];
        cout<<(char)('a'+ct-1);
    }
}
/*
b c d e f => 1
a c d e f => 1
b a d e f => 0
*/
