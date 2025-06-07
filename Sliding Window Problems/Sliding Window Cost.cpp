#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define INF 2047483647
#define INFL 9223372036854775807
#define ll long long
#define pii pair<ll,ll>
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define ull unsigned long long
#define M 1000000007
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
#define take(x) scanf("%d",&x)
#define DE(x) printf("\ndebug %d\n",x);
#define vout(x) for(int i=0;i<x.size();i++) printf("%d ",x[i]);
#define pie acos(-1)
#define MOD 998244353
 
typedef tree < int,  null_type,  less < int >,  rb_tree_tag,  tree_order_statistics_node_update > o_set;
typedef tree < pair < int, int >,  null_type,  less < pair < int, int > >,  rb_tree_tag,  tree_order_statistics_node_update > o_setp;
 o_setp s;
 
 
const int N = 200005;
 
int compressed[N];
ll segtree[4*N];
 
 
 
void update(int node,int l,int r,int pos,int val){
    if( l>r  ) return;
    if( l> pos or r<pos ) return;
    if( l>=pos and r<=pos ){
        segtree[node] += val;
        return;
    }
    int mid = (l+r)/2;
    update(node*2,l,mid,pos,val);
    update(node*2+1,mid+1,r,pos,val);
    segtree[node] =  segtree[node*2+1] + segtree[node*2] ;
}
 
ll query(int pos,int l, int r,int L,int R){
    if( l>r  ) return 0;
    if( l> R or r<L ) return 0;
    if( l>=L and r<=R ) return segtree[pos];
    int mid = (l+r)/2;
    ll val1 = query(pos*2,l,mid,L,R);
    ll val2 = query(pos*2+1,mid+1,r,L,R);
    return val1+val2;
}
 
 
int main(){
    int n,k;
    cin>>n>>k;
    int ara[n];
    set<int> st;
    for(int i=0;i<n;i++) {
        cin>>ara[i];
        st.insert(ara[i]);
    }
 
    map<int,int> mp;
    int cnt =0;
    for(auto s:st){
        mp[s] = ++cnt;
        compressed[cnt] = s;
    }
    for(int i=0;i<n;i++){
        ara[i] = mp[ ara[i] ];
    }
    for(int i=0;i<k;i++){
        s.insert({ara[i],i});
        update(1,1,cnt,ara[i],compressed[ara[i]]);
    }
 
    auto ret = *s.find_by_order(k/2);
    int pos1 = s.order_of_key({ret.first,-1});
    int pos2 = s.order_of_key({ret.first,n+1});
    ll lo = pos1;
    ll hi = k-pos2;
    ll val = compressed[ret.first];
    cout<<lo*val-query(1,1,cnt,1,ret.first-1)+query(1,1,cnt,ret.first+1,cnt)-hi*val<<" ";
    //cout<<compressed[ ret.first ]<<" "<<lo<<" "<<hi<<endl;
    for(int i=k;i<n;i++){
        s.erase({ara[i-k],i-k});
        s.insert({ara[i],i});
        update(1,1,cnt,ara[i-k],-compressed[ara[i-k]]);
        update(1,1,cnt,ara[i],compressed[ara[i]]);
        auto ret = *s.find_by_order(k/2);
        int pos1 = s.order_of_key({ret.first,-1});
        int pos2 = s.order_of_key({ret.first,n+1});
 
        ll lo = pos1;
        ll hi = k-pos2;
        val = compressed[ret.first];
         cout<<lo*val-query(1,1,cnt,1,ret.first-1)+query(1,1,cnt,ret.first+1,cnt)-hi*val<<" ";
    //cout<<compressed[ ret.first ]<<" "<<lo<<" "<<hi<<endl;
 
    }
 
}
