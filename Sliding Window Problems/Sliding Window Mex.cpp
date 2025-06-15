#include<bits/stdc++.h>
using namespace std;
 
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
#define endl '\n'
 
const int MAXN = 200005;
 
 
map<int, int> frequency;
set<int> missing_numbers;
 
void init() {
    for (int i = 0; i < MAXN; i++)
        missing_numbers.insert(i);
}
 
int get() {
    return *missing_numbers.begin();
}
 
void add(int val) {
    if ( val >= MAXN ) return;
    ++frequency[val];
    missing_numbers.erase(val);
}
 
void remove(int val) {
    if ( val >= MAXN ) return;
    if (--frequency[val] == 0)
        missing_numbers.insert(val);
}
 
 
 
void solve() {
 
    int n, k;
    cin >> n >> k;
    vector<int> ara(n);
    for(int i=0;i<n;i++) cin>>ara[i];
    init();
    for(int i=0;i<k;i++) add(ara[i]);
    cout << get() << " ";
    for(int i=k;i<n;i++) {
        add(ara[i]);
        remove(ara[i-k]);
        cout << get() << " ";
    }
}
int main(){
    FASTIO;
 
    solve();
}
