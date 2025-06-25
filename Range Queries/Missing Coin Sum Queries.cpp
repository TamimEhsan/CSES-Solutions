#include<bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
#define endl '\n'

const int N = 200005;

int segtree[2*N][30];
long long cumsum[N][30];

inline void comb(int ret[], int left[], int right[]){
    for(int i=0;i<30;i++) ret[i] = min(left[i],right[i]);
}

void query(int l, int r, int ret[]) {
    for(int i=0;i<30;i++) ret[i] = 2e9;
    for( l+=N,r+=N;l<=r;l/=2,r/=2) {
        if (l % 2 == 1) comb(ret, ret, segtree[l++]);
        if (r % 2 == 0) comb(ret, segtree[r--], ret);
    }
}

void answer() {
    int a,b;
    cin>>a>>b;
    int res[30];
    query(a,b,res);
    long long sum = 0, ans = -1;
    for(int i=0;i<30;i++) {
        if( sum+1<res[i] and sum+1 < (1 << (i + 1))  ){
            cout<<sum+1<<endl;
            return;
        }
        sum+= cumsum[b][i]-cumsum[a-1][i];
    }
    cout<<sum+1<<endl;
}

void solve() {
    int n, q;
    cin >> n >> q;
    memset(segtree, 0x3f, sizeof(segtree));

    for(int i=1;i<=n;i++){
        int x;
        cin >> x;
        int g = log2(x);
        segtree[i+N][g] = x;cumsum[i][g] = x;
    }
    for(int i=1;i<=n;i++) for(int j=0;j<30;j++) cumsum[i][j] += cumsum[i-1][j];

    for(int i=N-1;i;i--) comb(segtree[i], segtree[i*2], segtree[i*2+1]);

    while(q--) {
        answer();
    }
}

int main() {
    FASTIO; 
   
    solve();

    return 0;
}