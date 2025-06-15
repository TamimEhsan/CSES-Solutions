#include<bits/stdc++.h>
using namespace std;
 
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
#define endl '\n'
 
const int MAXN = 200005;
 
int segtree[MAXN * 4];
 
long long inversion = 0;
 
long long get() {
    return inversion;
}
 
void update(int val, int diff, int node = 1, int l = 1, int r = MAXN) {
    if ( l > r or l > val or r < val ) return;
    if ( l == r) {
        segtree[node] += diff;
        return;
    }
    int mid = (l+r)/2;
    update(val, diff, node*2, l, mid);
    update(val, diff, node*2+1, mid+1, r);
    segtree[node] = segtree[node*2] + segtree[node*2+1];
}
 
int query(int L, int R, int node = 1, int l = 1, int r = MAXN) {
    if( r < L or l > R or l > R ) return 0;
    if( l >= L and r <= R ) return segtree[node];
    int mid = (l+r)/2;
    return query(L,R,node*2,l,mid) + query(L,R,node*2+1,mid+1,r);
}
 
void add(int val) {
    update(val, 1);
    inversion += query(val+1, MAXN);
}
 
void remove(int val) {
    update(val, -1);
    inversion -= query(0, val-1);
}
 
void compress(int ara[], int n){
    set<int> st;
    for(int i=0;i<n;i++) st.insert(ara[i]);
    map<int,int> mp;
    int cnt = 0;
    for(auto s:st) mp[s] = ++cnt;
    for(int i=0;i<n;i++) ara[i] = mp[ ara[i] ];
}
 
void solve() {
 
    int n, k;
    cin >> n >> k;
    int ara[n];
    for(int i=0;i<n;i++) cin>>ara[i];
    compress(ara,n);
    for(int i=0;i<k;i++) add(ara[i]);
    cout << get() << " ";
    for(int i=k;i<n;i++) {
        add(ara[i]);
        remove(ara[i-k]);
        cout << get() << " ";
    }
}
int main(){
    FASTIO;
 
    solve();
}
 
