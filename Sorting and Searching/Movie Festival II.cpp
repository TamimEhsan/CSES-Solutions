#include<bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
//#define endl '\n'
#define int long long
int Set(int N,int pos){return N=N | (1LL<<pos);}
int reset(int N,int pos){return N= N & ~(1<<pos);}
bool check(int N,int pos){return (bool)(N & (1LL<<pos));}


const int N = 200005;
int assigned[N];

struct Cell{
    int s;
    int t;
};

bool cmp(Cell a,Cell b){
    if( a.t!=b.t ) return a.t<b.t;
    return a.s>b.s;
}

void solve(){

    int n,k;
    cin>>n>>k;
    vector<Cell> cells;
    for(int i=1;i<=n;i++){
        int s,t;
        cin>>s>>t;
        cells.push_back({s,t});

    }
    sort(cells.begin(),cells.end(),cmp);
    multiset<int> available;
    for(int i=0;i<k;i++) available.insert(0);

    int res = 0;
    for(auto [s,t]:cells){
        if( available.size() == 0 ) continue;
        auto it = available.upper_bound(s);
        if( it == available.begin() ) continue;
        it--;
        available.erase(it);
        available.insert(t);
        res++;
    }
    cout<<res;


}

signed main(){
    //FASTIO;
    int tc=1;
    //cin>>tc;
    while(tc--) solve();
}
