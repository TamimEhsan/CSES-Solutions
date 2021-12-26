#include<bits/stdc++.h>
using namespace std;
//#define INF 2147483647
#define INFL 9223372036854775807
#define pii pair<int,int>
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define ll long long
#define ull unsigned long long
#define M 1000000007
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
#define take(x) scanf("%d",&x)
#define DE(x) printf("\ndebug %d\n",x);
#define vout(x) for(int i=0;i<x.size();i++) printf("%d ",x[i]);
#define pie acos(-1)
#define MOD 998244353


struct Range{
    int a;
    int b;
    int i;
    int v = 0;
};
bool comRange(const Range &A,const Range &B){
    if(A.a!=B.a) return A.a<B.a;
    return A.b>B.b;
}
bool compS(const Range &A,const Range &B){
    if(A.b!=B.b) return A.b<B.b;
    return A.a>B.a;
}

int main(){
    int n;
    cin>>n;
    set<int> sf;
    Range ranges[n];
    map<pii,int> pp;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        pp[{a,b}]++;
        ranges[i] = {a,b,i,0};
    }
    sort(ranges,ranges+n,compS);
    for(int i=0;i<n;i++){
        int a = ranges[i].a;
        auto it = sf.lower_bound(a);
        if( it!=sf.end() or pp[{ ranges[i].a,ranges[i].b} ]>1 ) ranges[i].v = 1;
        else ranges[i].v = 0;
        sf.insert(ranges[i].a);
    }
    int res[n] = {0};
    for(int i=0;i<n;i++)
        res[ ranges[i].i ] = ranges[i].v;
    for(int i=0;i<n;i++)
        cout<<res[i]<<" ";
    cout<<endl;
    sf.clear();
    sort(ranges,ranges+n,comRange);
    for(int i=0;i<n;i++){

        int b = ranges[i].b;
        auto it = sf.lower_bound(b);
        if( it!=sf.end() or pp[{ ranges[i].a,ranges[i].b} ]>1 ) ranges[i].v = 1;
        else ranges[i].v = 0;
        sf.insert(ranges[i].b);
    }
    for(int i=0;i<n;i++)
        res[ ranges[i].i ] = ranges[i].v;
    for(int i=0;i<n;i++)
        cout<<res[i]<<" ";
}

