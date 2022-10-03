#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#pragma GCC optimize("O3,unroll-loops")
#define INF 2047483647
#define INFL 9223372036854775807
#define ll long long
#define pii pair<int,int>
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define ull unsigned long long
//#define M 1000000007
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
#define take(x) scanf("%d",&x)
#define DE(x) printf("\ndebug %d\n",x);
#define vout(x) for(int i=0;i<x.size();i++) printf("%d ",x[i]);
#define pie acos(-1)
#define MOD 998244353
#define infl 10000000000
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int my_rand(int l, int r){return uniform_int_distribution<int>(l,r) (rng);}

/**
Fully Generalized implementation for Monotone slope,Arbitrary query
runtime insert() O(1)
        query() O(logn)
**/
struct Line{
    long long m,c;//mx+c
    Line(){
        m=c=infl;
    }
    Line(ll m,ll c):m(m),c(c){}
    long long operator()(long long x)
    {
        return m*x+c;
    }
    bool parallel(Line l)
    {
        return m==l.m;
    }
    pair<long double,long double> intersect(Line l)//assuming not parallel
    {
        long double x,y;
        x=(long double)(l.c-c)/(m-l.m);
        y=(long double)m*x+c;
        return {x,y};
    }
};

class MonotoneCHT{
    deque<Line> Q;
    int type;
    void insertBack(Line nl)
    {
        //handle parallel line insertion,there cannot be more than one parallel line to new line currently inside Q;
        if(!Q.empty()&&Q.back().parallel(nl))
        {
            if(type<2)
            {
                if(Q.back().c>nl.c)
                    Q.pop_back();
                else
                    return;
            }
            else
            {
                if(Q.back().c<nl.c)
                    Q.pop_back();
                else
                    return;
            }
        }
        while(Q.size()>1&&Q.back().intersect(nl)<Q[Q.size()-2].intersect(nl))
            Q.pop_back();
        Q.push_back(nl);
    }
    void insertFront(Line nl)
    {
        //handle parallel line insertion,there cannot be more than one parallel line to new line currently inside Q;
        if(!Q.empty()&&Q[0].parallel(nl))
        {
            if(type<2)
            {
                if(Q[0].c>nl.c)
                    Q.pop_front();
                else
                    return;
            }
            else
            {
                if(Q[0].c<nl.c)
                    Q.pop_front();
                else
                    return;
            }
        }
        while(Q.size()>1&&Q[0].intersect(nl)>Q[1].intersect(nl))
            Q.pop_front();
        Q.push_front(nl);
    }
    pii bSearch(ll x)
    {
        if(Q.size()==1||Q[0].intersect(Q[1]).first>=x)
            return {0,0};
        int l=1,r=(int)Q.size()-1;
        while(r>l+1)
        {
            int mid=(l+r)/2;
            if(Q[mid].intersect(Q[mid-1]).first<x)
                l=mid;
            else
                r=mid;
        }
        return {l,r};
    }
public:
    //slope increasing or decreasing(not query point,query point is arbitrary),querying for maximum or minimum
    MonotoneCHT(bool increasing,bool maximum)
    {
        type=increasing;
        if(maximum)
            type|=2;
    }
    void insert(Line nl)
    {
        if(type==3||type==0)
            insertBack(nl);
        else
            insertFront(nl);
    }
    ll fastQuery(ll x)//if monotone query satisfied //not tested,although it should be ok
    {
        #ifdef INCREASING_QUERY
        while(Q.size()>1&&Q[0].intersect(Q[1]).first<x)
            Q.pop_front();
        return Q[0](x);
        #else
        while(Q.size()>1&&Q.back().intersect(Q[(int)Q.size()-2]).first>x)
            Q.pop_back();
        return Q.back()(x);
        #endif
    }
    ll query(ll x)
    {
        pii indx=bSearch(x);
        if(type<2)
            return min(Q[indx.first](x),Q[indx.second](x));
        return max(Q[indx.first](x),Q[indx.second](x));
    }
    void clear()
    {
        Q.clear();
    }
};

const int N = 200005;
ll dp[N];

int main(){
    MonotoneCHT cht(false,false);
    ll n,x;
    cin>>n>>x;
    ll skill[n],mons[n];
    for(int i=0;i<n;i++) cin>>mons[i];
    for(int i=0;i<n;i++) cin>>skill[i];
    cht.insert({x,0});
    for(int i=0;i<n;i++){
        dp[i] = x*mons[i];
        dp[i] = cht.query(mons[i]);
        cht.insert({skill[i],dp[i]});
       // cout<<dp[i]<<" ";
    }
    cout<<dp[n-1];
}
