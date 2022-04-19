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

long long bigmod(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

int main(){
    //ifstream cin;
    //cin.open("input2.in");
    int n;
    cin>>n;
    pii para[n];
    for(int i=0;i<n;i++){
        cin>>para[i].F>>para[i].S;

    }
    ll number = 1,divCount = 1,divCount2 = 1,divSum = 1,divProd = 1;

    for(int i=0;i<n;i++){


        divCount = divCount*(para[i].S+1);
        divCount%=M;

        divProd = bigmod( divProd, para[i].S+1,M )* bigmod( bigmod( para[i].F, para[i].S*(para[i].S+1)/2,M ), divCount2,M );
        divProd%=M;

        divCount2 = divCount2*(para[i].S+1);
        divCount2%=(M-1);

        divSum = divSum * (bigmod( para[i].F,para[i].S+1,M)-1+M);
        divSum%=M;
        divSum = divSum*bigmod( para[i].F-1,M-2,M );
        divSum%=M;
    }

    cout<<divCount<<" "<<divSum<<" "<<divProd;
}
