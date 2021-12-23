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
ll broken[N],solid[N];
int main(){
    broken[1] = solid[1] = 1;
    for(int i=2;i<N;i++){
        solid[i] = solid[i-1]*2 + broken[i-1];
        broken[i] = solid[i-1] + 4*broken[i-1];
        solid[i]%=M;
        broken[i]%=M;
    }
    int tc;
    cin>>tc;
    while(tc--){
        int n;
        cin>>n;
        cout<<(solid[n]+broken[n])%M<<endl;
    }
}




