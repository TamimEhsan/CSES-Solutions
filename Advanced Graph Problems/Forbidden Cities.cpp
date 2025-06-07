#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=2e5;
int n, m, bccI, dt, tin[mxN], low[mxN], st[mxN], sth, c[2*mxN], d[2*mxN], anc[2*mxN][19], q;
vector<int> adj1[mxN], adj2[2*mxN];

/*
Block Cut tree
create a new node for each bi connected component

bi connected components means there is always a path between any two nodes in the component,
even after removing any node from the component

and every node that is a part of some bi connected component is connected to that node
one node can be part of multiple biconnected component

if u has more than one edge in block cut tree, it means it is part of two or more seperate
bi connected components => meaning it an articulation point

the tree now is rooted at root and is directed, but will work if it is made directed
*/

void dfs1(int u=0, int p=-1) {
	tin[u]=low[u]=++dt;
	st[sth++]=u;
	for(int v : adj1[u]) {
		if(v==p)
			continue;
		if(!tin[v]) {
			dfs1(v, u);
			if(low[v]>=tin[u]) {
				adj2[u].push_back(n+bccI);
				do {
					adj2[n+bccI].push_back(st[sth-1]);
					adj2[st[sth-1]].push_back(n+bccI);
				} while(st[--sth]^v);
				++bccI;
			}
			low[u]=min(low[u], low[v]);
		} else
			low[u]=min(low[u], tin[v]);
	}
}


void dfs2(int u=0,int par = -1) {
	for(int i=1; i<19; ++i)
		anc[u][i]=anc[anc[u][i-1]][i-1];
	c[u]+=u<n;
	for(int v : adj2[u]) {
        if( v == par ) continue;
		c[v]=c[u];
		d[v]=d[u]+1;
		anc[v][0]=u;
		dfs2(v,u);
	}
}

int lca(int u, int v) {
	if(d[u]<d[v])
		swap(u, v);
	for(int i=18; ~i; --i)
		if(d[u]-(1<<i)>=d[v])
			u=anc[u][i];
	if(u==v)
		return u;
	for(int i=18; ~i; --i) {
		if(anc[u][i]^anc[v][i]) {
			u=anc[u][i];
			v=anc[v][i];
		}
	}
	return anc[u][0];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
    int q;
	cin >> n >> m >> q;
	for(int i=0, u, v; i<m; ++i) {
		cin >> u >> v, --u, --v;
		adj1[u].push_back(v);
		adj1[v].push_back(u);
	}
	dfs1();
	dfs2();

	while(q--){
        int a,b,c;
        cin>>a>>b>>c;
        a--,b--,c--;
        int l = lca(a,b);
        if( lca(a,c) == c and lca(c,l) == l ) cout<<"NO"<<endl;
        else if( lca(b,c) == c and lca(c,l) == l ) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
	}
}


