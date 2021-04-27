#include<bits/stdc++.h>
using namespace std;
#define INF 2147483647
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

map<ll,int> m;
ll calcFib(ll n){
    if( n == -1 ) return 0;
    if( n == 0 ) return 1;
    if( n == 1 ) return 1;
    if( n == 2 ) return 2;
    ll a,b,c;
    if( n%2 == 0 ){
        m[n/2]!=0 ?  a = m[n/2]:m[n/2] = a = calcFib(n/2);
        m[n/2-1]!=0? b = m[n/2-1]: m[n/2-1] = b = calcFib(n/2-1);
        return ((a*a)%M+(b*b)%M)%M;
    }else{
        m[n/2+1]!=0?a = m[n/2+1]:m[n/2+1] = a = calcFib(n/2+1);
        m[n/2]!=0?b = m[n/2]:m[n/2] = b = calcFib(n/2);
        m[n/2-1]!=0?c = m[n/2-1]:m[n/2-1] = c = calcFib(n/2-1);
        return ((a*b)%M+(b*c)%M)%M;
    }
}

int main(){
    ll n;
    cin>>n;
    cout<<calcFib(n-1);
}

/*
F(54774730983471038)%10e+7 = 795317107
*/
