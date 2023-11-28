#include<bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define endl '\n'

const int N = 8;
int grid[N][N];

int dx[] = {2,-2,2,-2,1,1,-1,-1};
int dy[] = {1,1,-1,-1,2,-2,2,-2};


int check_count(int x,int y){
    int cnt = 0;
    for(int i=0;i<8;i++){
        int vx = x+dx[i];
        int vy = y+dy[i];
        if( vx>=0 and vx<8 and vy>=0 and vy<8 and grid[vx][vy] == 0 ) cnt++;
    }
    return cnt;
}
bool recurse(int ux,int uy,int step){
    grid[ux][uy] = step;
    if( step == 64 ) return true;
    int ind = -1;
    vector<pii> moves;
    for(int i=0;i<8;i++){
        int vx = ux+dx[i];
        int vy = uy+dy[i];
        if( vx<0 or vy<0 or vx>=8 or vy>=8  ) continue;
        if( grid[vx][vy] ) continue;

        int ret = check_count(vx,vy);
        moves.push_back({ret,i});
    }
    if( moves.size() == 0 ) {
        grid[ux][uy] = 0;
        return false;
    }
    sort(moves.begin(),moves.end());
    for(auto [del,ind]:moves){
        bool ret = recurse(ux+dx[ind],uy+dy[ind],step+1);
        if( ret ) return true;
    }
    grid[ux][uy] = 0;
    return false;
}

void solve(){

    int x,y;
    cin>>y>>x;
    x--;y--;
    recurse(x,y,1);
    for(int i=0;i<8;i++) {
        for(int j=0;j<8;j++) cout<<grid[i][j]<<" ";
        cout<<endl;
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc=1;
    //cin>>tc;

    for(int i=0;i<tc;i++){
        solve();
    }
}

