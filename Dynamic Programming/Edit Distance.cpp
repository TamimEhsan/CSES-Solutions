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

const int N = 5005;
int edit[N][N];
int main(){
    string s,t;
    cin>>s>>t;
    s = '#'+s;
    t = '#'+t;
    int n = s.size();
    int m = t.size();
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i==0 and j==0) ;
            else if( i == 0 ) edit[i][j] = edit[i][j-1]+1;
            else if( j == 0 ) edit[i][j] = edit[i-1][j]+1;
            else if( s[i] == t[j] ) edit[i][j] = edit[i-1][j-1];
            else edit[i][j] = min( {edit[i-1][j-1],edit[i][j-1],edit[i-1][j]} )+1;
        }
    }
    cout<<edit[n][m];
}




