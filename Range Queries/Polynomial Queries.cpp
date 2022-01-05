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
//#define M 1000000007
#define M 998244353
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
#define take(x) scanf("%d",&x)
#define DE(x) printf("\ndebug %d\n",x);
#define vout(x) for(int i=0;i<x.size();i++) printf("%d ",x[i]);
#define pie acos(-1)
#define MOD 998244353


struct Node{
    ll a = 0;
    ll d = 0;
};
const int N = 2000007;
ll ara[N],segtree[4*N];
Node lazy[4*N];
void build(int pos,int l,int r){
    if( l == r ){
        segtree[pos] = ara[l];
        return;
    }
    int mid = (l+r)/2;
    build(pos*2,l,mid);
    build(pos*2+1,mid+1,r);
    segtree[pos] =  segtree[pos*2]+segtree[pos*2+1] ;
}

void lazyUpdate(int pos,int l,int r){
    if( lazy[pos].d ){
        segtree[pos]+=  (r-l+1)*(2*lazy[pos].a+(r-l)*lazy[pos].d)/2;
        if( l!=r ){
            int mid = (l+r)/2;
            lazy[pos*2].a+=lazy[pos].a;
            lazy[pos*2+1].a+=lazy[pos].a+(mid-l+1)*lazy[pos].d;
            lazy[pos*2].d+=lazy[pos].d;
            lazy[pos*2+1].d+=lazy[pos].d;
        }
        lazy[pos] = {0,0};
    }
}

void update(int pos,int l,int r,int L,int R,ll val){
    lazyUpdate(pos,l,r);
    if( l>r  ) return;
    if( l> R or r<L ) return;
    if( l>=L and r<=R ){
        lazy[pos].a+=val+l-L;
        lazy[pos].d++;
        lazyUpdate(pos,l,r);
        return;
    }
    int mid = (l+r)/2;
    update(pos*2,l,mid,L,R,val);
    update(pos*2+1,mid+1,r,L,R,val);
    segtree[pos] = segtree[pos*2+1]+ segtree[pos*2] ;
}

ll query(int pos,int l, int r,int L,int R){
    lazyUpdate(pos,l,r);
    if( l>r  ) return 0;
    if( l> R or r<L ) return 0;
    if( l>=L and r<=R ) return segtree[pos];
    int mid = (l+r)/2;
    ll val1 = query(pos*2,l,mid,L,R);
    ll val2 = query(pos*2+1,mid+1,r,L,R);
    return val1+val2;
}

int main(){
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++)
        cin>>ara[i];
    build(1,1,n);
    while(q--){
        int t;
        cin>>t;
        if( t == 1 ){
            int a,b;
            cin>>a>>b;
            update(1,1,n,a,b,1);
        }else{
            int a,b;
            cin>>a>>b;
            cout<<query(1,1,n,a,b)<<endl;
        }
    }
}


