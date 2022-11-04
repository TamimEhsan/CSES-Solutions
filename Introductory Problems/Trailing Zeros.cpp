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
    int t = 1;
   // scanf("%d",&t);
    for(int tc=1;tc<=t;tc++){
        int n;
        cin>>n;
        ll mul = 5;
        int res = 0;
        while(mul<=n){
            res+=n/mul;
            mul*=5;
        }
        cout<<res;
    }
}
