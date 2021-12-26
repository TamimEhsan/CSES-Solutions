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
const int N = 2e5+5;

int ara[N];
ll segtree[4*N];

int sz;
void build(int index=0,int l=0,int r = sz-1){
    if( r<l ) return;
    if( l == r ) {
        segtree[index] = ara[l];
        return;
    }
    int mid = (l+r)/2;
    build(index*2+1,l,mid);
    build(index*2+2,mid+1,r);
    segtree[index] = segtree[index*2+1]^segtree[index*2+2] ;
}


void update(int val,int pos,int index=0,int l=0,int r=sz-1){
    if( r<l ) return;

    if( l == r ) {
        segtree[index] = val;
        return;
    }
    int mid = (l+r)/2;
    if( pos<=mid ) update(val,pos,index*2+1,l,mid);
    else update(val,pos,index*2+2,mid+1,r);
    segtree[index] = segtree[index*2+1]^segtree[index*2+2] ;
}

ll query(int L,int R,int index = 0,int l = 0,int r = sz-1){
    if( r<l ) return 0;
    if( l>=L and r<=R ) return segtree[index];
    else if( r<L or l>R ) return 0;
    int mid = (l+r)/2;
    return query(L,R,index*2+1,l,mid)^query(L,R,index*2+2,mid+1,r) ;
}
int main(){
    int n,q;
    cin>>n>>q;
    sz = n;
    for(int i=0;i<n;i++){
        cin>>ara[i];
    }
    build();
    while(q--){
        int l,r;
        cin>>l>>r;
        cout<<query(l-1,r-1)<<endl;
    }

}
