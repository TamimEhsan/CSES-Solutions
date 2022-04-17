#include<bits/stdc++.h>
using namespace std;
#define INF 2047483647
#define INFL 9223372036854775807
#define ll long long
#define pii pair<ll,ll>
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define ull unsigned long long
#define M 1000000007
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
#define take(x) scanf("%d",&x)
#define DE(x) printf("\ndebug %d\n",x);
#define vout(x) for(int i=0;i<x.size();i++) printf("%d ",x[i]);
#define pie acos(-1)
#define MOD 998244353

int Set(int N,int pos){return N=N | (1<<pos);}
int reset(int N,int pos){return N= N & ~(1<<pos);}
bool check(int N,int pos){return (bool)(N & (1<<pos));}


int main(){
    FASTIO;
    vector<int>l,r;
    ll n,x;
    cin>>n>>x;
    int i=0;
    for(;i<n/2;i++){
        int a;
        cin>>a;
        l.pb(a);
    }
    for(;i<n;i++){
        int a;
        cin>>a;
        r.pb(a);
    }
    vector<ll> L;
    int mxBit = 1<<l.size();
    for(int bit = 0;bit<mxBit;bit++){
        ll sum = 0;
        for(int pos=0;pos<l.size();pos++){
            if( check(bit,pos) )
                sum+=l[pos];
            if( sum>x ) break;
        }
        if( sum>x ) continue;
        L.pb(sum);
    }
    mxBit = 1<<r.size();
    ll res = 0;
    sort(L.begin(),L.end());
    for(int bit = 0;bit<mxBit;bit++){
        ll sum = 0;
        for(int pos=0;pos<r.size();pos++){
            if( check(bit,pos) )
                sum+=r[pos];
            if( sum>x ) break;
        }
        if( sum>x ) continue;
        int val = upper_bound(L.begin(),L.end(),x-sum) - lower_bound(L.begin(),L.end(),x-sum);
        res+=val;
    }
    cout<<res;
}
