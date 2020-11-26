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
#define MOD 998244353

int main(){
    int n,w;
    cin>>n>>w;
    int weights[n];
    for(int i=0;i<n;i++){
        cin>>weights[i];
    }
    sort(weights,weights+n);
    int i =0,j=n-1,res = 0;
    while( i<=j ){
        if( i == j ){
            i++;
            res++;
        } else if( weights[i]+weights[j]<=w ){
            i++;
            j--;
            res++;
        } else{
            j--;
            res++;
        }
    }
    cout<<res;
}

