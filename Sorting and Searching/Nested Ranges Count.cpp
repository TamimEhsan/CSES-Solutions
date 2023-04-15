#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
#define endl '\n'


struct FenwickTree {
    vector<int> bit;  // binary indexed tree
    int n;

    FenwickTree(int n) {
        this->n = n;
        bit.assign(n, 0);
    }

    FenwickTree(vector<int> a) : FenwickTree(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }

    int sum(int r) {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
    void update(int idx,int val){
        int prevVal = sum(idx,idx);
        int delta = val - prevVal;
        add(idx,delta);
    }
};

struct Cell{
    int val;
    int pos;
    int isStart;
    int index;
};

struct Original{
    int l;
    int r;
    int index;
};
bool cmp(Cell a,Cell b){
    if( a.val != b.val ) return a.val<b.val;
    if( a.isStart and b.isStart ) return a.pos<b.pos;
    if( !a.isStart and !b.isStart ) return a.pos>b.pos;
    return !a.isStart; // < might need to change this
}
bool cmp2(Original a,Original b){
    if( a.l != b.l ) return a.l<b.l;
    return a.r>b.r;
}


void solve(){

    int n;
    cin>>n;
    FenwickTree ft(n+1);
    Original para[n];
    int contains[n]={0};
    int contained[n]={0};
    for(int i=0;i<n;i++) {
        int l,r;
        cin>>l>>r;
        para[i] = {l,r,i};
    }
    sort(para,para+n,cmp2);
    Cell ranges[2*n];
    for(int i=0;i<n;i++){
        ranges[i*2] = {para[i].l,i,1,para[i].index};
        ranges[i*2+1] = {para[i].r,i,0,para[i].index};
    }
    sort(ranges,ranges+2*n,cmp);
    for(auto [val,pos,isStart,index]:ranges){
        if( isStart ) {
          //  cout<<"started "<<index<<" "<<pos<<" "<<val<<endl;
            continue;
        }
        //cout<<"ended "<<index<<" "<<pos<<" "<<val<<endl;
        contains[index] = ft.sum(pos+1,n);
        contained[index] = pos-ft.sum(0,pos-1);
        ft.update(pos,1);
    }
    for(int i=0;i<n;i++) cout<<contains[i]<<" "; cout<<endl;
    for(int i=0;i<n;i++) cout<<contained[i]<<" "; cout<<endl;
}





int main(){

    FASTIO;
    int tc=1;
    //cin>>tc;
    for(int t=1;t<=tc;t++){
       // cout<<"Case "<<t<<": ";
        solve();
    }
}

/*
2
5
11100
00011
5
00111
11000
*/
