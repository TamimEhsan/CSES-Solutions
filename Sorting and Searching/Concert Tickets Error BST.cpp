#include<bits/stdc++.h>
using namespace std;
#define INF 2147483647
#define INFL 9223372036854775807
#define pii pair<int,int>
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define ll long long
#define ull unsigned long long
#define M 1000000007
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
#define take(x) scanf("%d",&x)
#define DE(x) printf("\ndebug %d\n",x);
#define vout(x) for(int i=0;i<x.size();i++) printf("%d ",x[i]);
#define pie acos(-1)
#define MOD 998244353

vector<ll> bst;
int sz;
void createBST(ll ara[],int L,int R,int pos){
    if( L>R ) return ;
    int mid = (L+R)/2;
    bst[pos] = ara[mid];
    createBST(ara,L,mid-1,2*pos);
    createBST(ara,mid+1,R,2*pos+1);
}
int searchTree(int pos,ll x){
    if( bst[pos] == -1) return -1;
    else if( bst[pos] > x ) return searchTree(pos*2,x);
    int mid = bst[pos];
    if( mid == x ) return mid;
    ll L = searchTree(pos*2+1,x);
    if( L == -1) return mid;
    else return L;
}
ll get(int pos){
    if( pos>=sz ) return -1;
    else return bst[pos];
}
void moveUp(int pos){
    if( pos>=sz ) return;
    if( get(pos*2) == -1 and get(pos*2+1) == -1 ) {
        bst[pos] = -1;
        return;
    }
    if( get(pos*2) == -1 ){
        bst[pos] = get(pos*2+1);
        moveUp(pos*2+1);
        return;
    }
    bst[pos] = get(pos*2);
    moveUp(pos*2);
}

void deleteVal(int pos,ll x){
    if( bst[pos] > x ){
        deleteVal(pos*2,x);
    }else if( bst[pos]<x ){
        deleteVal(pos*2+1,x);
    } else{
        moveUp(pos);
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    ll ara[n];
    sz = 4*n;
    for(int i=0;i<n;i++){
        cin>>ara[i];
    }
    sort(ara,ara+n);
    bst.resize(4*n,-1);
    createBST(ara,0,n-1,1);
    ll para[m];
    for(int i=0;i<m;i++){
        cin>>para[i];
    }
    for(int i=0;i<m;i++){
        ll val = searchTree(1,para[i]);
        cout<<val<<endl;
        if( val!=-1 ) deleteVal(1,val);
    }
}
