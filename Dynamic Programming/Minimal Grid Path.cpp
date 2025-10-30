#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
#define endl '\n'

const int N = 3006;
string grid[N];
int n;
int vis[N][N];
string result;

int dx[] = {1,0};
int dy[] = {0,1};

void bfs() {
    queue<pii> fronts;
    queue<pii> tempFronts;
    result += grid[0][0];
    fronts.push({0,0});
    while(result.size() < 2*n -1) {
        char best = 'Z' + 1;
        while(fronts.size()) {
            auto [ux, uy] = fronts.front(); fronts.pop();
            for(int i=0;i<2;i++) {
                int vx = ux + dx[i];
                int vy = uy + dy[i];
                if ( vx >= n or vy >= n or grid[vx][vy] > best or vis[vx][vy] ) continue;
                vis[vx][vy] = 1;
                if ( grid[vx][vy] < best ) {
                    best = grid[vx][vy];
                    while(tempFronts.size()) tempFronts.pop();
                }
                tempFronts.push({vx,vy});
            }
        }
        result += best;
        while(tempFronts.size()) {
           fronts.push(tempFronts.front());
           tempFronts.pop();
        }
    }
}

void solve() {
    cin>>n;
    for(int i=0;i<n;i++) cin>>grid[i];
    bfs();
    cout<<result;
}

signed main() {
    FASTIO;
    int tc = 1;
    // cin>>tc;

    for(int i=1;i<=tc;i++) {
        solve();
    }
}
