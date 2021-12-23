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

const int N = 100005;
int previ[N+5],now[N+5];
int main(){
    int n;
    cin>>n;
    int coins[n];
    for(int i=0;i<n;i++)
        cin>>coins[i];
    previ[0] = 1;
    int cnt = 0;
    for(int k=0;k<n;k++){
        cnt = 0;
        for(int i=0;i<N;i++){
            if( previ[i] == 1 and i + coins[k]<N) now[i + coins[k] ] = 1;
            if( previ[i] ) now[i] = 1;
            previ[i] = now[i];
            cnt+=now[i];
        }
    }
    cout<<cnt-1<<endl;
    for(int i=1;i<N;i++)
        if( now[i] == 1 ) cout<<i<<" ";
}




