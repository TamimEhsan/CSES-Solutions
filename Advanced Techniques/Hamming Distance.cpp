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


int main(){
    int n,k;
    cin>>n>>k;
    int ara[n];
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        int a=0;
        for(int j=0;j<k;j++)
            if( s[j] == '1' )
                a+= (1<<j);
        ara[i] = a;
    }
    int mn = k;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int r = (int)__builtin_popcount(ara[i]^ara[j]);
            mn = min(mn,r);
        }
    }
    cout<<mn;
}

