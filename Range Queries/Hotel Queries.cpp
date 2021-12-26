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
int segtree[4*N];

int sz;

pii comp(pii A,pii B){
    if( A.F>B.F ) return A;
    if( B.F>A.F ) return B;
    if( A.S<B.S ) return A;
    return B;
}
void build(int index=0,int l=0,int r = sz-1){
    if( r<l ) return;
    if( l == r ) {
        segtree[index] = ara[l];
        return;
    }
    int mid = (l+r)/2;
    build(index*2+1,l,mid);
    build(index*2+2,mid+1,r);
    segtree[index] = max(segtree[index*2+1],segtree[index*2+2]) ;
}


void update(int val,int pos,int index=0,int l=0,int r=sz-1){
    if( r<l ) return;

    if( l == r ) {
        segtree[index] -= val;
        return;
    }
    int mid = (l+r)/2;
    if( pos<=mid ) update(val,pos,index*2+1,l,mid);
    else update(val,pos,index*2+2,mid+1,r);
    segtree[index] = max(segtree[index*2+1],segtree[index*2+2]) ;
}

int query(int L,int R,int qSz,int index = 0,int l = 0,int r = sz-1){
    if( r<l ) return -1;
    if( segtree[index]<qSz ) return -1;
    if( l == r ) return l;
    else if( r<L or l>R ) return -1;
    int mid = (l+r)/2;

    if( segtree[index*2+1]>=qSz ) return query(L,R,qSz,index*2+1,l,mid);
    if( segtree[index*2+2]>=qSz ) return query(L,R,qSz,index*2+2,mid+1,r);
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
        int a;
        cin>>a;
        int res = query(0,n-1,a);
        cout<<res+1<<" ";
        if(res!=-1)update(a,res);
    }

}
