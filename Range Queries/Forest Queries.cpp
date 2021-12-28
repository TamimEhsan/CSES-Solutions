#include<bits/stdc++.h>
using namespace std;
//#define INF 2147483647
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


const int N = 1005;
int forestSum[N][N];

int main(){
    int n,q;
    cin>>n>>q;
    string forest[n];
    for(int i=0;i<n;i++)
        cin>>forest[i];

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            forestSum[i][j] = forestSum[i-1][j]+forestSum[i][j-1]-forestSum[i-1][j-1];
            if( forest[i-1][j-1] == '*' )
                forestSum[i][j]++;

        }
    }
    while(q--){
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        cout<<forestSum[x2][y2]-forestSum[x2][y1-1]-forestSum[x1-1][y2] + forestSum[x1-1][y1-1]<<endl;
    }
}
