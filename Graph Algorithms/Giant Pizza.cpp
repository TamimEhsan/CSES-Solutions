#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>


const int N = 200005;

int n;
vector<int> adj[N], adj_t[N];
int used[N];
vector<int> order;
int comp[N];
int assignment[N];

void dfs1(int v) {
    used[v] = true;
    for (int u : adj[v]) {
        if (!used[u])
            dfs1(u);
    }
    order.push_back(v);
}

void dfs2(int v, int cl) {
    comp[v] = cl;
    for (int u : adj_t[v]) {
        if (comp[u] == -1)
            dfs2(u, cl);
    }
}

bool solve_2SAT() {
    order.clear();

    for(int i=0;i<=n;i++) used[i] = false;
    for (int i = 0; i < n; ++i) {
        if (!used[i])
            dfs1(i);
    }
    for(int i=0;i<=n;i++) comp[i] = -1;

    for (int i = 0, j = 0; i < n; ++i) {
        int v = order[n - i - 1];
        if (comp[v] == -1)
            dfs2(v, j++);
    }

    for(int i=0;i<n/2;i++) assignment[i] = false;
    for (int i = 0; i < n; i += 2) {
        if (comp[i] == comp[i + 1])
            return false;
        assignment[i / 2] = comp[i] > comp[i + 1];
    }
    return true;
}

void add_disjunction(int a, bool na, int b, bool nb) {
    // na and nb signify whether a and b are to be negated
    a = 2*a ^ na;
    b = 2*b ^ nb;
    int neg_a = a ^ 1;
    int neg_b = b ^ 1;
    adj[neg_a].push_back(b);
    adj[neg_b].push_back(a);
    adj_t[b].push_back(neg_a);
    adj_t[a].push_back(neg_b);
}
void solve(){
    int m;
    cin>>m>>n;
    n = 2*n;
    for(int i=0;i<m;i++){
        string c1,c2;
        int a,b;
        cin>>c1>>a>>c2>>b;
        a--;b--;
        bool ca,cb;
        ca = c1 == "+";
        cb = c2 == "+";
        add_disjunction(a,!ca,b,!cb);
    }
    bool ret = solve_2SAT();
    if( !ret ){
        cout<<"IMPOSSIBLE"<<endl;
        return;
    }
    for(int i=0;i<n/2;i++) cout<<(assignment[i]?'+':'-')<<" ";

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc=1;
    //cin>>tc;

    for(int i=0;i<tc;i++){
        solve();
    }
}

