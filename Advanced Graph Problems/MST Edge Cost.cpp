#include "bits/stdc++.h"
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
#define endl '\n'

#define pii pair<int,int>
#define pb push_back
#define mp make_pair
#define F first
#define S second

/*
Heavy light decomposition divides the tree into logn paths
Each path only moves downward ( or upward )
So, for querying on any property of the nodes (or paths) from a to b
we can query the properties of path from a to LCA(a,b) and from b to LCA(a,b) and merge them
We create seperate segment tree for each path.
Here actually an array of euler path is taken on nodes. So we assign the property of the node
to the euler id of the node and create segment tree with that. And as for a path the euler path id
is increasing so, if we can somehow breakdown the problem where we can use the property on some
segment tree we can solve the problem.
Here, some properties can be minimum, maximum value of nodes, sum of values of nodes, xor, etc etc

to use property on edges add new intermediate nodes and add property on that
for use case see https://lightoj.com/submission/2684185
*/

const int N = 3e5+5;
const int D = 19;
const int S = (1<<D);

int n, q, v[N];
vector<int> adj[N];

int sz[N], p[N], dep[N];
int st[S], id[N], tp[N];

void update(int idx, int val) {
	st[idx += n] = val;
	for (idx /= 2; idx; idx /= 2)
		st[idx] = max(st[2 * idx], st[2 * idx + 1]);
}

int query(int lo, int hi) {
	int ra = 0, rb = 0;  //<< Don't forget to pre initialize the starting value
	for (lo += n, hi += n + 1; lo < hi; lo /= 2, hi /= 2) {
		if (lo & 1)
			ra = max(ra, st[lo++]);
		if (hi & 1)
			rb = max(rb, st[--hi]);
	}
	return max(ra, rb);
}

int dfs_sz(int cur, int par) {
	sz[cur] = 1;
	p[cur] = par;
	for(int chi : adj[cur]) {
		if(chi == par) continue;
		dep[chi] = dep[cur] + 1;
		p[chi] = cur;
		sz[cur] += dfs_sz(chi, cur);
	}
	return sz[cur];
}

int ct = 1;

void dfs_hld(int cur, int par, int top) {
	id[cur] = ct++;
	tp[cur] = top;
	update(id[cur], v[cur]);  //< We update the property against the euler id
	int h_chi = -1, h_sz = -1;
	for(int chi : adj[cur]) {
		if(chi == par) continue;
		if(sz[chi] > h_sz) {
			h_sz = sz[chi];
			h_chi = chi;
		}
	}
	if(h_chi == -1) return;
	dfs_hld(h_chi, cur, top);
	for(int chi : adj[cur]) {
		if(chi == par || chi == h_chi) continue;
		dfs_hld(chi, cur, chi);
	}
}

int path(int x, int y){
	int ret = 0;
	while(tp[x] != tp[y]){
		if(dep[tp[x]] < dep[tp[y]])swap(x,y);
		ret = max(ret, query(id[tp[x]],id[x]));
		x = p[tp[x]];
	}
	if(dep[x] > dep[y])swap(x,y);
	ret = max(ret, query(id[x],id[y]));
	return ret;
}

struct Edge {
    int u, v, w, id;
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
    int m;
    cin >> n >> m;
    Edge edges[m];
    for (int i = 0; i < m; i++) {
        int uu, vv, w;
        cin >> uu >> vv >> w;
        edges[i] = {uu, vv, w, i};
    }
    Dsu(n);
    sort(edges, edges + m);
    long long mst_cost = 0;
    for (int i = 0; i < m; i++) {
        int uu = edges[i].u;
        int vv = edges[i].v;
        int w = edges[i].w;
        if (Find(uu) != Find(vv)) {
            Union(uu, vv);
            
            int x = n+i+1; 
            adj[uu].pb(x);
            adj[x].pb(uu);
            adj[vv].pb(x);
            adj[x].pb(vv);

            v[x] = w; 
            mst_cost += w;
        }
    }

    sort(edges, edges + m, [](const Edge& a, const Edge& b) {
        return a.id < b.id;
    });

    n += m; //<< New nodes added for edges
    dfs_sz(1, 1);
    dfs_hld(1, 1, 1);
    for(int i = 0; i < m; i++) {
        int uu = edges[i].u;
        int vv = edges[i].v;
        int w = edges[i].w;
        int mx = path(uu, vv); 
        cout << mst_cost - mx + w << " ";  
    }
}

int main() {
    FASTIO;
	solve();
}
