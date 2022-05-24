#include<bits/stdc++.h>
using namespace std;
#define INF 2147483647
#define INFL 9223372036854775807
#define pii pair<int,int>
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define ll long long
#define ull unsigned long long
#define M 1000000007
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
#define take(x) scanf("%d",&x)
#define DE(x) printf("\ndebug %d\n",x);
#define vout(x) for(int i=0;i<x.size();i++) printf("%d ",x[i]);
#define pie acos(-1)
#define MOD 998244353

// solution to https://codeforces.com/gym/100551/problem/A

/* Here we will be asked to
    Add an edge to the graph
    Delete an edge from the graph
    Count the number of connected components in the graph
*/

/*
    look at the add query
    here we store the life cycle of the query.
    from birth to death.

    if a node is alive till end. we end it at q
*/
struct dsu_save {
    int v, rnkv, u, rnku;

    dsu_save() {}

    dsu_save(int _v, int _rnkv, int _u, int _rnku)
        : v(_v), rnkv(_rnkv), u(_u), rnku(_rnku) {}
};

struct dsu_with_rollbacks {
    vector<int> p, rnk;
    int comps;
    stack<dsu_save> op;

    dsu_with_rollbacks() {}

    dsu_with_rollbacks(int n) {
        p.resize(n);
        rnk.resize(n);
        for (int i = 0; i < n; i++) {
            p[i] = i;
            rnk[i] = 0;
        }
        comps = n;
    }

    int find_set(int v) {
        return (v == p[v]) ? v : find_set(p[v]);
    }

    bool unite(int v, int u) {
        v = find_set(v);
        u = find_set(u);
        if (v == u)
            return false;
        comps--;
        if (rnk[v] > rnk[u])
            swap(v, u);
        op.push(dsu_save(v, rnk[v], u, rnk[u]));
        p[v] = u;
        if (rnk[u] == rnk[v])
            rnk[u]++;
        return true;
    }

    void rollback() {
        if (op.empty())
            return;
        dsu_save x = op.top();
        op.pop();
        comps++;
        p[x.v] = x.v;
        rnk[x.v] = x.rnkv;
        p[x.u] = x.u;
        rnk[x.u] = x.rnku;
    }
};

struct query {
    int v, u;
    bool united;
    query(int _v, int _u) : v(_v), u(_u) {
    }
};

struct QueryTree {
    vector<vector<query>> t;
    dsu_with_rollbacks dsu;
    int T;

    QueryTree() {}

    QueryTree(int _T, int n) : T(_T) {
        dsu = dsu_with_rollbacks(n);
        t.resize(4 * T + 4);
    }

    void add_to_tree(int v, int l, int r, int ul, int ur, query& q) {
        if (ul > ur)
            return;
        if (l == ul && r == ur) {
            t[v].push_back(q);
            return;
        }
        int mid = (l + r) / 2;
        add_to_tree(2 * v, l, mid, ul, min(ur, mid), q);
        add_to_tree(2 * v + 1, mid + 1, r, max(ul, mid + 1), ur, q);
    }

    void add_query(query q, int l, int r) {
        add_to_tree(1, 0, T - 1, l, r, q);
    }

    void dfs(int v, int l, int r, vector<int>& ans) {
        for (query& q : t[v]) {
            q.united = dsu.unite(q.v, q.u);
        }
        if (l == r)
            ans[l] = dsu.comps;
        else {
            int mid = (l + r) / 2;
            dfs(2 * v, l, mid, ans);
            dfs(2 * v + 1, mid + 1, r, ans);
        }
        for (query q : t[v]) {
            if (q.united)
                dsu.rollback();
        }
    }

    vector<int> solve() {
        vector<int> ans(T);
        dfs(1, 0, T - 1, ans);
        return ans;
    }
};

int main(){
    int n,m,q,a,b;
    scanf("%d %d %d",&n,&m,&q);
    QueryTree qt(m+q+1,n);
    bool isaquery[q+m+1];
    map< pii,int> e;
    for(int i=1;i<=m;i++){
        isaquery[i] = false;
        scanf("%d %d",&a,&b);
        a--;b--;
        if( a>b ) swap(a,b);
        e[mp(a,b)] = i; // marking the start of an edge

    }
    isaquery[m] = true;
    for(int i=m+1;i<=m+q;i++){
        int t;
        cin>>t;
        if( t == 1 ){
            scanf("%d %d",&a,&b);
            a--;b--;
            if( a>b ) swap(a,b);
            e[mp(a,b)] = i; // marking the start of an edge
        } else {
            // here the node got destroyed right? so it was alive for e[{a,b}] to i-1
            scanf("%d %d",&a,&b);
            a--;b--;
            if( a>b ) swap(a,b);
            qt.add_query( query(a,b),e[mp(a,b)],i-1 );
            e.erase(mp(a,b)); // deleting the occurance of this
        }
        isaquery[i] = true;
    }
    // so now we have handled all the created and deleted nodes.
    // so all that lefts are nodes who remained alive for all the time
    for( auto it = e.begin();it!=e.end();++it ){
        qt.add_query( query( it->F.F,it->F.S ),it->S,m+q ); // remember we stored e[{a,b}] = position. so starts at pos and ends at q or the last time (always was)
    }
    vector<int> res = qt.solve();
    for(int i=1;i<=m+q;i++){
        if(isaquery[i])
        {
            printf("%d\n",res[i]);
        }
    }

    return 0;
}
