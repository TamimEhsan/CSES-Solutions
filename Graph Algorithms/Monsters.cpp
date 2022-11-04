#include<bits/stdc++.h>
using namespace std;
#define INF 2047483647
#define INFL 9223372036854775807
#define ll long long
#define pii pair<ll,ll>
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define ull unsigned long long
#define M 1000000007
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
#define take(x) scanf("%d",&x)
#define DE(x) printf("\ndebug %d\n",x);
#define vout(x) for(int i=0;i<x.size();i++) printf("%d ",x[i]);
#define pie acos(-1)
#define MOD 998244353
#define ld long double

#define inf 10000000

const int N = 1005;
int n,m;
string grid[N];
int dis[N][N];
int dis2[N][N];
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
void bfs(){
    queue<pii>q;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if( grid[i][j] == 'M' ){
                dis[i][j] = 0;
                q.push({i,j});
            }
        }
    }

    while(!q.empty()){
        auto [ux,uy] = q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int vx = ux+dx[i];
            int vy = uy+dy[i];
            if( vx<0 or vx>=n or vy<0 or vy>=m or grid[vx][vy] == '#' or dis[vx][vy]<=dis[ux][uy]+1 ) continue;
            dis[vx][vy] = dis[ux][uy]+1;
            q.push({vx,vy});
        }
    }
}

string dir = "DURL";

void print(int x,int y){
    string path;
    while(grid[x][y]!='A'){
        for(int i=0;i<4;i++){
            int px = x+dx[i];
            int py = y+dy[i];
            if( px<0 or px>=n or py<0 or py>=m or grid[px][py] == '#' ) continue;
            if( dis2[px][py] == dis2[x][y]-1 ){
                x = px;
                y = py;
                path+=dir[i];
                break;
            }
        }
    }
    cout<<"YES\n"<<path.size()<<endl;
    reverse(path.begin(),path.end());
    cout<<path<<endl;
}
void bfs2(int x,int y){

    queue<pii>q;
    dis2[x][y] = 0;
    q.push({x,y});
    while(!q.empty()){
        auto [ux,uy] = q.front();
        if( ux == n-1 or uy == m-1 or ux==0 or uy==0 ){
            print(ux,uy);
            return;
        }
        q.pop();
        for(int i=0;i<4;i++){
            int vx = ux+dx[i];
            int vy = uy+dy[i];
            if( vx<0 or vx>=n or vy<0 or vy>=m or grid[vx][vy] == '#' or dis2[vx][vy]!=inf or dis[vx][vy]<=dis2[ux][uy]+1 ) continue;
            dis2[vx][vy] = dis2[ux][uy]+1;
            q.push({vx,vy});
        }
    }
    cout<<"NO";
}

void solve(){
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            dis[i][j] = dis2[i][j] = inf;
    cin>>n>>m;
    for(int i=0;i<n;i++) cin>>grid[i];

    bfs();

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if( grid[i][j] == 'A' )
                bfs2(i,j);
        }
    }


}
int main(){
    FASTIO;
    int tc=1;
    //cin>>tc;
    //cout<<fixed<<setprecision(8);
    for(int t=1;t<=tc;t++){
      //  cout<<"Case "<<t<<": ";
        solve();

    }
}
