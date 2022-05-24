// https://cses.fi/problemset/task/2072/
#include "bits/stdc++.h"
using namespace std;
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
#define F first
#define S second

typedef long long LL;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef struct item * pitem;
struct item {
    int prior, value, cnt;
    LL sum;
    bool rev;

    item(int value):prior(rng()), value(value) {
        cnt = 0;
        rev = 0;
        sum = value;
        l = r = nullptr;
    }

    pitem l, r;
};

namespace Treap {
    int cnt (pitem it) {
        return it != nullptr? it->cnt : 0;
    }
    LL sum(pitem it) {
        return it != nullptr? it->sum : 0;
    }
    void upd_cnt (pitem it) {
        if (it!=nullptr) {
            it->cnt = cnt(it->l) + cnt(it->r) + 1;
            it->sum = sum(it->l) + sum(it->r) + it->value;
        }
    }
    void push (pitem it) {
        if (it != nullptr && it->rev == true) {
            it->rev = false;
            swap (it->l, it->r);
            if (it->l)  it->l->rev ^= true;
            if (it->r)  it->r->rev ^= true;
        }
    }
    void merge (pitem & t, pitem l, pitem r) {
        push (l);
        push (r);
        if (l==nullptr || r==nullptr)
            t = (l!=nullptr) ? l : r;
        else if (l->prior > r->prior)
            merge (l->r, l->r, r),  t = l;
        else
            merge (r->l, l, r->l),  t = r;
        upd_cnt (t);
    }
    void split (pitem t, pitem & l, pitem & r, int key, int add = 0) {
        if (t==nullptr) {
            l = r = nullptr;
            return;
        }
        push(t);
        int cur_key = add + cnt(t->l);

        if (key <= cur_key)
            split (t->l, l, t->l, key, add),  r = t;
        else
            split (t->r, t->r, r, key, add + 1 + cnt(t->l)),  l = t;
        upd_cnt (t);
    }
    void reverse (pitem &t, int l, int r) {
        pitem t1, t2, t3;
        split (t, t1, t2, l); //< split t into t1 and t2 at position l, thus we have [..,l] and [l+1,..]
        split (t2, t2, t3, r-l+1); //< split t2 into t2 and t3
        // so we have now 3 tree t1,t2 and t3
        assert(t2 != NULL);
        t2->rev ^= true;
        merge (t, t1, t2); // merge t1 and t2 into t
        // so now we have t and t3
        merge (t, t, t3);  // merge t and t3 into t
    }
    void cut (pitem &t, int l, int r) {
        pitem L, mid, R;
        split(t, L, mid, l );
        split(mid, mid, R, r - l+1);
        merge(t, L, R);
        merge(t, t, mid);
    }
    LL query (pitem &t, int l, int r) {
        pitem t1, t2, t3;
        split (t, t1, t2, l);
        split (t2, t2, t3, r-l+1);
        LL ans = t2->sum;
        merge (t, t1, t2);
        merge (t, t, t3);
        return ans;
    }
    void insert (pitem & t, int key, int value) {
        pitem x = new item(value);
        pitem L, R;
        split(t, L, R, key);
        merge(L, L, x);
        merge(t, L, R);
        upd_cnt(t);
    }
    int erase (pitem & t, int key) {
        assert(cnt(t) > key);
        pitem L, MID, R;
        split(t, L, MID, key);
        split(MID, MID, R, 1);
        merge(t, L, R);
        upd_cnt(t);
        int rt = MID->value;
        delete MID;
        return rt;
    }
    void output (pitem t, string &v) {
        if (t==nullptr)  return;
        push (t);
        output (t->l, v);
        v.push_back(t->value);
        output (t->r, v);
    }
    void output2 (pitem t) {
        if (t==nullptr)  return;
        push (t);
//        cout << "(";
        output2 (t->l);
        cout << (t->value) << " ";
        output2 (t->r);
//        cout << ")";
    }
}


int main(){
   // ifstream cin("test_input.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    pitem root = nullptr;
    int n,q;
    cin>>n>>q;

    string s;
    cin>>s;
    for(int i=0;i<n;i++){
        Treap::insert(root,i,s[i]);
    }

    while(q--){
        int l,r;
        cin>>l>>r;
        l--;r--;
        Treap::cut(root,l,r);
    }
    string ans;
    Treap::output(root,ans);
    cout<<ans;


}
