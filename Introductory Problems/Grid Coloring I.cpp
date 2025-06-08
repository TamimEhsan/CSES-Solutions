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


void solve() {
    int n,m;
    cin>>n>>m;
    string grid[n];
    for(int i=0;i<n;i++)
        cin>>grid[i];

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if( (i+j)%2==0 ){
                if( grid[i][j] == 'A' ) grid[i][j] = 'B';
                else grid[i][j] = 'A';
            } else{
                if( grid[i][j] == 'C' ) grid[i][j] = 'D';
                else grid[i][j] = 'C';
            }
        }
    }
    for(int i=0;i<n;i++)
        cout<<grid[i]<<endl;
}
int main(){
    solve();
}
