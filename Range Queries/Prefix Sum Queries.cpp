#include "bits/stdc++.h"
using namespace std;
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
#define ll long long


const int N = 200005;
int n,q,ara[N];

struct Node{
    ll sum;
    ll pref;
    friend Node operator+(const Node &A, const Node &B){
        return {A.sum+B.sum, max(A.pref,A.sum+B.pref) };
    }
};
Node segtree[4*N];
void build(int index = 1,int l = 1,int r = n){
    if( l>r ) return;
    if( l == r ){
        segtree[index] = {ara[l],max(0,ara[l])};
        return;
    }
    int mid = (l+r)/2;
    build(index*2,l,mid);
    build(index*2+1,mid+1,r);
    segtree[index] = segtree[index*2] + segtree[index*2+1];
}

void update(int index,int pos,int l,int r,int x){
    if( r<pos or l>pos ) return;
    if( l == r ){
        segtree[index] = {x,x};
        return;
    }
    int mid = (l+r)/2;
    update(index*2,pos,l,mid,x);
    update(index*2+1,pos,mid+1,r,x);
    segtree[index] = segtree[index*2] + segtree[index*2+1];
}

Node query(int index,int L,int R,int l,int r){
    if( r<L or l>R ) return {0,0};
    if( l>=L and r<=R ) return segtree[index];

    int mid = (l+r)/2;
    Node q1 = query(index*2,L,R,l,mid);
    Node q2 = query(index*2+1,L,R,mid+1,r);
    return q1+q2;
}

int main(){

    cin>>n>>q;
    for(int i=1;i<=n;i++)
        cin>>ara[i];
    build();
    while(q--){
        int t;
        cin>>t;
        if( t == 1 ){
            int k,u;
            cin>>k>>u;
            update(1,k,1,n,u);
        }else{
            int a,b;
            cin>>a>>b;
            cout<<query(1,a,b,1,n).pref<<endl;
        }
    }
}
/*

*/
