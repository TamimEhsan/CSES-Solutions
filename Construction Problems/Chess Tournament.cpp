#include<bits/stdc++.h>
using namespace std;
#define INF 2047483647
#define INFL 9223372036854775807
#define ll long long
#define pii pair<int,int>
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define ull unsigned long long
#define M 1000000007
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
#define take(x) scanf("%d",&x)
#define DE(x) printf("\ndebug %d\n",x);
#define vout(x) for(int i=0;i<x.size();i++) printf("%d ",x[i]);
#define pie acos(-1)
#define MOD 998244353
#define ld long double


void solve(){
    int n;
    cin>>n;
    set<pii> s;
    for(int i=1;i<=n;i++){
        int a;
        cin>>a;
        if(a) s.insert({a,i});
    }
    vector<pii> res;
    while(s.size()>=2){
        auto [u,itu] = *s.begin();


        s.erase({u,itu});
        vector<pii> store;
        while(u and s.size()){
            auto [v,itv] = *s.rbegin();
            s.erase({v,itv});
            u--;v--;
            res.push_back({itu,itv});
            store.push_back({v,itv});
        }
        if( u ){
            cout<<"IMPOSSIBLE";
            return;
        }
        for(auto [v,itv]:store){
            if( v ) s.insert({v,itv});
        }
    }
    if( s.size() ){
        cout<<"IMPOSSIBLE";
        return;
    }
    cout<<res.size()<<endl;
    for(auto [u,v]:res) cout<<u<<" "<<v<<endl;
}
int main(){
    FASTIO;
    int tc=1;
   //cin>>tc;
    //cout<<fixed<<setprecision(8);
    for(int t=1;t<=tc;t++){
       // cout<<"Case "<<t<<": ";
        solve();
    }

}
