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
//#define M 1000000007
#define M 998244353
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

struct Cell{
    int mx;
    int sum;
    int res;
};
const int N = 200005;
Cell segtree[N*4];
int ara[N];



void build(int node,int l,int r){
    if( l == r ){
        segtree[node] = {ara[l],ara[l],0};
        return;
    }
    int mid = (l+r)/2;
    build(node*2,l,mid);
    build(node*2+1,mid+1,r);
    int mx = ara[l];
    int res = 0;
    int sum = ara[l];
    for(int i=l+1;i<=r;i++){
        if(ara[i]>=mx) mx = ara[i];
        else res+=(mx-ara[i]);
        sum+=ara[i];
    }
    segtree[node] = {mx,sum,res};
    //cout<<l<<" "<<r<<" "<<mx<<" "<<sum<<endl;
}

pii walk(int node,int l,int r,int mx){

    if( l == r ){
        if( ara[l] >= mx ) return {0,ara[l]};
        else return {mx-ara[l],mx};
    }

    int mid = (l+r)/2;
    if( segtree[node].mx<=mx ){
        return { mx*(r-l+1)-segtree[node].sum,mx };
    }
    if( segtree[node*2].mx >= mx ){
        int rightc = segtree[node].res - segtree[node*2].res;
        return {walk(node*2,l,mid,mx).first+rightc,segtree[node].mx};
    }else{
        auto ret = walk(node*2+1,mid+1,r,mx);
        return { ret.first + mx*(mid-l+1) - segtree[node*2].sum, segtree[node].mx};
    }

}

pii query(int node,int l,int r,int L,int R,int mx){
    if( l>R or r<L ) return {0,0};
    if(l>=L and r<=R){
        auto ret = walk(node,l,r,mx);
        //cout<<l<<" "<<r<<" "<<ret.first<<" "<<ret.second<<endl;
        return ret;
    }
    int mid = (l+r)/2;
    pii retL = query(node*2,l,mid,L,R,mx);
    pii retR = query(node*2+1,mid+1,r,L,R,retL.second);
    //cout<<l<<" "<<r<<" > "<<retL.first+retR.first<<" "<<retR.second<<endl;
    return {retL.first+retR.first,retR.second};

}


void solve(){
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>ara[i];
    build(1,1,n);
    while(q--){
        int l,r;
        cin>>l>>r;
        cout<<query(1,1,n,l,r,0).first<<endl;
    }
}
signed main(){
    FASTIO;
    int tc=1;
    //cin>>tc;

    while(tc--) solve();
}
