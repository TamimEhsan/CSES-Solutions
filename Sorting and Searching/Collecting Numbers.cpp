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
    pii para[n];
    for(int i=0;i<n;i++){
        cin>>para[i].F;
        para[i].S = i;
    }
    sort(para,para+n);
    int times = 1;
    for(int i=1;i<n;i++){
        if( para[i].S<para[i-1].S ) times++;
    }
    cout<<times;
}
