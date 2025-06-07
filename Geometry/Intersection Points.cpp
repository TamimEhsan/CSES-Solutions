#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll,ll>
#define F first9
#define S second


const int N = 200005;
struct Range{
    int x1,y1,x2,y2;
};
Range ranges[N];

vector<int> startt[N];
vector<int> endd[N];
vector<pii> queryy[N];

int segtree[4*N];

void update(int node,int l,int r,int pos,int val){
    if( l>pos or r<pos or l>r ) return;
    if( l == pos and r == pos ){
        segtree[node]+=val;
        return;
    }
    int mid = (l+r)/2;
    update(node*2,l,mid,pos,val);
    update(node*2+1,mid+1,r,pos,val);
    segtree[node] = segtree[node*2]+segtree[node*2+1];
}

int query(int node,int l,int r,int L,int R){
    if( l>R or r<L or l>r ) return 0;
    if( l>=L and r<=R ) return segtree[node];
    int mid = (l+r)/2;
    return query(node*2,l,mid,L,R) + query(node*2+1,mid+1,r,L,R);
}
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++) {
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        ranges[i] = {a,b,c,d};
    }
    vector<int> v;
    for(int i=0;i<n;i++) {
        v.push_back(ranges[i].x1);
        v.push_back(ranges[i].x2);
    }
    sort(v.begin(),v.end());
    v.erase( unique( v.begin(),v.end() ) , v.end() );

    for(int i=0;i<n;i++){
        ranges[i].x1 = lower_bound(v.begin(),v.end(),ranges[i].x1) - v.begin() + 1;
        ranges[i].x2 = lower_bound(v.begin(),v.end(),ranges[i].x2) - v.begin() + 1;
    }
    v.clear();
    for(int i=0;i<n;i++) {
        v.push_back(ranges[i].y1);
        v.push_back(ranges[i].y2);
    }
    sort(v.begin(),v.end());
    v.erase( unique( v.begin(),v.end() ) , v.end() );

    for(int i=0;i<n;i++){
        ranges[i].y1 = lower_bound(v.begin(),v.end(),ranges[i].y1) - v.begin() + 1;
        ranges[i].y2 = lower_bound(v.begin(),v.end(),ranges[i].y2) - v.begin() + 1;
    }
    v.clear();
    //for(int i=0;i<n;i++) cout<<ranges[i].x1<<" "<<ranges[i].y1<<" "<<ranges[i].x2<<" "<<ranges[i].y2<<endl;

    for(int i=0;i<n;i++){
        int x1 = ranges[i].x1;
        int x2 = ranges[i].x2;
        int y1 = ranges[i].y1;
        int y2 = ranges[i].y2;
        if( x1 == x2 ){
            startt[y1].push_back(x1);
            endd[y2].push_back(x1);
        }else{
            queryy[y1].push_back({x1,x2});
        }
    }

    ll res = 0;
    for(int i=1;i<N;i++){
        for(auto x:startt[i]) update(1,1,N-1,x,1);
        for(auto [l,r]:queryy[i]){
            int ret = query(1,1,N-1,l,r);
            res+=ret;
        }
        for(auto x:endd[i]) update(1,1,N-1,x,-1);
    }
    cout<<res;
}
