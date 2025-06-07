#include<bits/stdc++.h>
using namespace std;
#define INF 2047483647
#define INFL 9223372036854775807
#define ll long long
#define pii pair<int,int>
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


const int N = 1005;
pii segtree[N];
string grid[N];
int n,m;
pii update(int node,int l,int r,int pos,int val){
    if( r<pos or l>pos ) return {-1,-1};
    if( l == r and l == pos ){
        return segtree[node] = {val,l};
    }
    int mid = (l+r)/2;
    return segtree[node] = max(update(node*2,l,mid,pos,val),update(node*2+1,mid+1,r,pos,val));

}

pii query(int node,int l,int r,int L,int R){
    if( l>=L and r<=R ) return segtree[node];
    if( r<L or l>R ) return {-1,-1};
    int mid = (l+r)/2;
    return max( query(node*2,l,mid,L,R),query(node*2+1,mid+1,r,L,R) );
}

int getMax(int l,int r,int level){
    if( l>r ) return -1;
    auto ret = query(1,1,m,l,r);
    int res = (level-ret.first)*(r-l+1);
    return max({ res, getMax(l,ret.second-1,level),getMax(ret.second+1,r,level) });
}

int main(){
    FASTIO;
    cin>>n>>m;
    for(int i=0;i<n;i++)
        cin>>grid[i];
    for(int j=0;j<m;j++)
        update(1,1,m,j+1,0);

    int mx = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            if( grid[i][j] == '*' ){
                update(1,1,m,j+1,i+1);
            }
        mx = max(mx,getMax(1,m,i+1));
    }
    cout<<mx;

}
