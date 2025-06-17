#include<bits/stdc++.h>
using namespace std;

const int N = 200005;
vector<int> adj[N];
pair<int,int> dist[N][2];

void solve() {

    int n, m, k;
    cin >> n >> m >> k;

    for(int i=1;i<=n;i++) {
        dist[i][0] = {INT_MAX, INT_MAX};
        dist[i][1] = {INT_MAX, INT_MAX};
    }
    queue<int> q;
    for(int i=0;i<k;i++) {
        int x;
        cin >> x;
        dist[x][0] = {0, x};
        q.push(x);
    }

    for(int i=0;i<m;i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    while(!q.empty()) {
        int u = q.front();
        q.pop();

        for(int v : adj[u]) {
            if(dist[v][0].first > dist[u][0].first + 1) {
                dist[v][1] = dist[v][0];
                dist[v][0] = {dist[u][0].first + 1, dist[u][0].second};
                q.push(v);
            } else if(dist[v][1].first > dist[u][0].first + 1 && dist[v][0].second != dist[u][0].second) {
                dist[v][1] = {dist[u][0].first + 1, dist[u][0].second};
            }
        }
    }
    int ans[n+1];
    for(int i=1;i<=n;i++) {
        ans[i] = INT_MAX;
        if(dist[i][0].first != 0) {
            ans[i] = dist[i][0].first;
        }
    }
    for(int i=1;i<=n;i++) {
        if(dist[i][1].first == INT_MAX || dist[i][1].first == INT_MAX) continue;
        int u = dist[i][0].second;
        int v = dist[i][1].second;
        ans[u] = min(ans[u], dist[i][1].first + dist[i][0].first);
        ans[v] = min(ans[v], dist[i][1].first + dist[i][0].first);
    }

    for(int i=1;i<=n;i++) {
        if(ans[i] == INT_MAX) {
            cout << -1 << " ";
        } else {
            cout << ans[i] << " ";
        }
    }

}

int main() {
    solve();
}