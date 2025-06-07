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
 
const int N = 105;
 
void mult(int aa[][N], int bb[][N], int cc[][N], int n) {
    int i, j, k;
 
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++) {
            int c = 0;
 
            for (k = 0; k < n; k++)
                c = (c + (long long) aa[i][k] * bb[k][j]) % M;
            cc[i][j] = c;
        }
}
 
void power(int aa[][N], int pp[][N], int tt[][N], int n, int k) {
    if (k == 0) {
        int i, j;
 
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
                pp[i][j] = i == j;
        return;
    }
    if (k % 2 == 0) {
        power(aa, tt, pp, n, k / 2);
        mult(tt, tt, pp, n);
    } else {
        power(aa, pp, tt, n, k / 2);
        mult(pp, pp, tt, n);
        mult(tt, aa, pp, n);
    }
}
 
int main(){
    int aa[N][N], pp[N][N], tt[N][N];
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) aa[i][j] = pp[i][j] = tt[i][j] = 0;
    int a,b;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        a--;b--;
        aa[a][b] ++;
    }
    power(aa,pp,tt,n,k);
    cout<<pp[0][n-1];
}