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
pii parent[1005][1005];
int dir[1005][1005];
char dd[] = {'D','U','R','L'};
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
        cin>>s[i];

    pii st,en;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if( s[i][j] == 'B' ) st = {i,j};
            if( s[i][j] == 'A' ) en = {i,j};
        }
    }

    queue<pii>q;

    q.push(st);
    vis[st.F][st.S] = 1;
    while(!q.empty()){
        auto u = q.front();
        q.pop();
        for(int k=0;k<4;k++){
            int vx = u.F+dx[k];
            int vy = u.S+dy[k];

            if( vx>=0 and vy>=0 and vx<n and vy<m and s[vx][vy]!='#' and vis[vx][vy] == 0  ){
                parent[vx][vy] = u;
                dir[vx][vy] = k;
                vis[vx][vy] = 1;
                q.push({vx,vy});
            }
        }
    }

    if( vis[en.F][en.S] == 0 ){
        cout<<"NO";
        return 0;
    }
    cout<<"YES"<<endl;
    int steps = 0;
   // cout<<en.F<<" "<<en.S<<"    "<<st.F<<" "<<st.S<<endl;
    int x = en.F,y = en.S;
    while( x!= st.F or y!=st.S){
        //cout<<x<<" "<<y<<endl;
        steps++;
        auto v = parent[x][y];
        x = v.F;
        y = v.S;

    }
    cout<<steps<<endl;
    x = en.F,y = en.S;
    while( x!= st.F or y!=st.S){
        cout<<dd[ dir[x][y] ];

        auto v = parent[x][y];
        x = v.F;
        y = v.S;

    }




}
