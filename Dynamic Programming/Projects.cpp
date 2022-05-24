#include<bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define F first
#define S second
#define ll long long
struct Project{
    int s,e,r;
};

bool comp(Project A,Project B){
    if(A.e!=B.e) return A.e<B.e;
    return A.s<B.s;
}

int main(){
    int n;
    cin>>n;
    Project pro[n];
    for(int i=0;i<n;i++){
        int a,b,c;
        cin>>a>>b>>c;
        pro[i] = {a,b,c};
    }
    sort(pro,pro+n,comp);

    int st[n],en[n];
    for(int i=0;i<n;i++){
        st[i] = pro[i].s;
        en[i] = pro[i].e;

    }

    ll mx = 0;
    ll profit[n] = {0};
    ll maxProfit[n] = {0};
    for(int i=0;i<n;i++){
        auto pos = lower_bound(en,en+n,st[i])-en;
       // cout<<pro[i].s<<" "<<pro[i].e<<" "<<pos<<endl;
        if( pos == 0 ) profit[i] = pro[i].r;
        else profit[i] = pro[i].r+maxProfit[pos-1];

        if(i) maxProfit[i] = max(maxProfit[i-1],profit[i]);
        else maxProfit[0] = profit[0];
    }
    cout<<maxProfit[n-1]<<endl;
}
