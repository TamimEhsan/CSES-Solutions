#include "bits/stdc++.h"
using namespace std;
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define ll long long
#define M 1000000007


struct FenwickTree {
    vector<ll> bit;  // binary indexed tree
    int n;

    FenwickTree(int n) {
        this->n = n;
        bit.assign(n, 0);
    }

    FenwickTree(vector<int> a) : FenwickTree(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }

    ll sum(int r) {
        ll ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1){

            ret += bit[r];
            ret%=M;
        }
        return ret;
    }

    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
};


int main(){
   // ifstream cin("test_input.txt");
    int n;
    cin>>n;
    int ara[n];
    set<int> ss;
    for(int i=0;i<n;i++) {
        cin>>ara[i];
        ss.insert(ara[i]);
    }

    map<int,int> compress;
    int cnt = 0;
    for(auto s:ss){
        compress[s] = ++cnt;
    }
    for(int i=0;i<n;i++)
        ara[i] = compress[ ara[i] ];

    FenwickTree ft(cnt+5);
    ll res = 0;
    for(int i=0;i<n;i++){
        ll temp = ft.sum(0, ara[i]-1 );
        temp++;
        temp%=M;
        ft.add(ara[i],temp);
        res+=temp;
        res%=M;
    }
    cout<<res;



}
