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

const int N = 1e6+5;
int change[N];
int main(){
    int n,x;
    cin>>n>>x;
    int coins[n];
    for(int i=0;i<n;i++) cin>>coins[i];
    change[0] = 1;
    for(int i=0;i<x;i++){
        for(int j=0;j<n;j++){
            if( change[i] == 0 ) continue;
            if( i + coins[j]<=x )
                if(change[i+coins[j]] == 0  )
                    change[i+coins[j]] = change[i] + 1;
                else
                    change[i+coins[j]] = min(change[i+coins[j]], change[i]+1 );
        }
    }
    if( change[x] == 0 ) cout<<-1;
    else cout<<change[x]-1;
}

