#include<bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
#define endl '\n'
 
const int N = 200005;
int segtree[4*N];
int ara[N];
int lt[N], rt[N];
void build(int node, int l, int r) {
    if( l > r ) return;
    if( l == r ) {
        segtree[node] = lt[l]; 
        return;
    }
    int mid = (l+r)/2;
    build(node*2,l,mid);
    build(node*2+1,mid+1,r);
    segtree[node] = max(segtree[node*2],segtree[node*2+1]);
}

void update(int node,int l, int r, int pos) {
    if( l>r or l>pos or r<pos ) return;
    if( l == r ) {
        segtree[node] = lt[l]; 
        // cout<<"updating "<<l <<' ' << r << " "<<segtree[node]<<endl;
        return;
    }
    int mid = (l+r)/2;
    update(node*2,l,mid,pos);
    update(node*2+1,mid+1,r,pos);
    segtree[node] = max(segtree[node*2],segtree[node*2+1]);
    // cout<<"updating "<<l <<' ' << r << " "<<segtree[node]<<endl;
}

int query(int node, int l, int r, int L, int R) {
    if(l>r or l>R or r<L) return 0;
    if( l>=L and r<=R ) return segtree[node];
    int mid = (l+r)/2;
    return max(query(node*2,l,mid,L,R), 
                query(node*2+1,mid+1,r,L,R));
}
map<int,set<int>> mst;

void solve() {
    
    int n,q;
    cin >> n >> q;
    for(int i=1;i<=n;i++) 
        cin >> ara[i];
    
    for(int i=1;i<=n;i++) {
        if( mst[ara[i]].size() == 0 ) {
            lt[i] = 0;
            rt[i] = n+1;
        } else {
            int b = *mst[ara[i]].rbegin();
            lt[i] = b;
            rt[i] = n+1;
            rt[b] = i;
        }
        mst[ara[i]].insert(i);
    }
    // for(int i=1;i<=n;i++) cout<<lt[i]<<" "; cout<<endl;
    // for(int i=1;i<=n;i++) cout<<rt[i]<<" "; cout<<endl;
    build(1,1,n);
    while(q--){
        int t,a,b;
        cin>>t>>a>>b;
        if( t == 1) {
            if(ara[a] == b) continue;
            mst[ara[a]].erase(a);
            ara[a] = b;
            rt[lt[a]] = rt[a];
            lt[rt[a]] = lt[a];
            update(1,1,n,rt[a]);

            auto pos = mst[b].upper_bound(a);
            if( mst[b].size() == 0 ) {
                lt[a] = 0;
                rt[a] = n+1;
            } else {
                if ( pos != mst[b].end() ) {
                    int p = *pos;
                    rt[a] = p;
                    lt[a] = lt[p];
                    rt[lt[a]] = a;
                    lt[p] = a;
                } else {
                    pos--;
                    int p = *pos;
                    lt[a] = p;
                    rt[a] = rt[p];
                    lt[rt[a]] = a;
                    rt[p] = a;
                }
            }
            mst[ara[a]].insert(a);
            // for(int i=1;i<=n;i++) cout<<lt[i]<<" "; cout<<endl;
            // for(int i=1;i<=n;i++) cout<<rt[i]<<" "; cout<<endl;
            update(1,1,n,a);
            update(1,1,n,rt[a]);
        }else{
            int mx = query(1,1,n,a,b);
            // cout<<mx<<endl;
            if( mx>=a ) cout<<"NO\n";
            else cout<<"YES\n";
        }
    }
}
 
int main(){
    FASTIO;
    solve();
 
}