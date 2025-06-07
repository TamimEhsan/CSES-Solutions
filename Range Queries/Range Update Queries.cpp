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
 
 
const int MAX = 1e9+5;
const int N = 2000007;
ll ara[N],segtree[4*N],lazy[4*N];
// max Segtree with lazy updates
// will find maximum of value in a range ,
void build(int pos,int l,int r){
    if( l == r ){
        segtree[pos] = ara[l];
        return;
    }
    int mid = (l+r)/2;
    build(pos*2,l,mid);
    build(pos*2+1,mid+1,r);
    segtree[pos] = max( segtree[pos*2],segtree[pos*2+1] );
}
 
void lazyUpdate(int pos,int l,int r){
    if( lazy[pos] ){
        segtree[pos]+=lazy[pos];
        if( l!=r ){
            lazy[pos*2]+=lazy[pos];
            lazy[pos*2+1]+=lazy[pos];
        }
        lazy[pos] = 0;
    }
}
 
void update(int pos,int l,int r,int L,int R,int val){
    lazyUpdate(pos,l,r);
    if( l>r  ) return;
    if( l> R or r<L ) return;
    if( l>=L and r<=R ){
        lazy[pos]+=val;
        lazyUpdate(pos,l,r);
        return;
    }
    int mid = (l+r)/2;
    update(pos*2,l,mid,L,R,val);
    update(pos*2+1,mid+1,r,L,R,val);
    segtree[pos] = max( segtree[pos*2+1], segtree[pos*2] );
}
 
ll query(int pos,int l, int r,int L,int R){
    lazyUpdate(pos,l,r);
    if( l>r  ) return 0;
    if( l> R or r<L ) return 0;
    if( l>=L and r<=R ) return segtree[pos];
    int mid = (l+r)/2;
    ll val1 = query(pos*2,l,mid,L,R);
    ll val2 = query(pos*2+1,mid+1,r,L,R);
    return max(val1,val2);
}
 
int main(){
    int n,q;
    cin>>n>>q;
 
    for(int i=1;i<=n;i++){
        cin>>ara[i];
    }
    build(1,1,n);
    while(q--){
        int t;
        cin>>t;
        if( t == 1 ){
            int a,b,u;
            cin>>a>>b>>u;
            update(1,1,n,a,b,u);
        }else{
            int k;
            cin>>k;
            cout<<query(1,1,n,k,k)<<endl;
        }
    }
 
}