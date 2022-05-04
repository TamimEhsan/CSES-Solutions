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


struct point{
    ll x,y;
};

int main() {
    int n;
    cin>>n;
    point p[n];
    for(int i=0;i<n;i++)
        cin>>p[i].x>>p[i].y;

    ll res = 0;
    for(int i=0;i<n;i++){
        res+= p[i].x*p[ (i+1)%n ].y;
    }
    for(int i=0;i<n;i++){
        res-= p[i].y*p[ (i+1)%n ].x;
    }
    cout<<abs(res);

}


