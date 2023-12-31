#include<bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
#define endl '\n'
#define ll long long
//#define int long long
#define pii pair<int,int>
int Set(int N,int pos){return N=N | (1LL<<pos);}
int reset(int N,int pos){return N= N & ~(1<<pos);}
bool check(int N,int pos){return (bool)(N & (1LL<<pos));}


const int N = 1000006;
const int LOG = 20;

int bparent[N][LOG];
pii segtree[4*N];
pii para[N];

void build(int node,int l,int r){

    if( l>r ) return;
    if( l == r ){
        segtree[node] = para[l];
        return;
    }
    int mid = (l+r)/2;
    build(node*2,l,mid);
    build(node*2+1,mid+1,r);
    segtree[node] = min(segtree[node*2],segtree[node*2+1]);
}

pii query(int node,int l,int r,int L,int R){
    if( l>r or l>R or r<L ) return {INT_MAX,-1};
    if( l>=L and r<=R )return segtree[node];
    int mid = (l+r)/2;
    return min( query(node*2,l,mid,L,R), query(node*2+1,mid+1,r,L,R) );
}

struct Cell{
    int start;
    int end;
};
bool cmp_cell(Cell a,Cell b){
    if( a.end!=b.end ) return a.end<b.end;
    return a.start<b.start;
}
void solve(){

    int n,q;
    cin>>n>>q;
    Cell cells[n];
    for(int i=0;i<n;i++){
        cin>>cells[i].start>>cells[i].end;
    }
    for(int i=0;i<N;i++) para[i] = {INT_MAX,n};
    cells[n] = {N-1,N-1};
    sort(cells,cells+n+1,cmp_cell);
    for(int i=n;i>=0;i--){
        para[cells[i].start] = {cells[i].end,i};
    }

    build(1,1,N-1);
    for(int i=0;i<n;i++){
        bparent[i][0] = query(1,1,N-1,cells[i].end,N-1).second;

    }
    for(int i=0;i<LOG;i++) bparent[n][i] = n;
    for(int i=1; i < LOG; i++)
        for(int j=0; j<n; j++)
            bparent[j][i]=bparent[bparent[j][i-1]][i-1];


    while(q--){
        int l,r;
        cin>>l>>r;
        pii pajn = query(1,1,N-1,l,r);

        if( pajn.first>r ) {
            cout<<0<<endl;
            continue;
        }
        int p = pajn.second;
        int res = 1;
        while(cells[p].end<=r){

            int nxt=-1;
            for(int i=0;i<LOG;i++){
                int t = bparent[p][i];
                if( cells[t].end<=r ) nxt = i;
                else break;
            }
            if( nxt == -1 ) break;
            res+= (1<<nxt);
            p = bparent[p][nxt];
        }
        cout<<res<<endl;
    }

}


signed main(){
    FASTIO;
    int tc=1;
    //cin>>tc;
    while(tc--) solve();
}

