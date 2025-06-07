#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
 
const int N = 200005;
struct cell{
    int mx = 0;
    int lz=0;
    int rz=0;
    int lo=0;
    int ro=0;
    int sz = 0;
 
 
 
};
 
cell segtree[N*4];
string s;
 
cell Merge(cell A,cell B){
    int mx,lz,rz,lo,ro;
    if( A.lz == A.sz ) lz = A.lz+B.lz;
    else lz = A.lz;
 
    if( B.rz == B.sz ) rz = B.rz+A.rz;
    else rz = B.rz;
 
    if( A.lo == A.sz ) lo = A.lo+B.lo;
    else lo = A.lo;
 
    if( B.ro == B.sz ) ro = B.ro+A.ro;
    else ro = B.ro;
 
    mx = max({A.mx,B.mx,A.rz+B.lz,A.ro+B.lo});
    return {mx,lz,rz,lo,ro,A.sz+B.sz};
 
}
void build(int node,int l,int r){
    if( l == r ){
        if( s[l] == '0' ) segtree[node] = {1,1,1,0,0,1};
        else segtree[node] = {1,0,0,1,1,1};
        return;
    }
 
    int mid = (l+r)/2;
    build(node*2+1,l,mid);
    build(node*2+2,mid+1,r);
    segtree[node] = Merge(segtree[node*2+1],segtree[node*2+2]);
 
}
 
void update(int node,int l,int r,int pos){
if( l>pos or r<pos ) return;
    if( l == r ){
        if( segtree[node].lz == 1 )
            segtree[node] = {1,0,0,1,1,1};
        else
            segtree[node] = {1,1,1,0,0,1};
       // cout<<"updated in range "<<l<<" "<<r<<" "<<segtree[node].mx<<" "<<segtree[node].lz<<" "<<segtree[node].rz<<" "<<segtree[node].lo<<" "<<segtree[node].ro<<endl;
        return;
    }
 
    int mid = (l+r)/2;
    update(node*2+1,l,mid,pos);
    update(node*2+2,mid+1,r,pos);
    segtree[node] = Merge(segtree[node*2+1],segtree[node*2+2]);
   // cout<<"updated in range "<<l<<" "<<r<<" "<<segtree[node].mx<<" "<<segtree[node].lz<<" "<<segtree[node].rz<<" "<<segtree[node].lo<<" "<<segtree[node].ro<<endl;
}
 
int main(){
    cin>>s;
    int n = s.size();
    build(1,0,n-1);
 
   // cout<<segtree[1].mx<<endl;
 
    int q;
    cin>>q;
    while(q--){
        int p;
        cin>>p;
        p--;
        update(1,0,n-1,p);
        cout<<segtree[1].mx<<" ";
    }
}