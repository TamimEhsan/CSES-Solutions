#include<bits/stdc++.h>
using namespace std;
#define INF 2047483647
#define INFL 9223372036854775807
#define ll long long
#define pii pair<ll,ll>
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

int main(){
    int n;
    cin>>n;
    pair<pii,int> para[n];
    for(int i=0;i<n;i++){
        cin>>para[i].F.F>>para[i].F.S;
        para[i].S = i;
    }
    sort(para,para+n);
    set<pii> s;
    int room = 1;
    int rooms[n];
    rooms[ para[0].S ] = 1;
    s.insert({para[0].F.S,1});
    for(int i=1;i<n;i++){
        auto it = s.lower_bound({para[i].F.F,0});
        if( it == s.begin() ){
            rooms[para[i].S] = ++room;
            s.insert({ para[i].F.S,room });
        }else{
            it--;
            int r = it->S;
            s.erase(it);
            s.insert({ para[i].F.S,r });
            rooms[para[i].S] = r;
        }
    }
    cout<<room<<endl;
    for(int i=0;i<n;i++) cout<<rooms[i]<<" ";
}
