#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
#define endl '\n'

void solve() {
    int n;
    cin >> n;
    int ara[n],bara[n],cara[n];
    for(int i=0;i<n;i++) cin >> ara[i];
    for(int i=0;i<n;i++) cin >> bara[i];

    queue<int> q;
    for(int i=1;i<=n;i++) q.push(i);

    int it = 0;
    for(;it<n-4;it++) {
        int a = q.front(); q.pop();
        if(ara[it] != a and bara[it]!=a) {
            cara[it] = a;
            continue;
        }
        int b = q.front(); q.pop();
        if(ara[it] != a and bara[it]!=a) {
            cara[it] = b;
            q.push(a);
            continue;
        }
        int c = q.front(); q.pop();
        cara[it] = c;
        q.push(a);
        q.push(b);
        
    }

    vector<int> v;
    while(q.size() > 0) {
        v.push_back(q.front()); q.pop();
    }
    sort(v.begin(),v.end());

    bool found = false;
    do{
        bool pos = true;
        for(int i=0;i<v.size();i++) {
            if(ara[it+i] == v[i] or bara[it+i] == v[i]) {
                pos = false;
            }
        }
        if(!pos) continue;
        found = true;
        for(int i=0;i<v.size();i++) cara[it+i] = v[i];
        break;
    } while(next_permutation(v.begin(),v.end()));
    if (!found) {
        cout<<"IMPOSSIBLE";
        return;
    }
    for(int i=0;i<n;i++) cout<<cara[i]<<" ";

}

int main() {
    FASTIO;
    int tc = 1;
    // cin>>tc;

    for(int i=1;i<=tc;i++) {
        solve();
    }
}