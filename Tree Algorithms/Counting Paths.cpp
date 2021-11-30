#include "bits/stdc++.h"
using namespace std;
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
*/
/*
PS. There are other applications where the lca can be found within the HLD.
But I couldn't understand what was happing, so am using my LCA template here
*/



const int N = 2000007;
const int D = 19;
const int S = (1<<D);

int n, q, v[N];
vector<int> adj[N];

int sz[N], p[N], dep[N];
int id[N], tp[N];

//<<<<<<<<<<<<<<<<<<< Fenwick Tree>>>>>>>>>>>>>>>>>>>>>>\\

int bit[N];

void add(int idx, int val) {
    for (++idx; idx <= n; idx += idx & -idx)
        bit[idx] += val;
}

void range_add(int l, int r, int val) {
    add(l, val);
    add(r + 1, -val);
}

int point_query(int idx) {
    int ret = 0;
    for (++idx; idx > 0; idx -= (idx & -idx))
        ret += bit[idx];
    return ret;
}

//<<<<<<<<<<<<<<<Fenwick tree Ends>>>>>>>>>>>>>>>>>\\

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

int ct = 0; //< Also 1 indexed

void dfs_hld(int cur, int par, int top) {
	id[cur] = ct++;
	tp[cur] = top;
	//update(id[cur], v[cur]);  //< We update the property against the euler id
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


// This automatically calculates the path from a to b . No LCA is required!
void path(int x, int y){
	while(tp[x] != tp[y]){
		if(dep[tp[x]] < dep[tp[y]])swap(x,y);
        range_add(id[tp[x]],id[x],1);
		x = p[tp[x]];
	}
	if(dep[x] > dep[y])swap(x,y);
	range_add(id[x],id[y],1);
}

int main() {
	scanf("%d%d", &n, &q);
	for(int i=2; i<=n; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs_sz(1, 1);  //< 1 indexed system  ;
	dfs_hld(1, 1, 1);

	while(q--) {
		int a,b;
		scanf("%d%d", &a,&b);
        path(a, b);  //< We update the property against the euler id in path of a to b
	}
	for(int i=1;i<=n;i++)  printf("%d ",point_query(id[i]));
}

