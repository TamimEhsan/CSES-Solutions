#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define F first
#define S second
#define ll long long
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
#include <bits/stdc++.h>
using namespace std;

#define mset0(x) memset(x,0,sizeof(x))
const int maxN = 1005 ;
const int maxM = 1005 ;
struct HopcroftKarp {
    int vis[maxN], level[maxN], ml[maxN], mr[maxM];
    vector<int> edge[maxN]; // constructing edges for left part only
    void init(int n) {
        for (int i = 1; i <= n; ++i) edge[i].clear();
    }
    void add(int u, int v) {
        edge[u].push_back(v);
    }
    bool dfs(int u) {
        vis[u] = true;
        for (vector<int>::iterator it = edge[u].begin(); it != edge[u].end(); ++it) {
            int v = mr[*it];
            if (v == -1 || (!vis[v] && level[u] < level[v] && dfs(v))) {
                ml[u] = *it;
                mr[*it] = u;
                return true;
            }
        }
        return false;
    }
    int matching(int n) { // n for left
        mset0(vis);
        mset0(level);
        memset(ml, -1,sizeof(ml));
        memset(mr, -1,sizeof(mr));
        for (int match = 0;;) {
            queue<int> que;
            for (int i = 1; i <= n; ++i) {
                if (ml[i] == -1) {
                    level[i] = 0;
                    que.push(i);
                } else level[i] = -1;
            }
            while (!que.empty()) {
                int u = que.front();
                que.pop();
                for (vector<int>::iterator it = edge[u].begin(); it != edge[u].end(); ++it) {
                    int v = mr[*it];
                    if (v != -1 && level[v] < 0) {
                        level[v] = level[u] + 1;
                        que.push(v);
                    }
                }
            }
            for (int i = 1; i <= n; ++i) vis[i] = false;
            int d = 0;
            for (int i = 1; i <= n; ++i) if (ml[i] == -1 && dfs(i)) ++d;
            if (d == 0) return match;
            match += d;
        }
    }
};

void solve(){
    int n,m,k;
    cin>>n>>m>>k;
    HopcroftKarp hk;
    hk.init(n+m+1);
    for(int i=0;i<k;i++){
        int u,v;
        cin>>u>>v;
        hk.add(u,v+n);
    }
    cout<<hk.matching(n)<<endl;
    for(int i=1;i<=n;i++){
        if( hk.ml[i]!=-1 )cout<<i<<" "<<hk.ml[i]-n<<endl;
    }
}

int main(){
    FASTIO;
    solve();
}
