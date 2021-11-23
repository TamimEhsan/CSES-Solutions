#include "bits/stdc++.h"
using namespace std;
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define ll long long
 
 
//<<<<<<<<<<Segment Tree>>>>>>>>>>>>>>>\\
 
 
const int N = 2e5+5;
const int D = 19;
const int S = (1<<D);
 
int n, q, v[N];
vector<int> adj[N];
 
int sz[N], p[N], dep[N];
ll st[S], euler[N], tp[N];
 
void update(int idx, int val) {
	st[idx += n] = val;
	for (idx /= 2; idx; idx /= 2)
		st[idx] = st[2 * idx]+ st[2 * idx + 1];
}
 
ll query(int lo, int hi) {
	ll ra = 0, rb = 0;  //<< Don't forget to pre initialize the starting value
	for (lo += n, hi += n + 1; lo < hi; lo /= 2, hi /= 2) {
		if (lo & 1)
			ra = ra+ st[lo++];
		if (hi & 1)
			rb = rb+ st[--hi];
	}
	return ra+rb;
}
 
//<<<<<<<<<<Segment Tree Ends>>>>>>>>>>>>>>>\\
 
 
int ct = 1;
int dfs(int cur, int par) {
    euler[cur] = ct++;
    sz[cur] = 1;
    p[cur] = par;
    update(euler[cur], v[cur]);  //< We assign the values against the euler id, so we can create segment trees on that
    for(int chi : adj[cur]) {
        if(chi == par) continue;
        dep[chi] = dep[cur] + 1;
        p[chi] = cur;
        sz[cur] += dfs(chi, cur);
    }
    return sz[cur];
}
 
 
int main() {
 
    scanf("%d%d",&n,&q);
    for(int i=1; i<=n; i++) scanf("%d", &v[i]);  //< Property on nodes
    for(int i=2; i<=n; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1,-1);
    while(q--) {
        int t;
        cin>>t;
        if(t == 1) {
            int s, x;
            scanf("%d%d", &s, &x);
            v[s] = x;
            update(euler[s],x);  //< We update the property against the euler id
        } else {
            int a;
            scanf("%d", &a);
            ll res = query(euler[a],euler[a] + sz[a] - 1);   //< Here we search between the euler id
                                                            //and euler id + substree size, cuase thats how euler tour works
            printf("%lld\n", res);
        }
    }
}
 