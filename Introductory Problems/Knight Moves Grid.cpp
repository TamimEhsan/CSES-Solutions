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


const int N = 1000;
int grid[N][N];
int dx[] = {1,1,-1,-1,-2,2,-2,2};
int dy[] = {-2,2,-2,2,1,1,-1,-1};

void solve() {
    int n;
    cin>>n;
    queue<pii> q;
    q.push({0,0});
    grid[0][0] = 1;
    while(q.size()){
        auto [x,y] = q.front();
        q.pop();
        for(int i=0;i<8;i++){
            int vx = x+dx[i];
            int vy = y+dy[i];
            if( vx<0 or vy<0 or vx>=n or vy>=n or grid[vx][vy] ) continue;
            grid[vx][vy] = grid[x][y] + 1;
            q.push({vx,vy});
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) cout<<grid[i][j]-1<<" ";
        cout<<endl;
    }
}
int main(){
    solve();
}
