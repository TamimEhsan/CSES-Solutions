#include "bits/stdc++.h"
using namespace std;
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define INF 1000000000

const int N = 2000007;
vector<int> adj[N];


int dp[2][N];
void dfs(int u,int par){
    dp[0][u] = 0;
    dp[1][u] = -INF;
    for(int v:adj[u]){
        if( v == par ) continue;
        dfs(v,u);
        dp[0][u] += (max(dp[1][v], dp[0][v]));
        dp[1][u] = max( dp[1][u], min(dp[0][v]-dp[1][v], 0  )  );
    }
    dp[1][u]+=dp[0][u];
	dp[1][u]++;
}

int main() {
    int n;
	scanf("%d", &n);
	for(int i=2; i<=n; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		a--;b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(0,-1);
	int ans = max(dp[0][0], dp[1][0]);
	cout << ans << endl;
}

