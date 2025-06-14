#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

struct Mex {
    int mex = 0;
    set<int> elements;

    void add(int x) {
        if ( x < mex ) return;
        if ( elements.find(x) != elements.end() ) return;

        elements.insert(x);
        if ( x != mex ) return;

        while (*elements.begin() == mex) {
            elements.erase(elements.begin());
            mex++;
        }
    }
    
};

Mex mexes[100][100];

void solve() {
    int n;
    cin >> n;
    int mex[n][n];

    for(int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {

            int mex = mexes[i][j].mex;
            cout << mex << " ";
            for(int k = 0; k < n; k++) {
                mexes[i][k].add(mex);
                mexes[k][j].add(mex);
            }
        }
        cout << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
    
    return 0;
}