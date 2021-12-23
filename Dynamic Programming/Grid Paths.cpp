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

const int N = 1e3+5;
int paths[N][N];
int main(){
    int n;
    cin>>n;
    string grid[n];
    for(int i=0;i<n;i++) cin>>grid[i];

    paths[0][0] = 1;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if( grid[i][j] == '*') continue;
            paths[i+1][j]+=paths[i][j];
            paths[i][j+1]+=paths[i][j];
            paths[i+1][j]%=M;
            paths[i][j+1]%=M;
        }
    }
    if( grid[0][0] == '*' or grid[n-1][n-1] == '*' ) cout<<0;
    else cout<<paths[n-1][n-1];
}

