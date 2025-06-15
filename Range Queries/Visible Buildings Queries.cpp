#include<bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
#define endl '\n'

const int MAXN=200005, LOG=20;
int bparent[MAXN][LOG];
void build_ancestor(int n){
    for(int i=1; i < LOG; i++)
        for(int j=1; j<=n; j++)
            bparent[j][i]=bparent[bparent[j][i-1]][i-1];
}


void solve() {
    int n, q;
    cin >> n >> q;
    int heights[n+2];
    
    for (int i = 1; i <= n; i++) {
        cin >> heights[i];
    }
    vector<int> monotone;
    heights[0] = INT_MAX; // Sentinel value for the last building
    monotone.push_back(0); // Start with the sentinel value
    for (int i = n; i >= 1; i--) {
        while (monotone.size() > 1 && heights[monotone.back()] <= heights[i]) {
            monotone.pop_back();
        }
        bparent[i][0] = monotone.back();
        monotone.push_back(i);
    }
    build_ancestor(n);
    while (q--) {
        int a, b;
        cin >> a >> b;
        int r = a;
        int cnt = 1;
        while ( r <= b ) {
            int i = 0;
            for(; i < LOG; i++) {
                if (bparent[r][i] == 0) break; // No more ancestors
                if (bparent[r][i] > b) break; // Stop if ancestor is out of range
            }
            if( i == 0) {
                break;
            }
            r = bparent[r][i-1]; // Move to the ancestor
            cnt += (1 << (i-1)); // Count the number of buildings visible
        }
        cout << cnt << endl;
    }
}

int main() {
    FASTIO;
    solve();
 
    return 0;
}