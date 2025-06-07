#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define ll long long

vector<pair<int, int>> pruefer_decode(vector<int> const& code) {
    int n = code.size() + 2;
    vector<int> degree(n, 1);
    for (int i : code)
        degree[i]++;

    set<int> leaves;
    for (int i = 0; i < n; i++) {
        if (degree[i] == 1)
            leaves.insert(i);
    }

    vector<pair<int, int>> edges;
    for (int v : code) {
        int leaf = *leaves.begin();
        leaves.erase(leaves.begin());

        edges.emplace_back(leaf, v);
        if (--degree[v] == 1)
            leaves.insert(v);
    }
    edges.emplace_back(*leaves.begin(), n-1);
    return edges;
}


int main(){
    int n;
    cin>>n;
    vector<int> codes;
    for(int i=0;i<n-2;i++){
        int a;
        cin>>a;
        a--;
        codes.push_back(a);
    }
    for(auto  [u,v]:pruefer_decode(codes))
        cout<<u+1<<" "<<v+1<<endl;


}
