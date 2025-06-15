#include "bits/stdc++.h"
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
#define endl '\n'

#define pii pair<int,int>
#define pb push_back
#define mp make_pair
#define F first
#define S second


const int N = 1e5+5;

struct Edge {
    int u, v, w, id, x;
    bool operator<(const Edge& other) const {
        return w < other.w;
    }
};

int parent[N];
int rnk[N];
void Dsu(int n){
    for(int i=0;i<=n;i++) {
        parent[i] = i;
        rnk[i] = 0;
    }

}
int Find(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = Find(parent[v]);
}

void Union(int a, int b) {
    a = Find(a);
    b = Find(b);
    if (a != b) {
        if (rnk[a] < rnk[b])
            swap(a, b);
        parent[b] = a;
        if (rnk[a] == rnk[b])
            rnk[a]++;
    }
}
void solve() {
    int n, m;
    cin >> n >> m;
    Edge edges[m];
    for (int i = 0; i < m; i++) {
        int uu, vv, w;
        cin >> uu >> vv >> w;
        edges[i] = {uu, vv, w, i, 0};
    }
    Dsu(n);
    sort(edges, edges + m);
    int l = 0, r = 0;
    while(r < m) {
        if ( edges[r].w != edges[l].w ) {
            for(int i = l; i < r; i++) {
                int uu = edges[i].u;
                int vv = edges[i].v;
                if (Find(uu) != Find(vv)) {
                    edges[i].x = 1; // Mark this edge as part of the MST
                }
            }
            for(int i = l; i < r; i++) {
                int uu = edges[i].u;
                int vv = edges[i].v;
                if (Find(uu) != Find(vv)) {
                    Union(uu, vv);
                }
            }
            l = r;
        }
        r++;
    }

    for(int i = l; i < r; i++) {
        int uu = edges[i].u;
        int vv = edges[i].v;
        if (Find(uu) != Find(vv)) {
            edges[i].x = 1; // Mark this edge as part of the MST
        }
    }

    for(int i = l; i < r; i++) {
        int uu = edges[i].u;
        int vv = edges[i].v;
        if (Find(uu) != Find(vv)) {
            Union(uu, vv);
        }
    }

    sort(edges, edges + m, [](const Edge& a, const Edge& b) {
        return a.id < b.id;
    });

    for(int i = 0; i < m; i++) {
        int uu = edges[i].u;
        int vv = edges[i].v;
        if( edges[i].x ) {
            cout << "YES" << endl; 
        } else {
            cout << "NO" << endl; 
        }
    }
}

int main() {
    FASTIO;
	solve();
}

