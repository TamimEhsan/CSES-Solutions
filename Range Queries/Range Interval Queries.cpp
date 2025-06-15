#include<bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
#define endl '\n'

const int MAXN = 100005;

int A[MAXN];
vector<int>tree[MAXN*5];

#define Left (node*2)
#define Right (node*2+1)
#define mid ((lo+hi)/2)

void build(int node, int lo, int hi){
    if(lo==hi) {tree[node].push_back(A[lo]); return;}
    build(Left,lo,mid);
    build(Right,mid+1,hi);
    merge(tree[Left].begin(),tree[Left].end(),tree[Right].begin(),tree[Right].end(),back_inserter(tree[node]));
}

// Function to count elements in the range [i, j] that are less than x
int query(int node, int lo, int hi, int i, int j, int x){
    if(i>hi || j<lo) return 0;
    if(lo>=i && hi<=j) return lower_bound(tree[node].begin(),tree[node].end(),x) - tree[node].begin();
    int p1 = query(Left,lo,mid,i,j,x);
    int p2 = query(Right,mid+1,hi,i,j,x);
    return p1+p2;
}

void solve() {
    int n,q;
    cin>>n>>q;
    for(int i=0;i<n;i++){
         cin>>A[i];
    }
    build(1,0,n-1);
    while(q--){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        a--; b--; // Convert to 0-based index
        int count = query(1, 0, n - 1, a, b, d + 1) - query(1, 0, n - 1, a, b, c);
        cout << count << endl;
    }
}

int main() {
    FASTIO;
    solve();
 
    return 0;
}