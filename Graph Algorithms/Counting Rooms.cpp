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


int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

string s[1005];
int vis[1005][1005];

int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
        cin>>s[i];

    queue<pii>q;

    int rooms = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if( s[i][j] == '#' or vis[i][j] == 1 ) continue;
            rooms++;
            q.push({i,j});
            vis[i][j] =1;
            while(!q.empty()){
                auto u = q.front();
                q.pop();
                for(int k=0;k<4;k++){
                    int vx = u.F+dx[k];
                    int vy = u.S+dy[k];

                    if( vx>=0 and vy>=0 and vx<n and vy<m and s[vx][vy]!='#' and vis[vx][vy] == 0  ){
                        vis[vx][vy] = 1;
                        q.push({vx,vy});
                    }
                }
            }
        }
    }
    cout<<rooms;


}
