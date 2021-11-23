#include "bits/stdc++.h"
using namespace std;
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define ll long long


const int N = 2e5+10;
const int D = 19;
const int S = (1<<D);

int n, q, v[N];
vector<int> adj[N];
pair<pii,pii> queries[N];
int sz[N], p[N], dep[N],MO[N];
int euler[N], tp[N];

//<<<<<<<<<<MO>>>>>>>>>>>>>>>\\



int BLOCK = 500;
int cnt[N];
int res = 0;
void add(int n){

    if( cnt[n] == 0 ) res++;
    cnt[n]++;
}
void rem(int n){
    cnt[n]--;
    if( cnt[n] == 0 ) res--;
}
//<<<<<<<<<<MO Ends>>>>>>>>>>>>>>>\\


int ct = 1;
int dfs(int cur, int par) {
    euler[cur] = ct++;
    sz[cur] = 1;
    p[cur] = par;
    //update(euler[cur], v[cur]);  //< We assign the values against the euler id, so we can create segment trees on that
    for(int chi : adj[cur]) {
        if(chi == par) continue;
        dep[chi] = dep[cur] + 1;
        p[chi] = cur;
        sz[cur] += dfs(chi, cur);
    }
    return sz[cur];
}


void mapp(int n,int ara[]){
    int ara2[n+1];
    for(int i=1;i<=n;i++) ara2[i] = ara[i];
    sort(ara2+1,ara2+n+1);
    map<int,int> keys;
    for(int i=1;i<=n;i++) {
        keys[ ara2[i] ] = i+1;

    }
    for(int i=1;i<=n;i++)  ara[i] = keys[ ara[i] ];

}

int main() {

    scanf("%d",&n);
    for(int i=1; i<=n; i++) scanf("%d", &v[i]);  //< Property on nodes
    mapp(n,v);
    for(int i=2; i<=n; i++) {
        int a, b;
        cin>>a>>b;//scanf("%d%d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1,-1);
    int mx = 0;
    for(int i=1;i<=n;i++){
        MO[ euler[i] ] = v[i];
        mx = max( mx,MO[euler[i]] );
    }
    int q = n;
     // start,end,index, ans
    for(int i=0;i<q;i++){
        queries[i] = {{euler[i+1],euler[i+1]+sz[i+1]-1},{i,0}};
    }

    sort(queries,queries+q,[](pair<pii,pii> A,pair<pii,pii> B){
         return A.F.F/BLOCK == B.F.F/BLOCK ? A.F.S<B.F.S: A.F.F<B.F.F;
         });

    int l_it =2,r_it = 1;
    for( int i=0;i<q;i++ ){

        int L = queries[i].F.F;
        int R = queries[i].F.S;
        while( r_it<R ) add( MO[++r_it] );
        while( l_it>L ) add( MO[ --l_it ] );
        while( r_it>R ) rem( MO[r_it--] );
        while( l_it<L ) rem( MO[l_it++] );
        queries[i].S.S = res;

    }

    sort( queries,queries+q,[](pair<pii,pii> A,pair<pii,pii> B){
         return A.S.F<B.S.F;
         });
    for(int i=0;i<q;i++){
        printf("%d ",queries[i].S.S);
    }
}

// https://cses.fi/problemset/task/2134/
