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

const int N = 2000007;

vector<pii> startt[N];
vector<pii> endd[N];
int lazy[4*N];
pii segtree[4*N];



pii merge(pii l,pii r){
    if( l.first<r.first ) return l;
    else if( r.first<l.first ) return r;
    else return {l.first,l.second+r.second};
}

void build(int pos,int l,int r){
    if( l>r ) return;
    if( l == r ){
        segtree[pos] = {0,1};
        return;
    }
    int mid = (l+r)/2;
    build(pos*2,l,mid);
    build(pos*2+1,mid+1,r);
    segtree[pos] = merge( segtree[pos*2+1], segtree[pos*2] );
}

void lazyUpdate(int pos,int l,int r){
    if( lazy[pos] ){
        segtree[pos].first+=lazy[pos];
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

    segtree[pos] = merge( segtree[pos*2+1], segtree[pos*2] );
}

pii query(int pos,int l, int r,int L,int R){
    lazyUpdate(pos,l,r);
    if( l>r  ) return {10,0};
    if( l> R or r<L ) return {10,0};
    if( l>=L and r<=R ) return segtree[pos];
    int mid = (l+r)/2;
    auto val1 = query(pos*2,l,mid,L,R);
    auto val2 = query(pos*2+1,mid+1,r,L,R);
    return merge(val1,val2);
}

int offset = 1000001;
int main(){
    FASTIO;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        x1+=offset;
        x2+=offset;
        y1+=offset;
        y2+=offset;
        startt[y1].push_back({x1,x2});
        endd[y2].push_back({x1,x2});
    }
    ll res = 0;
    build(1,1,N-1);
    for(int i=1;i<N;i++){
        for(auto [l,r]:endd[i]) update(1,1,N-1,l+1,r,-1);

        for(auto [l,r]:startt[i]) update(1,1,N-1,l+1,r,1);

        // calculating the number of empty cells
        pii ret = query(1,1,N-1,1,N-1);
        if( ret.first == 0 ) res+=ret.second;
    }
    // rectangle area = total area - empty area
    cout<<1LL*2000006*2000006-res;
}
/*
1
1 1 2 2
*/
